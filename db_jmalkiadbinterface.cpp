#include "db_jmalkiadbinterface.h"

#include <QVariant>



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
