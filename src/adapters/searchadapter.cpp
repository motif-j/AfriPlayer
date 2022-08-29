#include "searchadapter.h"

SearchAdapter::SearchAdapter(QObject *parent)
    : AbstractTracksAdapter(parent)
{

}

void SearchAdapter::querySong(QString query)
{

    this->setIsLoading(true);

    clearTracks();
    await(woker.searchForTracksByQuery(query),this,[this](QList<JTrack> searchResult){


        qDebug()<<"Search Size "<<searchResult.count();

        int index=0;
        foreach(JTrack t,searchResult){
            this->add(t,index);
            index++;
        }
        setIsLoading(false);
    });
}
