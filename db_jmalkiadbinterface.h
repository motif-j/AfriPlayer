#ifndef JMALKIADBINTERFACE_H
#define JMALKIADBINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QList>
#include <QSqlQuery>
#include "jmodels.h"
#include <QDebug>
#include <QVariant>
#include <QThread>
#include <QRandomGenerator>



//  Q_DECLARE_METATYPE(JTrack);

class JMalkiaDbInterface : public QObject
{
    Q_OBJECT

    //constructor
public:
    static JMalkiaDbInterface &getInstace(){
        static JMalkiaDbInterface instance;

        return instance;

    }

    //functions
public:
    QList<JTrack> *getTracks(const int lastId,const int limit);
    JTrack *getTrack(int trackId);
    QList<JPlaylist> *fetchPlaylistsFromRepository(int limit);

    QList<JTrack> *randomizedPlaylist();

    void massInsert();


    //constrctor


private:
    JMalkiaDbInterface(QObject *parent = nullptr){
        Q_UNUSED(parent);

        this->intializeDatabase();
    }

    //properties
private:

    const QString DRIVER_NAME=QString("QSQLITE");

    QSqlDatabase mDb;


    //functions
private:
    void intializeDatabase();

signals:

};

#endif // JMALKIADBINTERFACE_H
