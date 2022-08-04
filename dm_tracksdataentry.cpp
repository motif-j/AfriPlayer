#include "dm_tracksdataentry.h"
#include <QTime>
#include <QThread>




int TracksDataEntry::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_data.count();
}

QVariant TracksDataEntry::data(const QModelIndex &index, int role) const
{
    int row=index.row();

    if(row<0 ||row>m_data.count()){
        return QVariant();
    }

    auto track=m_data.value(row);

    QTime *time =new QTime(0,0,0,0);

    QTime nT=time->addMSecs(track.duration);

    time=nullptr;

    delete time;



    QString formatedTime=formatTrackTime(nT);

    //  QVariant value=QVariant::fromValue<JTrack>(track);

    switch(role){
    case JRole::ROLE_TRACKNAME:
        return track.trackName;

    case JRole::ROLE_TRACKID:
        return track.trackId;

    case JRole::ROLE_ALBUMID:
        return track.albumId;

    case JRole::ROLE_ALBUMNAME:
        return track.albumName;

    case JRole::ROLE_ARTISTID:
        return track.artistId;

    case JRole::ROLE_ARTISTNAME:
        return track.artistName;

    case JRole::ROLE_DURATION:

        return formatedTime;

    case JRole::ROLE_FILEURL:
        return track.fileUrl;
    }

    return QVariant();

}



void TracksDataEntry::loadMoreTracks()
{

    playlistId=0;
    loadTracks();
}

void TracksDataEntry::loadPlaylistTracks(int playlistId,int refreshCode)
{

    this->playlistId=playlistId;


    //0=Rnd mix 1, 1=Rand mix 2, 2=Rnd mix 3
    /*
     *Before we call this function clear the list first to avoid
     *append.
     *This function should at all cost only return unique data
     */

    clearPlaylist();
    setIsLoading(true);

    emit fetchPlaylistTracks(playlistId,refreshCode);



}

void TracksDataEntry::loadRecentlyPlayedTracks()
{

    playlistId=-1;
    setIsLoading(true);
    emit fetchRecentlyPlayedTracks();

}

void TracksDataEntry::clearPlaylist()
{

    setIsLoading(true);
    if(count>0){
        //here the data list is not empty


        emit beginRemoveRows(QModelIndex(),0,m_data.count()-1);
        m_data.clear();
        emit endRemoveRows();


    }
    setCount(0);
    setIsLoading(false);
}

void TracksDataEntry::addTrackToRecentlyPlayed(int trackId)
{

    mController.addTrackToRecentsPlaylist(trackId);
    this->reloadRecentlyPlayedTracks();

}

void TracksDataEntry::incrementIndex()
{
    int newIndex=activeIndex+1;


    if(newIndex>count-1){
        newIndex=count-1;
    }
    setActiveIndex(newIndex);
    setActiveTrackId(m_data.value(newIndex).trackId);
}

void TracksDataEntry::decrementIndex()
{
    int newIndex=activeIndex-1;


    if(newIndex<0){
        newIndex=0;
    }
    setActiveIndex(newIndex);
    setActiveTrackId(m_data.value(newIndex).trackId);
}



void TracksDataEntry::handleFetchedTracks(QList<JTrack> *tracks)
{


    if(playlistId==0){

        addData(tracks);

        if(this->activeTrackId!=mController.getActiveTrackId()){
            handleActiveTrackIdChanged(mController.getActiveTrackId());
        }

    }

}

void TracksDataEntry::handleFetchedPlaylstTracks(QList<JTrack> *tracks)
{
    if(playlistId>0){

        addData(tracks);
    }

    if(this->activeTrackId!=mController.getActiveTrackId()){
        handleActiveTrackIdChanged(mController.getActiveTrackId());
    }
}

void TracksDataEntry::handleActiveTrackIdChanged(int newId)
{

    setActiveTrackId(newId);

    int index=0;
    bool hasFound=false;

    foreach(JTrack d, m_data){

        if(d.trackId==newId){
            hasFound=true;
            setActiveIndex(index);

            break;
        }
        index++;

    }

    if(!hasFound){
        setActiveIndex(-1);
    }


}

void TracksDataEntry::handleRecentlyFetchedTracks(QList<JTrack> *tracks)
{


    if(playlistId==-1){

        qDebug()<<"HHHAHAHAHA";
        clearPlaylist();
        addData(tracks);
    }

}

int TracksDataEntry::getActiveIndex() const
{
    return activeIndex;
}

void TracksDataEntry::setActiveIndex(int newActiveIndex)
{
    if (activeIndex == newActiveIndex)
        return;
    activeIndex = newActiveIndex;
    emit activeIndexChanged();
}

int TracksDataEntry::getActiveTrackId() const
{
    return activeTrackId;
}

void TracksDataEntry::setActiveTrackId(int newActiveTrackId)
{
    if (activeTrackId == newActiveTrackId)
        return;
    activeTrackId = newActiveTrackId;
    emit activeTrackIdChanged();
}



bool TracksDataEntry::getIsLoading() const
{
    return isLoading;
}

void TracksDataEntry::setIsLoading(bool newIsLoading)
{
    if (isLoading == newIsLoading)
        return;
    isLoading = newIsLoading;
    emit isLoadingChanged();
}



bool TracksDataEntry::getDoneFetching() const
{
    return doneFetching;
}

void TracksDataEntry::setDoneFetching(bool newDoneFetching)
{
    if (doneFetching == newDoneFetching)
        return;
    doneFetching = newDoneFetching;
    emit doneFetchingChanged();
}

void TracksDataEntry::loadTracks()
{
    setIsLoading(true);

    int lastId=0;
    if(count>0){

        auto lastElement=m_data.value(count-1);
        lastId=lastElement.trackId;


    }

    emit this->fetchTracks(lastId,limit);
}

void TracksDataEntry::addData(QList<JTrack> *tracks)
{

    if(tracks->count()>0){

        int i=count;
        for(auto track:*tracks){
            emit beginInsertRows(QModelIndex(),i,i);
            m_data.append(track);
            emit   endInsertRows();

            i=i+1;
        }

    }else{

        setDoneFetching(true);
    }
    setIsLoading(false);
    setCount(m_data.count());

    if(this->activeTrackId!=mController.getActiveTrackId()){
        handleActiveTrackIdChanged(mController.getActiveTrackId());
    }
}



QHash<int, QByteArray> TracksDataEntry::roleNames() const
{
    return  this->jroles.roles();
}

int TracksDataEntry::getCount() const
{
    return count;
}

void TracksDataEntry::setCount(int newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged(count);
}

void TracksDataEntry::resetCount()
{
    setCount({}); // TODO: Adapt to use your actual default value
}

void TracksDataEntry::reloadRecentlyPlayedTracks()
{
    qDebug()<<"Reloading";

    playlistId=-1;
    setIsLoading(true);
    emit fetchRecentlyPlayedTracks();
}
