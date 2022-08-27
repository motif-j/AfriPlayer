#include "queueadapter.h"

QueueAdapter::QueueAdapter(QObject *parent)
    : AbstractTracksAdapter(parent)
{

    foreach(JTrack track,*playlistController.getPlaylist()){
        tracks.append(track);
    }

    connect(&playlistController,&JPlaylistController::notifyTrackInserted,this,&QueueAdapter::onTrackInserted);
    connect(&playlistController,&JPlaylistController::notifyTrackSelected,this,&QueueAdapter::onTrackSelected);
}

void QueueAdapter::onTrackInserted(JTrack track, int index,int lastIndex)
{
    qDebug()<<"COUNT "<<getCount();

    if(index==-1){

        add(track,tracks.count());

        return;
    }

    if(!tracks.isEmpty()){

        qDebug()<<"LAST INDEX "<<lastIndex;
        auto track=tracks.at(lastIndex);
        track.isPlaying=false;

        tracks.replace(lastIndex,track);

        QModelIndex topLeft=createIndex(lastIndex,0);
        QModelIndex bottomLeft=createIndex(lastIndex,0);

        emit dataChanged(topLeft,bottomLeft);

    }

    this->add(track,index);
    setPlayingIndex(index);


    qDebug()<<"Track "<< track.trackName<<" Inserted at "<<index;
}

void QueueAdapter::onTrackSelected(JTrack track, int index, int lastIndex)
{

    auto lastTrack=tracks.value(lastIndex);
    lastTrack.isPlaying=false;
    update(lastTrack,lastIndex);

    update(track,index);

}

int QueueAdapter::getPlayingIndex() const
{
    return playingIndex;
}

void QueueAdapter::setPlayingIndex(int newPlayingIndex)
{
    if (playingIndex == newPlayingIndex)
        return;
    playingIndex = newPlayingIndex;
    emit playingIndexChanged();
}
