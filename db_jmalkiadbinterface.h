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

#include <QMediaMetaData>

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
    enum PLAYLISTIDS{
        ID_FAV=1,
        ID_MOSTPLAYED=2,
        ID_LEASTPLAYED=3,
        ID_NEWEST=4,
        ID_RAND=5,
        ID_SONGSYOUMAYKNOW=6,
        ID_DAILYMIX=7
    };

    //functions
public:
    QList<JTrack> *getTracks(const int lastId,const int limit);
    JTrack *getTrack(int trackId);
    QList<JPlaylist> *fetchPlaylistsFromRepository(int limit);

    QList<JTrack> *randomizedPlaylist();
    QList<JTrack> *fetchPlaylistTracksFromRepo(int playlistId);
    QList<JTrack> *fetchRecentlyPlayedTracks();

    int generateLimit(int maxTrackId);
    void addTrackToPlaylist(JTrack track,int playlistId);
    void clearPlaylist(int playlistId);
    void addTrackToRecentlyPlayed(int trackId);

    void toggleFavoriteInTrack(int trackId);

    //Queue list impl
    void queueTrack(int trackId); //does not require a signal
    void clearQueue();
    void toggleQueuedTrackPlayed(int trackId);//done
    void queuePlaylist(QList<JTrack> tracks);

    //will be updated dynamically
    QList<JTrack> *fetchNext10QueuedTracks(bool shuffle);

    void removeTrackFromPlaylist(int trackId,int playlistId);

    void massInsert();
    void addNewTrack(JTrack track);
    int addNewArtist(QString artistName);
    int albumId(QString albumName);

    //constrctor


private:
    JMalkiaDbInterface(QObject *parent = nullptr){
        Q_UNUSED(parent);

        this->intializeDatabase();
    }

    void printError(QString tag,QSqlQuery *query){

        QString error=query->lastError().text();

        if(!error.isEmpty()){
            qDebug()<<"SQL ERROR "<<tag<<" : "<<error;
        }
    }

    //properties
private:

    const QString DRIVER_NAME=QString("QSQLITE");

    QSqlDatabase mDb;


    //functions
private:
    void intializeDatabase();
    bool isTrackFavorite(int trackId);



signals:

};

#endif // JMALKIADBINTERFACE_H
