#ifndef JMALKIADBINTERFACE_H
#define JMALKIADBINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QList>
#include <QSqlQuery>
#include "../models/jmodels.h"
#include <QDebug>
#include <QVariant>
#include <QThread>
#include <QRandomGenerator>
#include <QtConcurrent>
#include <QFuture>
#include <QThreadPool>
#include <QMediaMetaData>
#include <src/utils/jsettings.h>
#include <src/graphics/colorgenerator.h>


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
    JTrack updateTrackDuration(JTrack track);

    JTrack getLastTrack();

    QList<JPlaylist> *fetchPlaylistsFromRepository(int limit,bool isHome=false,bool folders=false);
    QList<JPlaylist> *fetchAiPlaylistsFromRepo();

    JPlaylist getLastPlaylist();
    JPlaylist getPlaylist(int playlistId);
    JPlaylist updatePlaylist(JPlaylist playlist);
    void removePlaylist(int playlistId);

    QList<JTrack> *randomizedPlaylist();
    QList<JTrack> *fetchPlaylistTracksFromRepo(int playlistId);
    QList<JTrack> *fetchRecentlyPlayedTracks();

    int generateLimit(int maxTrackId);
    void addTrackToPlaylist(JTrack track,int playlistId);
    void addTrackToFolderPlaylist(JTrack track,int playlistId); //delete
    void deleteTrackFromPlaylist(JTrack track,int playlistId);
    void clearPlaylist(int playlistId);
    void addTrackToRecentlyPlayed(int trackId);

    void toggleFavoriteInTrack(int trackId);

    //Queue list impl
    void queueTrack(int trackId); //does not require a signal
    void clearQueue();
    void toggleQueuedTrackPlayed(int trackId);//done
    void queuePlaylist(QList<JTrack> tracks);

    //will be updated dynamically
    QList<JTrack> *fetchNext10QueuedTracks();

    void removeTrackFromPlaylist(int trackId,int playlistId);

    void addFolderToLibs(QString path);
    void removeFolder(QString path);
    QStringList getFolders();
    void deleteLibTracks(QString pattern);

    void massInsert();

    void addNewTrack(JTrack track);
    void updateTrack(JTrack track);

    int addNewArtist(QString artistName);
    int albumId(QString albumName);

    QFuture<JTrack> getTrackFuture();

    //Search
    QList<JTrack> searchTrackByQuery(QString query);


    void addNewPlaylist(JPlaylist playlist);
    void addNewFolderPlaylist(JPlaylist playlist);

    //AI based playlist
    QList<JTrack> getMostPlayedTracks();
    QList<JTrack> getLeastPlayedTracks();
    QList<JTrack> getNewestTracks();
    QList<JTrack> getOldestTracks();
    //constructor

private:
    JMalkiaDbInterface(QObject *parent = nullptr){
        Q_UNUSED(parent);

        m_pool.setMaxThreadCount(1);
        m_pool.setExpiryTimeout(-1);

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
    QThreadPool m_pool;
    int lastQueuedId=0;
    JSettings &settings=JSettings::getInstance();
    ColorGenerator &colorGen=ColorGenerator::getInstance();

    QRandomGenerator randomGen=QRandomGenerator::securelySeeded();


    //functions
private:
    void intializeDatabase();
    bool isTrackFavorite(int trackId);
    bool isLocked=false;



signals:

};

#endif // JMALKIADBINTERFACE_H
