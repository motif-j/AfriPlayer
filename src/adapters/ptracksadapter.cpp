#include "ptracksadapter.h"

PTracksAdapter::PTracksAdapter(QObject *parent)
    : AbstractTracksAdapter(parent)
{

}

void PTracksAdapter::loadTracks(int playlistId, int refresh)
{
    setIsLoading(true);
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
