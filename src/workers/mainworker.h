#ifndef MAINWORKER_H
#define MAINWORKER_H

#include <QObject>
#include <QDebug>
#include <QtConcurrent>
#include <QThreadPool>
#include <QFuture>
#include <QList>
#include <QTime>

#include "src/database/db_jmalkiadbinterface.h"
#include "src/models/jmodels.h"
#include "src/database/db_jmalkiadbinterface.h"

/*
 *This class implements the heavy tasks for the list adapters
 */

extern QString formatTrackTime(QTime time);

class MainWorker : public QObject
{
    Q_OBJECT
private:
    MainWorker(QObject *parent=nullptr){

        Q_UNUSED(parent)
        threadPool=new QThreadPool();
        threadPool->setMaxThreadCount(1);

    }




public:
    static MainWorker &getInstance(){
        static MainWorker instance;

        return instance;
    }
public:
    QThreadPool *getPool(){
        return threadPool;
    }

    //Functions
public:

    QFuture<QList<JTrack>> getPlaylistTracks(int playlistId,int refreshCode);
    QFuture<JTrack> getTrack(int trackId);

    QFuture<QList<JTrack>> queuePlaylistTrack(int playlistId,bool append);
    QFuture<QList<JTrack>> queuePlaylistTrack(QList<JTrack> tracks,bool append);
    QFuture<QList<JTrack>> getQueuedPlaylist();
    QFuture<QList<JTrack>> getTracks(int lastId);

    QFuture<int> toggleQueuedTrackAsPlayed(int trackId);
    QFuture<JTrack> addTrackToPlaylist(int trackId,int playlistId);
    QFuture<JTrack> removeTrackFromPlaylist(int trackId,int playlistId);

    QFuture<JTrack> addTrackToQueue(int trackId);
    QFuture<JTrack> updateTrackDuration(JTrack track);

    QFuture<QString> calculateTotalTrackTime(QList<JTrack> tracks);

    //folders
public:
    QFuture<QStringList> loadFolders();
    QFuture<QStringList> addFolderToLib(QString folder);
    QFuture<QStringList> deleteFolderFromLib(QString folder);


    //Search
   QFuture<QList<JTrack>> searchForTracksByQuery(QString query);


   //playlist

   QFuture<QList<JPlaylist>> getPlaylists(bool isHome,bool folders=false);
   QFuture<QList<JPlaylist>> getAiPlaylist();
   QFuture<JPlaylist> addPlaylist(JPlaylist playlist);
   QFuture<JPlaylist> getPlaylist(int playlistId);
   QFuture<JPlaylist> updatePlaylist(int playlistId,QString title);
   QFuture<int> deletePlaylist(int playlistId);

private:
    QThreadPool *threadPool;
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();


};

template<typename T, typename  Handler>
inline void await(const QFuture<T> &future, QObject *context,Handler handler){

    auto watcher=new QFutureWatcher<T>(context);
    QObject::connect(watcher,&QFutureWatcherBase::finished,
                     context,[watcher,handler{std::move(handler)}](){
        handler(watcher->result());
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

#endif // MAINWORKER_H
