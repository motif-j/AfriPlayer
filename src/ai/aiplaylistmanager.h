#ifndef AIPLAYLISTMANAGER_H
#define AIPLAYLISTMANAGER_H

#include <QFuture>
#include <QFutureWatcherBase>
#include <QObject>
#include <QThreadPool>
#include <QtConcurrent>
#include <src/database/db_jmalkiadbinterface.h>
#include <src/workers/mainworker.h>

class AiPlaylistManager : public QObject
{
    Q_OBJECT
public:
    static AiPlaylistManager &getInstance(){
        static AiPlaylistManager instance;

        return instance;
    }
private:
    explicit AiPlaylistManager(QObject *parent = nullptr);

public:
    QFuture<QList<JTrack>> getAiTracks(int playlistId);

    QFuture<JTrack> incrementPlayCount(int trackId);
private:
    QThreadPool *pool;
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();
    MainWorker &mWorker=MainWorker::getInstance();

signals:

};




#endif // AIPLAYLISTMANAGER_H
