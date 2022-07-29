#include "db_jmalkiadbinterface.h"
#include <QDebug>



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
