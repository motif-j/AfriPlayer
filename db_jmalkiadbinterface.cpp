#include "db_jmalkiadbinterface.h"

#include <QVariant>



QList<JTrack> *JMalkiaDbInterface::getTracks(const int lastId,const int limit)
{


    QList<JTrack> *tempList=new QList<JTrack>();

    QSqlQuery *query =new QSqlQuery(mDb);

    auto prepare= query->prepare("select * from tracks where track_id>? limit ?");

    query->addBindValue(lastId);
    query->addBindValue(limit);


    if(!prepare){

        return new QList<JTrack>();
    }

    auto querySuccess= query->exec();

    if(!querySuccess){
        return new QList<JTrack>();
    }

    while(query->next()){
        JTrack track;

        QVariant *idVariant=new QVariant(query->value(0));
        QVariant *trackNameVariant=new QVariant(query->value(1));
        QVariant *durationVariant=new QVariant(query->value(2));
        QVariant *artistIdNameVariant=new QVariant(query->value(3));
        QVariant *albumIdVariant=new QVariant(query->value(4));
        QVariant *fileUrlVariant=new QVariant(query->value(5));


        track.trackId=idVariant->toInt();
        track.trackName=trackNameVariant->toString();
        track.duration=durationVariant->toLongLong();
        track.artistId=artistIdNameVariant->toInt();
        track.albumId=albumIdVariant->toInt();
        track.fileUrl=fileUrlVariant->toString();


        tempList->append(track);


          //reclaim the memory held by the variants
         idVariant=nullptr;
         trackNameVariant=nullptr;
         durationVariant=nullptr;
         artistIdNameVariant=nullptr;
         albumIdVariant=nullptr;
         fileUrlVariant=nullptr;

         delete idVariant;
         delete trackNameVariant;
         delete durationVariant;
         delete artistIdNameVariant;
         delete albumIdVariant;
         delete fileUrlVariant;


    }




    return tempList;

}

void JMalkiaDbInterface::massInsert()
{

    qDebug("Mass insert");
    for(int i=21;i<10000;i++){
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
