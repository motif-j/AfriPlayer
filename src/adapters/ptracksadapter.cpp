#include "ptracksadapter.h"

PTracksAdapter::PTracksAdapter(QObject *parent)
    : AbstractTracksAdapter(parent)
{


}

bool PTracksAdapter::getIsUserPlaylist() const
{
    return isUserPlaylist;
}

void PTracksAdapter::setIsUserPlaylist(bool newIsUserPlaylist)
{
    if (isUserPlaylist == newIsUserPlaylist)
        return;
    isUserPlaylist = newIsUserPlaylist;
    emit isUserPlaylistChanged();
}

void PTracksAdapter::loadTracks(int playlistId, int refresh)
{

    if(playlistId<8){
        setIsUserPlaylist(false);
    }else{

        //get playlist

        await(woker.getPlaylist(playlistId),this,[this](JPlaylist playlist){

            if(playlist.isFolder){
                setIsUserPlaylist(false);
            }else{
                setIsUserPlaylist(true);
            }
        });
    }
    setIsLoading(true);
    this->playlistId=playlistId;

    qDebug()<<"Loading ";


    await(this->woker.getPlaylistTracks(playlistId,refresh),this,[this](QList<JTrack> result){


        int index=0;
        foreach(JTrack track,result){
            this->add(track,index);

            index++;
        }
        setIsLoading(false);
        calculateTrackDuration();

    });



}

void PTracksAdapter::loadAiTracks(int playlistId)
{
    if(playlistId<8){
        setIsUserPlaylist(false);
    }

    if(!isLoading){
        setIsLoading(true);
        await(aiManager.getAiTracks(playlistId),this,[this](QList<JTrack> result){


            int index=0;
            foreach(JTrack track,result){
                this->add(track,index);

                index++;
            }
            setIsLoading(false);
             calculateTrackDuration();
        });
    }


}

void PTracksAdapter::addTracksToQueue(bool append)
{
    if(!isLoading){
        setIsLoading(true);
        this->playlistController.addPlaylistToQueue(tracks,append);

        setIsLoading(false);

    }


}

void PTracksAdapter::onTrackRemovedFromPlaylist(JTrack track,bool isFavorite)
{
    AbstractTracksAdapter::onTrackRemovedFromPlaylist(track,isFavorite);

    if(playlistId==1){

        if(!track.isFavorite){

            int index=this->getIndexFromId(track.trackId);
            if(index<0 || index>tracks.count()-1){
                return;
            }

            remove(track,index);
            // this->clearTracks();
        }

    }else{
        if(playlistId>7){
            if(!isFavorite){
                int index=this->getIndexFromId(track.trackId);
                if(index<0 || index>tracks.count()-1){
                    return;
                }

                remove(track,index);
            }

            return;
        }


    }


}

