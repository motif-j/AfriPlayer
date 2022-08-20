#include "../database/db_jmalkiadbinterface.h"

#include <QVariant>
#include <QSet>
#include <QSetIterator>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QUrl>
#include <QSettings>
#include <QColor>


QList<JTrack> *JMalkiaDbInterface::getTracks(const int lastId,const int limit)
{


    QList<JTrack> *tempList=new QList<JTrack>();

    QSqlQuery *query =new QSqlQuery(mDb);

    auto prepare= query->prepare("SELECT track_id,track_name,artist_name,album_name,duration,file_url,colors FROM tracks t LEFT Join albums a on a.album_id=t.album_id LEFT JOIN artists art on art.artist_id=t.artist_id where track_id>? limit ?");

    query->addBindValue(lastId);
    query->addBindValue(limit);


    if(!prepare){
        qDebug()<<"Not prepared "<<query->lastError().text();

        return new QList<JTrack>();
    }

    auto querySuccess= query->exec();

    if(!querySuccess){
        printError("Get Tracks",query);
        // qDebug()<<"Query failed "<<query->lastError().text();
        return new QList<JTrack>();
    }

    while(query->next()){
        JTrack track;

        QVariant *idVariant=new QVariant(query->value(0));
        QVariant *trackNameVariant=new QVariant(query->value(1));
        QVariant *artistNameVariant=new QVariant(query->value(2));
        QVariant *albumNameVariant=new QVariant(query->value(3));
        QVariant *durationVariant=new QVariant(query->value(4));


        QVariant *fileUrlVariant=new QVariant(query->value(5));
        QVariant *colorsVariant=new QVariant(query->value(6));



        track.trackId=idVariant->toInt();
        track.trackName=trackNameVariant->toString();
        track.duration=durationVariant->toLongLong();
        track.artistName=artistNameVariant->toString();
        track.albumName=albumNameVariant->toString();
        track.fileUrl=fileUrlVariant->toString();
        track.isFavorite=isTrackFavorite(track.trackId);
        track.colors=colorsVariant->toString();



        tempList->append(track);


        //reclaim the memory held by the variants
        idVariant=nullptr;
        trackNameVariant=nullptr;
        durationVariant=nullptr;
        artistNameVariant=nullptr;
        albumNameVariant=nullptr;
        fileUrlVariant=nullptr;

        delete idVariant;
        delete trackNameVariant;
        delete durationVariant;
        delete artistNameVariant;
        delete albumNameVariant;
        delete fileUrlVariant;
        delete colorsVariant;


    }




    return tempList;

}

JTrack *JMalkiaDbInterface::getTrack(int trackId)
{
    QString query="SELECT track_id,track_name,artist_name,album_name,duration,file_url,colors  FROM tracks t LEFT Join albums a on a.album_id=t.album_id LEFT JOIN artists art on art.artist_id=t.artist_id where track_id=?";

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);


    auto isQueryPrepared=sqlQuery->prepare(query);

    sqlQuery->addBindValue(trackId);

    if(isQueryPrepared){
        auto isExecuted=sqlQuery->exec();

        if(isExecuted){

            if(sqlQuery->first()){
                JTrack *track=new JTrack;

                track->trackId=sqlQuery->value(0).toInt();
                track->trackName=sqlQuery->value(1).toString();
                track->artistName=sqlQuery->value(2).toString();
                track->albumName=sqlQuery->value(3).toString();
                track->duration=sqlQuery->value(4).toLongLong();
                track->fileUrl=sqlQuery->value(5).toString();
                track->isFavorite=isTrackFavorite(track->trackId);
                track->colors=sqlQuery->value(6).toString();

                sqlQuery=nullptr;
                delete sqlQuery;


                return track;
            }

        }


    }

    printError("Get single track ",sqlQuery);
    sqlQuery=nullptr;
    delete sqlQuery;

    return new JTrack;

}

QList<JPlaylist> *JMalkiaDbInterface::fetchPlaylistsFromRepository(int limit)
{

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);
    QList<JPlaylist> *tempList=new QList<JPlaylist>();

    auto prepare =sqlQuery->prepare("select * from playlists where pl_id NOT IN (1,2,3,4 ) limit ?");
    if(prepare){

        sqlQuery->addBindValue(limit);
        auto executed=sqlQuery->exec();

        if(executed){
            while(sqlQuery->next()){

                JPlaylist playlistItem;

                playlistItem.playlistId=sqlQuery->value(0).toInt();
                playlistItem.playlistTitle=sqlQuery->value(1).toString();
                playlistItem.colors=sqlQuery->value(2).toString();

                tempList->append(playlistItem);
            }
            sqlQuery=nullptr;
            delete sqlQuery;

            return tempList;
        }

    }
    printError("Get playlists ",sqlQuery);

    sqlQuery=nullptr;
    delete sqlQuery;
    return tempList;

}

QList<JTrack> *JMalkiaDbInterface::randomizedPlaylist()
{
    int startId=0;
    int endId=0;
    int totalTracks=0;

    bool isSuccess=false;
    //get the first track id
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    QList<JTrack> *tracks=new QList<JTrack>();


    auto firstItemQuery="select track_id from tracks limit 1";
    auto lastItemQuery="SELECT track_id FROM tracks ORDER BY track_id DESC  LIMIT 1";
    auto totalTracksQuery="SELECT seq from sqlite_sequence where name = 'tracks' ";

    if(sqlQuery->exec(firstItemQuery)){

        if(sqlQuery->first()){
            startId=sqlQuery->value(0).toInt();
            sqlQuery->finish();
            isSuccess=true;
        }

        if(sqlQuery->exec(lastItemQuery)){

            if(sqlQuery->first()){
                endId=sqlQuery->value(0).toInt();
                sqlQuery->finish();
                isSuccess=true;
            }


        }
        if(sqlQuery->exec(totalTracksQuery)){

            if(sqlQuery->first()){
                totalTracks=sqlQuery->value(0).toInt();
                sqlQuery->finish();
                isSuccess=true;
            }


        }
    }

    if(isSuccess){

        //from here generate a

        for(int i=1;i<=totalTracks;i++){
            //generate a random Id for every entry
            if(i<=50){

                if(endId>0){
                    int randId=QRandomGenerator::global()->bounded(startId,endId);
                    auto track=this->getTrack(randId);

                    auto isDup=tracks->contains(*track);

                    if(!isDup){
                        tracks->append(*track);
                    }else{
                        qDebug()<<"Duplicate spotted";
                    }
                }



            }

        }
    }



    printError("Randomize Playlist ",sqlQuery);

    delete sqlQuery;

    return tracks;
}

QList<JTrack> *JMalkiaDbInterface::fetchPlaylistTracksFromRepo(int playlistId)
{
    QString query="SELECT pT.track_id, t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url,t.colors FROM playlist_tracks pT INNER JOIN tracks t ON t.track_id=pT.track_id LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id WHERE pT.pl_id=? ORDER BY pT.id DESC ";


    if(playlistId==-1){
        query="SELECT t.track_id, t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url ,t.colors FROM tracks t LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id ORDER BY t.track_id DESC ";

    }

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    auto tracks=new QList<JTrack>();

    auto isQueryPrepared=sqlQuery->prepare(query);

    if(playlistId!=-1){
        sqlQuery->addBindValue(playlistId);
    }


    if(isQueryPrepared){
        auto isExecuted=sqlQuery->exec();

        if(isExecuted){

            while(sqlQuery->next()){
                JTrack *track=new JTrack;

                track->trackId=sqlQuery->value(0).toInt();
                track->trackName=sqlQuery->value(1).toString();
                track->artistName=sqlQuery->value(2).toString();
                track->albumName=sqlQuery->value(3).toString();
                track->duration=sqlQuery->value(4).toLongLong();
                track->fileUrl=sqlQuery->value(5).toString();
                track->isFavorite=isTrackFavorite(track->trackId);
                track->colors=sqlQuery->value(6).toString();



                tracks->append(*track);
            }

        }

    }

    printError("Get Playlist Tracks ",sqlQuery);
    sqlQuery=nullptr;
    delete sqlQuery;

    return tracks;
}

QList<JTrack> *JMalkiaDbInterface::fetchRecentlyPlayedTracks()
{
    QString query="SELECT pT.track_id, t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url ,t.colors , pT.rec_id FROM recently_played pT INNER JOIN tracks t ON t.track_id=pT.track_id LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id  ORDER BY pT.rec_id  DESC LIMIT 5";


    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    auto tracks=new QList<JTrack>();

    auto isQueryPrepared=sqlQuery->prepare(query);


    if(isQueryPrepared){
        auto isExecuted=sqlQuery->exec();

        if(isExecuted){

            while(sqlQuery->next()){
                JTrack *track=new JTrack;

                track->trackId=sqlQuery->value(0).toInt();
                track->trackName=sqlQuery->value(1).toString();
                track->artistName=sqlQuery->value(2).toString();
                track->albumName=sqlQuery->value(3).toString();
                track->duration=sqlQuery->value(4).toLongLong();
                track->fileUrl=sqlQuery->value(5).toString();
                track->isFavorite=isTrackFavorite(track->trackId);
                track->colors=sqlQuery->value(6).toString();



                tracks->append(*track);
            }

        }

    }

    printError("Get Recently Played ",sqlQuery);
    sqlQuery=nullptr;
    delete sqlQuery;

    return tracks;

}

int JMalkiaDbInterface::generateLimit(int maxTrackId)
{
    QString query= "SELECT COUNT(*) as 'Limit' FROM tracks WHERE track_id<=? ";
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    int limit=0;

    if(sqlQuery->prepare(query)){
        sqlQuery->addBindValue(maxTrackId);

        if(sqlQuery->exec()){

            if(sqlQuery->first()){
                limit= sqlQuery->value(0).toInt();

            }



        }
    }

    printError("Generate Limit ",sqlQuery);
    delete sqlQuery;

    return limit;

}

void JMalkiaDbInterface::addTrackToPlaylist(JTrack track,int playlistId)
{
    QString  query="INSERT INTO playlist_tracks ( 'pl_id', 'track_id') VALUES ( ?, ?) ";

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);



    if(sqlQuery->prepare(query)){
        sqlQuery->addBindValue(playlistId);
        sqlQuery->addBindValue(track.trackId);

        if(sqlQuery->exec()){

            delete sqlQuery;
            return;
        }else{

            removeTrackFromPlaylist(track.trackId,playlistId);
        }


    }
    printError("Add track to playlist",sqlQuery);

    delete sqlQuery;
}

void JMalkiaDbInterface::clearPlaylist(int playlistId)
{
    QString  query="DELETE FROM playlist_tracks WHERE pl_id=? ";

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    if(sqlQuery->prepare(query)){
        sqlQuery->addBindValue(playlistId);

        if(sqlQuery->exec()){
            delete sqlQuery;
            return;
        }
    }
    printError("Clear playlist ",sqlQuery);
    delete sqlQuery;
}

void JMalkiaDbInterface::addTrackToRecentlyPlayed(int trackId)
{
    QString  query="INSERT INTO recently_played ('track_id') VALUES ( ?) ";

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    // auto track=getTrack(trackId);
    // if(track->trackId==trackId){
    sqlQuery->prepare("DELETE from recently_played where track_id = ?");
    sqlQuery->addBindValue(trackId);

    sqlQuery->exec();
    // }

    if(sqlQuery->prepare(query)){
        sqlQuery->addBindValue(trackId);

        if(sqlQuery->exec()){

            delete sqlQuery;
            return;
        }
    }

    printError("Add Track to Recently Played",sqlQuery);
    delete sqlQuery;
}

void JMalkiaDbInterface::toggleFavoriteInTrack(int trackId)
{

    auto track=getTrack(trackId);

    if(track->isFavorite){

        //remove favorite
    }else{
        //change favorite
    }
}

void JMalkiaDbInterface::queueTrack(int trackId)
{
    QString  query="INSERT INTO playing_que ('track_id') VALUES ( ?) ";

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->prepare("SELECT track_id FROM playing_que WHERE track_id=? AND has_played =0 ");
    sqlQuery->addBindValue(trackId);

    sqlQuery->exec();

    if(sqlQuery->first()){
        toggleQueuedTrackPlayed(trackId);
    }else{

        //  auto track=getTrack(trackId);
        ///  if(track->trackId==trackId){
        // sqlQuery->prepare("DELETE from recently_played where track_id = ?");
        //   sqlQuery->addBindValue(trackId);
        //
        //    sqlQuery->exec();
        // }

        //sqlQuery->prepare("DELETE FROM playing_que WHERE track_id= ?" );
        sqlQuery->addBindValue(trackId);
        sqlQuery->exec();


        if(sqlQuery->prepare(query)){
            sqlQuery->addBindValue(trackId);


            if(sqlQuery->exec()){

                delete sqlQuery;
                return;
            }
        }

    }
    printError("Queue Track",sqlQuery);

    delete sqlQuery;
}

void JMalkiaDbInterface::clearQueue()
{
    QString  query="DELETE FROM playing_que ";
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->exec(query);


    printError("Clear Queue ",sqlQuery);

    delete sqlQuery;

}

void JMalkiaDbInterface::toggleQueuedTrackPlayed(int trackId)
{

    QString  query="UPDATE playing_que SET has_played=1  WHERE track_id=? ";
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->prepare(query);
    sqlQuery->addBindValue(trackId);

    sqlQuery->exec();
    printError("Toggle Queued Track ",sqlQuery);

    delete sqlQuery;

}

void JMalkiaDbInterface::queuePlaylist(QList<JTrack> tracks)
{
    QString  query="DELETE FROM playing_que  ";
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->exec();
    printError("Clear Queue ",sqlQuery);

    for(JTrack t :tracks){
        queueTrack(t.trackId);
    }

}

QList<JTrack> *JMalkiaDbInterface::fetchNext10QueuedTracks(bool shuffle)
{
    QSettings settings("AfrikTek","Qplayer");


    QString query="SELECT pT.track_id,t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url , pT.has_played,pT.que_id  FROM playing_que pT INNER JOIN tracks t ON t.track_id=pT.track_id LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id WHERE pT.has_played=0   LIMIT 10 ";

    if(shuffle){
        // qDebug()<<"SHUFFLE ON";
        query="SELECT pT.track_id,t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url , pT.has_played,pT.que_id  FROM playing_que pT INNER JOIN tracks t ON t.track_id=pT.track_id LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id where pT.has_played=0  ";

    }

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    auto tracks=new QList<JTrack>();

    auto isQueryPrepared=sqlQuery->prepare(query);

    if(!shuffle){
        //  sqlQuery->addBindValue(lastDbQueID);
    }

    QList<int> *queIds=new QList<int>();

    if(isQueryPrepared){
        auto isExecuted=sqlQuery->exec();

        if(isExecuted){

            while(sqlQuery->next()){
                JTrack *track=new JTrack;

                track->trackId=sqlQuery->value(0).toInt();
                track->trackName=sqlQuery->value(1).toString();
                track->artistName=sqlQuery->value(2).toString();
                track->albumName=sqlQuery->value(3).toString();
                track->duration=sqlQuery->value(4).toLongLong();
                track->fileUrl=sqlQuery->value(5).toString();
                track->isFavorite=isTrackFavorite(track->trackId);
                track->hasPlayed=(sqlQuery->value(6).toInt()==1);


                queIds->append(sqlQuery->value(7).toInt());

                tracks->append(*track);
            }

        }

    }


    if(!tracks->isEmpty()){
        if(shuffle){
            auto *nonRepTracks=new QList<JTrack>();

            int index=0;
            for(int i=0;i<10;i++){

                auto randomIndex= QRandomGenerator::global()->bounded(0,tracks->count());

                auto t=tracks->value(randomIndex);

                if(!nonRepTracks->contains(t)){
                    nonRepTracks->append(t);
                }
                index++;
            }

            //clear the list
            tracks->clear();

            foreach(JTrack t,*nonRepTracks){
                tracks->append(t);
            }
            //nonRepTracks->clear();

        }
    }


    printError("Fetch Next 10 Tracks in Queue ",sqlQuery);

    int lastId=0;
    if(!queIds->isEmpty()){
        lastId=queIds->last();
        settings.setValue("dbQueueId",lastId);
    }


    sqlQuery=nullptr;
    delete sqlQuery;


    return tracks;

}

void JMalkiaDbInterface::massInsert()
{

    qDebug("Mass insert");
    for(int i=0;i<500;i++){
        QSqlQuery *q=new QSqlQuery(mDb);
        auto prepare=  q->prepare("INSERT INTO tracks (track_name, duration, artist_id, album_id, file_url) VALUES (?, '121', '1', '1', ?)");

        if(prepare){
            qDebug("Prepared");

            q->addBindValue(QString("Inserted track ").append(QString::number(i)));
            q->addBindValue(QString("Url ").append(QString::number(i)));

            auto ex=q->exec();

            if(ex){

                qDebug()<<"Finish inserting "<<i;
            }else{
                auto lstError=q->lastError();
                qDebug()<<lstError.text();
                break;
            }

        }else{
            auto lstError=q->lastError();
            qDebug()<<lstError.text();

            break;
        }

        q->finish();
        q=nullptr;
        delete q;
    }
    qDebug("Mass insert Done");
}

void JMalkiaDbInterface::addNewTrack(JTrack track)
{
    QStringList *colors=new QStringList;

    for(int i=0;i<2;i++){
        int red=QRandomGenerator::global()->bounded(0,255);
        int green=QRandomGenerator::global()->bounded(0,255);
        int blue=QRandomGenerator::global()->bounded(0,255);

        QColor *color=new QColor(red,green,blue);
        colors->append(color->name(QColor::HexRgb));

        delete color;


    }



    QSqlQuery *q=new QSqlQuery(mDb);
    q->prepare("INSERT INTO tracks (track_name, duration, artist_id, album_id, file_url,colors,year,date_added) VALUES (?, ?, ?, ?, ?,?,?,?)");

    int artistId=addNewArtist(track.artistName);
    int album=albumId(track.albumName);



    q->addBindValue(track.trackName);
    q->addBindValue(track.duration);
    q->addBindValue(artistId);
    q->addBindValue(album);

    q->addBindValue(track.fileUrl);
    q->addBindValue(colors->value(0).append("-").append(colors->value(1)));
    q->addBindValue(track.releaseYear);
    q->addBindValue(track.dateAdded);


    q->exec();


    printError("Add New Track",q);
    q->finish();
    q=nullptr;
    delete q;
    delete colors;


}

void JMalkiaDbInterface::updateTrack(JTrack track)
{


}

int JMalkiaDbInterface::addNewArtist(QString artistName)
{
    QSqlQuery *q=new QSqlQuery(mDb);

    q->prepare("SELECT artist_id FROM artists WHERE artist_name =? ");
    q->addBindValue(artistName);

    q->exec();



    if(q->first()){

        printError("Add New Artist ",q);

        int id=q->value(0).toInt();
        delete  q;
        return id;
    }



    printError("Add New Artist ",q);


    q=new QSqlQuery(mDb);

    q->prepare("INSERT INTO artists (artist_name) VALUES (?) " );
    q->addBindValue(artistName);

    q->exec();

    q->finish();
    q->prepare("SELECT artist_id FROM artists WHERE artist_name = ?");
    q->addBindValue(artistName);

    q->exec();



    if(q->first()){
        printError("Add New Artist ",q);
        int id=q->value(0).toInt();
        delete  q;
        return id;
    }


    printError("Add New Artist ",q);


    delete q;

    return 0;
}

int JMalkiaDbInterface::albumId(QString albumName)
{
    QSqlQuery *q=new QSqlQuery(mDb);

    q->prepare("SELECT album_id FROM albums WHERE album_name = ?");
    q->addBindValue(albumName);

    q->exec();



    if(q->first()){
        printError("Add New Album SEL ",q);

        int id=q->value(0).toInt();
        delete  q;
        return id;
    }


    printError("Add New Album SEL ",q);
    q=new QSqlQuery(mDb);

    q->prepare("INSERT INTO albums (album_name) VALUES (?) " );
    q->addBindValue(albumName);

    q->exec();

    q->finish();
    printError("Add New Album INS ",q);

    q=new QSqlQuery(mDb);


    q->prepare("SELECT album_id FROM albums WHERE album_name = ?");
    q->addBindValue(albumName);

    q->exec();



    if(q->first()){
        printError("Add New Album SEL2 ",q);


        int id=q->value(0).toInt();
        delete  q;
        return id;
    }


    printError("Add New Album SEL2",q);
    delete  q;
    return 0;
}



void JMalkiaDbInterface::intializeDatabase()
{

    auto path=QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    QDir dir(path);
    if(!dir.exists("database")){
        if(dir.mkpath("database")){
            qDebug()<<" SUCCESS ";
        }
    }else{
        qDebug()<<"Folder already exists ";
    }

    //Lets check if the db file exists
    if(!dir.exists("database/malkia.db")){

        // on windows
#ifdef Q_OS_WIN32
        qDebug()<<"We are on windows";

        QUrl *url= new  QUrl("assets/malkia.db");

        qDebug()<<url->path();
        auto winPath=path;
        bool res= QFile::copy(url->path(),winPath.append("/database/malkia.db"));

        qDebug()<<"db result "<<res;

        delete url;


#endif

        //andoroid code
#ifdef Q_OS_ANDROID
        qDebug()<<"Android platform code";
        qDebug()<<"ANDROID PATH "<<path;

        QFile *dbFile=new QFile("assets:/assets/malkia.db");

        auto dPath=path;

        QFile *toBeWritten=new QFile(dPath.append("/database/malkia.db"));


        QFile::copy(dbFile->fileName(),toBeWritten->fileName());


        delete dbFile;
        delete toBeWritten;

#endif
    }


    auto isDriverAvailable=QSqlDatabase::isDriverAvailable(DRIVER_NAME);

    auto dbPth=path.append("/database/malkia.db");
    if(isDriverAvailable){

        mDb=QSqlDatabase::addDatabase(DRIVER_NAME);

        mDb.setDatabaseName(dbPth);

        //open the database

        auto open=mDb.open();

        if(open){
            qDebug()<<"Database connected successfully";


        }

    }else{
        qDebug("Failed to conenct to database");

    }

}

bool JMalkiaDbInterface::isTrackFavorite(int trackId)
{
    QString query= "SELECT COUNT(*) as 'isFavorite' FROM playlist_tracks WHERE track_id =? AND pl_id=1 ;";
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    int isFav=0;

    if(sqlQuery->prepare(query)){
        sqlQuery->addBindValue(trackId);

        if(sqlQuery->exec()){

            if(sqlQuery->first()){
                isFav= sqlQuery->value(0).toInt();

            }



        }else{
            // qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
        }
    }else{
        // qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
    }

    printError("Is Track Favorite ",sqlQuery);

    delete sqlQuery;

    return isFav>0;

}

void JMalkiaDbInterface::removeTrackFromPlaylist(int trackId,int playlistId)
{

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    if(sqlQuery->prepare("DELETE FROM playlist_tracks where track_id=? AND pl_id=?")){
        sqlQuery->addBindValue(trackId);
        sqlQuery->addBindValue(playlistId);

        if(sqlQuery->exec()){

            delete sqlQuery;
            return;
        }
    }
    printError("Remove Track From Playlist ",sqlQuery);
    delete sqlQuery;
}

void JMalkiaDbInterface::addFolderToLibs(QString path)
{
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->prepare("INSERT INTO music_libs (folder) VALUES (?) ");

    sqlQuery->addBindValue(path);

    sqlQuery->exec();

    printError("Add Folder ",sqlQuery);

    delete sqlQuery;

}

void JMalkiaDbInterface::removeFolder(QString path)
{
    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->prepare("DELETE FROM music_libs WHERE folder =? ");

    sqlQuery->addBindValue(path);

    sqlQuery->exec();

    printError("Remove Folder ",sqlQuery);

    delete sqlQuery;
}

QStringList JMalkiaDbInterface::getFolders()
{
    QStringList folders;

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->prepare("SELECT folder FROM music_libs ");

    sqlQuery->exec();

    while(sqlQuery->next()){

        folders.append(sqlQuery->value(0).toString());

    }

    printError("Get Folders ",sqlQuery);

    delete sqlQuery;

    return folders;
}

void JMalkiaDbInterface::deleteLibTracks(QString pattern)
{
    QStringList folders;

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    sqlQuery->prepare("DELETE FROM tracks WHERE file_url like ? ");
    QString pt="%";
    sqlQuery->addBindValue(pt.append(pattern).append("%"));


    sqlQuery->exec();


    printError("DELETE FOLDER TRACKS ",sqlQuery);

    delete sqlQuery;


}

