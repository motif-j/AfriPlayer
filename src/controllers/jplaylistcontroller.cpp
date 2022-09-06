#include "../controllers/jplaylistcontroller.h"
#include <QDebug>


QList<JTrack> *JPlaylistController::getPlaylist()
{
    return playlist;
}

void JPlaylistController::loadPlayingTrackToQueuePlaylist(JTrack track)
{
    int index=0;

    int previousPlayingId=settings.getPlayingTrackId();
    int  lastIndex=indexFromPlaylist(previousPlayingId);

    //check if the track is in the playlist

    if(playlist->isEmpty()){
        qDebug()<<"Playlist is empty";
        playlist->append(track);
        settings.setPlayingTrackId(track.trackId);

    }else{
        //get the previous playingId

        if(playlist->contains(track)){
            qDebug()<<"Playlist Contains track";

            index=playlist->indexOf(track);

            settings.setPlayingTrackId(track.trackId);

            track.isPlaying=true;

            setPlayingIndex(index);

            playFromUrl(track);

            int diff=playlist->count()-index;

            if(diff<5){
                dynamicLoadQueueTracks();
            }

            emit notifyTrackSelected(track,index,lastIndex+1);

            return;
        }


        if(previousPlayingId==0){

            playlist->insert(0,track);
            index=0;
            settings.setPlayingTrackId(track.trackId);

        }else{

            if(lastIndex==-1){
                playlist->insert(0,track);
                index=0;
                lastIndex+=1;

            }else{

                lastIndex=lastIndex+1;
                index=lastIndex+1;
                playlist->insert(index,track);

            }
        }

        //insert the track at last index +1


        qDebug()<<"TOTAL TRACKS "<<playlist->count();
        settings.setPlayingTrackId(track.trackId);


    }

    track.isPlaying=true;
    setPlayingIndex(index);
    playFromUrl(track);

    int diff=playlist->count()-index;

    if(diff<5){
        dynamicLoadQueueTracks();
    }
    emit notifyTrackInserted(track,index,lastIndex);
}

void JPlaylistController::addTrackToQueue(JTrack track,bool updateInDb)
{
    if(updateInDb){
        await(worker.addTrackToQueue(track.trackId),this,[track](JTrack res){

        qDebug()<<res.trackName<<" updated";

        });

    }


    if(playlist->contains(track)){
        return;
    }
    playlist->append(track);



    emit notifyTrackInserted(track,-1,-1);






}

JTrack JPlaylistController::getNextTrack()
{
    if(playlist->isEmpty()){

        JTrack track;
        track.trackId=-1;
        return track;
    }

    int position=getPlayingIndex();

    position++;



    if( position>playlist->count()-1){

        if(settings.getRepeatStatus()==RepeatMode::All){

            return playlist->at(0);
        }

        JTrack track;
        track.trackId=-1;
        return track;
    }

    return playlist->at(position);
}

JTrack JPlaylistController::getPreviousTrack()
{
    if(playlist->isEmpty()){

        JTrack track;
        track.trackId=-1;
        return track;
    }

    int position=getPlayingIndex();

    position--;



    if(position<0 ){



        JTrack track;
        track.trackId=-1;
        return track;
    }

    return playlist->at(position);

}

void JPlaylistController::addPlaylistToQueue(int playlistId, bool append)
{


    if(!isLoading){
        setIsLoading(true);
        if(!append){
             playlist->clear();
        }

        await(worker.queuePlaylistTrack(playlistId,append),this,[this,append](QList<JTrack> queuedTracks){


            int index=0;
            foreach(JTrack t, queuedTracks){
                if(index==0){
                    if(!append){
                          loadPlayingTrackToQueuePlaylist(t);
                    }else{
                        this-> addTrackToQueue(t,false);
                    }


                }else{


                    this-> addTrackToQueue(t,false);
                }
                index++;
            }

            setIsLoading(false);

        });
    }


}

void JPlaylistController::addPlaylistToQueue(QList<JTrack> tracks, bool append)
{
    Q_UNUSED(append)

    if(!isLoading){
        setIsLoading(true);
        if(!append){
             playlist->clear();
        }

        await(worker.queuePlaylistTrack(tracks,append),this,[this,append](QList<JTrack> queuedTracks){


            int index=0;
            foreach(JTrack t, queuedTracks){
                if(index==0){
                    if(!append){
                          loadPlayingTrackToQueuePlaylist(t);
                    }else{
                        this-> addTrackToQueue(t,false);
                    }


                }else{


                    this-> addTrackToQueue(t,false);
                }
                index++;
            }

            setIsLoading(false);

        });
    }
}

void JPlaylistController::addTrackToPlaylist(int trackId, int playlistId)
{

    await(worker.addTrackToPlaylist(trackId,playlistId),this,[playlistId,this](JTrack res){



        qDebug()<<res.trackId<<" Added to playlist "<<playlistId;
        await(worker.getTrack(res.trackId),this,[this](JTrack t){

            emit  notifyTrackAddedToPlaylist(t);

        });

    });

}

void JPlaylistController::removeTrackFromPlaylist(int trackId, int playlistId)
{
    await(worker.removeTrackFromPlaylist(trackId,playlistId),this,[this,playlistId](JTrack res){


        await(worker.getTrack(res.trackId),this,[this,playlistId](JTrack t){

            bool isFavorite=false;
            if(playlistId==1){
                isFavorite=true;
            }
            emit notifyTrackRemovedFromPlaylist(t,isFavorite);

        });

    });
}

void JPlaylistController::playFromUrl(JTrack track)
{
    engine.loadAudio(track.fileUrl);
    emit trackPlaybackStarted(track);

    toggleTrackAsPlayed(track.trackId);

    //increment play count
    aiManager.incrementPlayCount(track.trackId);

    engine.play();




}

void JPlaylistController::dynamicLoadQueueTracks()
{
    qDebug()<<"Fetching dynamic playlist "<<isLoading;


    if(!isLoading){
        setIsLoading(true);
        await(worker.getQueuedPlaylist(),this,[this](QList<JTrack> playingQueue){


            int index=0;
            foreach(JTrack t, playingQueue){

                this-> addTrackToQueue(t,false);

                index++;
            }

            setIsLoading(false);

            qDebug()<<"Done fetching playlist "<<isLoading;
        });
    }

}

void JPlaylistController::toggleTrackAsPlayed(int trackId)
{
    await(worker.toggleQueuedTrackAsPlayed(trackId),this,[](int res){
        qDebug()<<res<<" result";
    });
}

int JPlaylistController::indexFromPlaylist(int playingTrackId)
{
    int index=-1;
    foreach(JTrack t,*playlist){

        if(t.trackId==playingTrackId){
            break;
        }
        index++;
    }
    return index;
}

bool JPlaylistController::getIsLoading() const
{
    return isLoading;
}

void JPlaylistController::setIsLoading(bool newIsLoading)
{
    isLoading = newIsLoading;

    emit notifyAmBusy(newIsLoading);
}

int JPlaylistController::getPlayingIndex() const
{
    return playingIndex;
}

void JPlaylistController::setPlayingIndex(int newPlayingIndex)
{
    playingIndex = newPlayingIndex;
}
