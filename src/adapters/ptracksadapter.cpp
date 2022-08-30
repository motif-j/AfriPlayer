#include "ptracksadapter.h"

PTracksAdapter::PTracksAdapter(QObject *parent)
    : AbstractTracksAdapter(parent)
{


}

void PTracksAdapter::loadTracks(int playlistId, int refresh)
{
    setIsLoading(true);
    this->playlistId=playlistId;

    qDebug()<<"Loading ";


    await(this->woker.getPlaylistTracks(playlistId,refresh),this,[this](QList<JTrack> result){

        setIsLoading(false);
        int index=0;
        foreach(JTrack track,result){
            this->add(track,index);

            index++;
        }


    });



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

