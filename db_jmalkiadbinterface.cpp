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
    QString query="SELECT track_id,track_name,artist_name,album_name,duration,file_url FROM tracks t LEFT Join albums a on a.album_id=t.album_id LEFT JOIN artists art on art.artist_id=t.artist_id where track_id=?";

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

    auto prepare =sqlQuery->prepare("select * from playlists limit ?");
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
            if(i<=5){

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

void JMalkiaDbInterface::massInsert()
{

    qDebug("Mass insert");
    for(int i=0;i<100;i++){
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
