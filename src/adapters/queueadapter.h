#ifndef QUEUEADAPTER_H
#define QUEUEADAPTER_H

#include <QAbstractListModel>
#include <QObject>
#include <src/adapters/tracksadpater.h>
#include <src/controllers/jplaylistcontroller.h>

class QueueAdapter : public AbstractTracksAdapter
{
    Q_OBJECT
    Q_PROPERTY(int playingIndex READ getPlayingIndex WRITE setPlayingIndex NOTIFY playingIndexChanged)


public:
    explicit QueueAdapter(QObject *parent = nullptr);

    int getPlayingIndex() const;
    void setPlayingIndex(int newPlayingIndex);

public slots:
    void test(){
        qDebug()<<"QUEUE ADAPTER";
    }

signals:
    void playingIndexChanged();

    //listeners
private slots:
    void onTrackInserted(JTrack ,int,int);
    void onTrackSelected(JTrack,int index,int lastIndex);

private:
    JPlaylistController &playlistController=JPlaylistController::getInstance();
    int playingIndex=-1;



};

#endif // QUEUEADAPTER_H
