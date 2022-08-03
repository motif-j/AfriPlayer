#ifndef JMUSICCONTROLLER_H
#define JMUSICCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QString>
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
        JMusicControllerWorker *worker=new JMusicControllerWorker;

        worker->moveToThread(&controllerThread);
        connect(&controllerThread,&QThread::finished,worker,&QObject::deleteLater);
        connect(this,&JMusicController::fetchTrackFromRepository,worker,&JMusicControllerWorker::getTrack);
        connect(this,&JMusicController::fetchTracksFromRepository,worker,&JMusicControllerWorker::fetchTracksFromRepository);

        connect(worker,&JMusicControllerWorker::trackFetched,this,&JMusicController::handleFetchTrack);
        connect(worker,&JMusicControllerWorker::tracksFetchedFromRepository,this,&JMusicController::handleTracksFromRepository);

        connect(this,&JMusicController::fetchHomePlaylistFromRepository,worker,&JMusicControllerWorker::fetchHomePlaylistFromRepo);
        connect(worker,&JMusicControllerWorker::homePlaylistFetchedFromRepository,this,&JMusicController::handleHomePlaylistsFetchedFromRepository);

        connect(this,&JMusicController::fetchPlaylistTracksFromRepo,worker,&JMusicControllerWorker::fetchPlaylistTracksFromRepo);
        controllerThread.start();


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


    //slots called from qml interface
public slots:
    void getTrack(int trackId);
    void loadTracks(int lastId,int limit);
    void loadHomePlaylist();
    void loadPlaylistTrack(int playlistId);


    //slots that interact with the worker
public slots:
    void handleFetchTrack(JTrack trackResult);

    void handleTracksFromRepository(QList<JTrack>*);
    void handleHomePlaylistsFetchedFromRepository(QList<JPlaylist> *result);


    //signals that interact with the worker
signals:

    void fetchTrackFromRepository(int trackId);
    void fetchTracksFromRepository(int lastId,int limit);
    void fetchHomePlaylistFromRepository();
    void fetchPlaylistTracksFromRepo(int playlistId);


    //signals received in qml interface
signals:
    void trackFetched(QVariantMap jsonTrack);

    void tracksLoaded(QList<JTrack>*);
    void homePlaylistFetched(QList<JPlaylist>*);
 //   void playlistTracksFetched(QList<JTrack>*);

};

#endif // JMUSICCONTROLLER_H
