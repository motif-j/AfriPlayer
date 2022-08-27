#include "maincontroller.h"

MainController::MainController(QObject *parent)
    : QObject{parent}
{
    setShuffle(settings.getShuffle());
    setIsQuering(settings.getIsQuering());

    if(isQuering){
        setIsQuering(false);
        settings.setIsQuering(false);
        queryAudioFiles();
    }

    //toggleShuffle();

}

void MainController::loadTrackToEngine(int trackId)
{

    await(worker.getTrack(trackId),this,[this](JTrack track){
        setPlayingTrackId(track.trackId);
        //play the track
        //  engine->loadAudio(track.fileUrl);
        //  engine->play();


        //update the playing queue
        playlistController.loadPlayingTrackToQueuePlaylist(track);

    });

}

void MainController::addTrackToPlayingQue(int trackId)
{
    await(worker.getTrack(trackId),this,[this](JTrack track){
        setPlayingTrackId(track.trackId);

        playlistController.addTrackToQueue(track,true);

    });
}

void MainController::addPlaylistToQueue(int playlistId)
{
    playlistController.addPlaylistToQueue(playlistId,false);


}

void MainController::addTrackToPlaylist(int trackId, int playlistId)
{
    playlistController.addTrackToPlaylist(trackId,playlistId);


}



void MainController::toggleShuffle()
{
    bool shuffle=settings.getShuffle();

    setShuffle(!shuffle);

}

void MainController::queryAudioFiles()
{
    if(!settings.getIsQuering()){
        settings.setIsQuering(true);
        setIsQuering(true);
        await(fileWorker.queryAllFiles(),this,[this](int res){

            settings.setIsQuering(false);
            setIsQuering(false);
            qDebug()<<"Done quering audio files "<<res;
        });
    }

}

void MainController::playNext()
{
    auto nextTrack=playlistController.getNextTrack();

    if(nextTrack.trackId==-1){
        return;
    }

    //play the track

    //update ui
    playlistController.loadPlayingTrackToQueuePlaylist(nextTrack);


}

void MainController::playPrevious()
{
    auto previousTrack=playlistController.getPreviousTrack();

    if(previousTrack.trackId==-1){
        return;
    }

    //play the track

    //update ui
    playlistController.loadPlayingTrackToQueuePlaylist(previousTrack);

}

bool MainController::getIsQuering() const
{
    return isQuering;
}

void MainController::setIsQuering(bool newIsQuering)
{
    if (isQuering == newIsQuering)
        return;
    isQuering = newIsQuering;
    emit isQueringChanged();
}

bool MainController::getShuffle() const
{
    return shuffle;
}

void MainController::setShuffle(bool newShuffle)
{
    if (shuffle == newShuffle)
        return;
    shuffle = newShuffle;
    settings.setShuffle(shuffle);

    emit shuffleChanged();
}



int MainController::getPlayingTrackId() const
{
    return playingTrackId;
}

void MainController::setPlayingTrackId(int newPlayingTrackId)
{
    if (playingTrackId == newPlayingTrackId)
        return;
    playingTrackId = newPlayingTrackId;
    emit playingTrackIdChanged();
}
