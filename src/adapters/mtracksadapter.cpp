#include "mtracksadapter.h"

MTracksAdapter::MTracksAdapter(QObject *parent)
    : AbstractTracksAdapter(parent)
{

}

void MTracksAdapter::loadTracks()
{



    if(!isLoading){
        setIsLoading(true);

        int lastId=0;

        if(tracks.count()>0){

            auto lastElement=tracks.value(tracks.count()-1);
            lastId=lastElement.trackId;

        }


        await(woker.getTracks(lastId),this,[this](QList<JTrack> result){


             int index=tracks.count();
             if(tracks.isEmpty()){
               index=0;
             }

             foreach(JTrack t, result){
                 this->add(t,index);
                 index++;

             }
             setIsLoading(false);
             if(result.isEmpty()){
                 setDoneFetching(true);
             }

        });
    }



}

bool MTracksAdapter::getDoneFetching() const
{
    return doneFetching;
}

void MTracksAdapter::setDoneFetching(bool newDoneFetching)
{
    if (doneFetching == newDoneFetching)
        return;
    doneFetching = newDoneFetching;
    emit doneFetchingChanged();
}
