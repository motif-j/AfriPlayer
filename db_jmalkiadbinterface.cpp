#include "db_jmalkiadbinterface.h"

#include <QVariant>
#include <QSet>
#include <QSetIterator>


QList<JTrack> *JMalkiaDbInterface::getTracks(const int lastId,const int limit)
{


    QList<JTrack> *tempList=new QList<JTrack>();

    QSqlQuery *query =new QSqlQuery(mDb);

    auto prepare= query->prepare("SELECT track_id,track_name,artist_name,album_name,duration,file_url FROM tracks t LEFT Join albums a on a.album_id=t.album_id LEFT JOIN artists art on art.artist_id=t.artist_id where track_id>? limit ?");

    query->addBindValue(lastId);
    query->addBindValue(limit);


    if(!prepare){
        qDebug()<<"Not prepared "<<query->lastError().text();

        return new QList<JTrack>();
    }

    auto querySuccess= query->exec();

    if(!querySuccess){
        qDebug()<<"Query failed "<<query->lastError().text();
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



        track.trackId=idVariant->toInt();
        track.trackName=trackNameVariant->toString();
        track.duration=durationVariant->toLongLong();
        track.artistName=artistNameVariant->toString();
        track.albumName=albumNameVariant->toString();
        track.fileUrl=fileUrlVariant->toString();
        track.isFavorite=isTrackFavorite(track.trackId);


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


    }




    return tempList;

}

JTrack *JMalkiaDbInterface::getTrack(int trackId)
{
    QString query="SELECT track_id,track_name,artist_name,album_name,duration,file_url  FROM tracks t LEFT Join albums a on a.album_id=t.album_id LEFT JOIN artists art on art.artist_id=t.artist_id where track_id=?";

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

                sqlQuery=nullptr;
                delete sqlQuery;


                return track;
            }

        }


    }

    qDebug()<<"Failed to perform db operation "<<sqlQuery->lastError().text();
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
    qDebug()<<"Sql error: "<<sqlQuery->lastError().text();

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




    delete sqlQuery;

    return tracks;
}

QList<JTrack> *JMalkiaDbInterface::fetchPlaylistTracksFromRepo(int playlistId)
{
    QString query="SELECT pT.track_id, t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url FROM playlist_tracks pT INNER JOIN tracks t ON t.track_id=pT.track_id LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id WHERE pT.pl_id=? ORDER BY pT.id DESC ";


    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    auto tracks=new QList<JTrack>();

    auto isQueryPrepared=sqlQuery->prepare(query);

    sqlQuery->addBindValue(playlistId);

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



                tracks->append(*track);
            }

        }

    }

    qDebug()<<"SQL ERROR "<<sqlQuery->lastError().text();
    sqlQuery=nullptr;
    delete sqlQuery;

    return tracks;
}

QList<JTrack> *JMalkiaDbInterface::fetchRecentlyPlayedTracks()
{
    QString query="SELECT pT.track_id, t.track_name,a.artist_name,ab.album_name, t.duration, t.file_url , pT.rec_id FROM recently_played pT INNER JOIN tracks t ON t.track_id=pT.track_id LEFT JOIN artists a on t.artist_id=a.artist_id LEFT JOIN albums ab on ab.album_id=t.album_id  ORDER BY pT.rec_id  DESC LIMIT 5";


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



                tracks->append(*track);
            }

        }

    }

    qDebug()<<"SQL ERROR "<<sqlQuery->lastError().text();
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

    qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
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
    printError(sqlQuery);

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
    qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
    delete sqlQuery;
}

void JMalkiaDbInterface::addTrackToRecentlyPlayed(int trackId)
{
    QString  query="INSERT INTO recently_played ('track_id') VALUES ( ?) ";

    QSqlQuery *sqlQuery=new QSqlQuery(mDb);

    auto track=getTrack(trackId);
    if(track->trackId==trackId){
        sqlQuery->prepare("DELETE from recently_played where track_id = ?");
        sqlQuery->addBindValue(trackId);

        sqlQuery->exec();
    }

    if(sqlQuery->prepare(query)){
        sqlQuery->addBindValue(trackId);


        if(sqlQuery->exec()){

            delete sqlQuery;
            return;
        }
    }

    qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
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



void JMalkiaDbInterface::intializeDatabase()
{

    auto isDriverAvailable=QSqlDatabase::isDriverAvailable(DRIVER_NAME);

    if(isDriverAvailable){

        mDb=QSqlDatabase::addDatabase(DRIVER_NAME);

        mDb.setDatabaseName("C:\\Users\\user\\Desktop\\malkia.db");

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
            qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
        }
    }else{
        qDebug()<<" SQL ERROR "<<sqlQuery->lastError().text();
    }


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
    printError(sqlQuery);
    delete sqlQuery;
}

