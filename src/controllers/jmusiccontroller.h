#ifndef JMUSICCONTROLLER_H
#define JMUSICCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QString>
#include <QSettings>
#include "jmusiccontrollerworker.h"


extern QString formatTrackTime(QTime);

class JMusicController : public QObject
{
    Q_OBJECT

    QThread controllerThread;

private:
    explicit JMusicController(QObject *parent = nullptr){
        Q_UNUSED(parent)

        qDebug()<<"INITIALIZING MAIN CONTROLELR";


          QSettings settings("AfrikTek","Qplayer");

          int playingId=settings.value("playingTrackId",0).toInt();




        worker->moveToThread(&controllerThread);
        connect(&controllerThread,&QThread::finished,worker,&QObject::deleteLater);
        connect(this,&JMusicController::fetchTrackFromRepository,worker,&JMusicControllerWorker::getTrack);
        connect(this,&JMusicController::fetchTracksFromRepository,worker,&JMusicControllerWorker::fetchTracksFromRepository);

        connect(worker,&JMusicControllerWorker::trackFetched,this,&JMusicController::handleFetchTrack);
        connect(worker,&JMusicControllerWorker::tracksFetchedFromRepository,this,&JMusicController::handleTracksFromRepository);

        connect(this,&JMusicController::fetchHomePlaylistFromRepository,worker,&JMusicControllerWorker::fetchHomePlaylistFromRepo);
        connect(worker,&JMusicControllerWorker::homePlaylistFetchedFromRepository,this,&JMusicController::handleHomePlaylistsFetchedFromRepository);

        connect(this,&JMusicController::fetchPlaylistTracksFromRepo,worker,&JMusicControllerWorker::fetchPlaylistTracksFromRepo);
        connect(worker,&JMusicControllerWorker::playlistTracksFetchedFromRepo,this,&JMusicController::handlePlaylistTracksFetchedFromRepo);


        connect(this,&JMusicController::fetchRecentlyPlayedTracks,worker,&JMusicControllerWorker::fetchRecentlyPlayedTracks);
        connect(worker,&JMusicControllerWorker::recentlyPlayedTracksFetched,this,&JMusicController::handleRecentlyPlayedTracksFetched);

        connect(this,&JMusicController::fetchPlayingTrackFromRepository,worker,&JMusicControllerWorker::getPlayingTrack);
        connect(worker,&JMusicControllerWorker::playingTrackFetched,this,&JMusicController::handlePlayingTrackFetched);


        connect(this,&JMusicController::addTrackToPlaylistSig,worker,&JMusicControllerWorker::addTrackToPlaylist);


        connect(this,&JMusicController::queueTrack,worker,&JMusicControllerWorker::queueTrack);

        connect(this,&JMusicController::queuePlaylistTracks,worker,&JMusicControllerWorker::queuePlaylistTracks);

        connect(this,&JMusicController::fetchPlayingQueue,worker,&JMusicControllerWorker::fetchPlayingQueue);
        connect(worker,&JMusicControllerWorker::queuedTracksFetched,this,&JMusicController::handleQueuedTracksFetched);


        connect(worker,&JMusicControllerWorker::trackQueued,this,&JMusicController::handleQueuedSoloTrackFetched);

        controllerThread.start();

        if(playingId!=0){
             getPlayingTrack(playingId);
        }


    }

    ~JMusicController(){
        controllerThread.quit();
        controllerThread.wait();

    }

public:
    static JMusicController &getInstance(){
        static JMusicController instance;

        return instance;

    }


    void addTrackToRecentsPlaylist(int trackId);
    void toggleQueuedTrack(int trackId);

    //slots called from qml interface which is the controller

public slots:
    int getActiveTrackId() const;
    void setActiveTrackId(int newActiveTrackId);
    void getTrack(int trackId);

    void getPlayingTrack(int trackId);

    void loadTracks(int lastId,int limit);
    void loadHomePlaylist();
    void loadPlaylistTrack(int playlistId,int refreshCode);
    void loadRecentlyPlayedTracks();

    void addTrackToPlaylist(int trackId,int playlistId);

    void addTrackToQueue(int trackId);
    void addPlaylistToQueue(int playlistId,bool append);
    void loadQueueList();

    //slots that interact with the worker
public slots:
    void handleFetchTrack(JTrack trackResult);
    void handlePlayingTrackFetched(JTrack track);

    void handleTracksFromRepository(QList<JTrack>*);
    void handlePlaylistTracksFetchedFromRepo(QList<JTrack>*);

    void handleHomePlaylistsFetchedFromRepository(QList<JPlaylist> *result);
    void handleRecentlyPlayedTracksFetched(QList<JTrack>*);


    void handleQueuedTracksFetched(QList<JTrack>* tracks);
    void handleQueuedSoloTrackFetched(JTrack track);

    //signals that interact with the worker
signals:

    void fetchTrackFromRepository(int trackId);
    void fetchPlayingTrackFromRepository(int trackId);
    void fetchTracksFromRepository(int lastId,int limit);
    void fetchHomePlaylistFromRepository();
    void fetchPlaylistTracksFromRepo(int playlistId,int refreshCode);
    void fetchRecentlyPlayedTracks();
    void addTrackToPlaylistSig(int trackId,int playlistId);

    void queueTrack(int trackId);
    void queuePlaylistTracks(int playlistId,bool append);
    void  fetchPlayingQueue();


    //signals received in qml interface which is the controller interface
signals:
    void trackFetched(QVariantMap jsonTrack);
    void playingTrackFetched(QVariantMap jsonTrack);

    void tracksLoaded(QList<JTrack>*);
    void playlistTracksLoaded(QList<JTrack>*);
    void recentlyPlayedTracksFetched(QList<JTrack>*);
    void homePlaylistFetched(QList<JPlaylist>*);

    void activeTrackIdChanged(int newTrackID);

    void queuedTracksFetched(QList<JTrack>*);

    void trackQueued(JTrack track);

    //   void playlistTracksFetched(QList<JTrack>*);
private:
    JMusicControllerWorker *worker=new JMusicControllerWorker;
    JMalkiaDbInterface &dbInterface=JMalkiaDbInterface::getInstace();
    int activeIndex;
    int activeTrackId=0;

    int playingIndex=0;
    int playingTrackId=0;
public:

    int getPlayingTrackId(){
        return playingTrackId;
    }
    JTrack getTrackSync(int trackId);
};

#endif // JMUSICCONTROLLER_H
