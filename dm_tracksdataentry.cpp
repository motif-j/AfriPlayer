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


    loadTracks();
}

void TracksDataEntry::loadPlaylistTracks(int playlistId)
{



    setIsLoading(true);

    //0=Rnd mix 1, 1=Rand mix 2, 2=Rnd mix 3
    /*
     *Before we call this function clear the list first to avoid
     *append.
     *This function should at all cost only return unique data
     */


   // clearPlaylist();
    emit fetchPlaylistTracks(playlistId);



}

void TracksDataEntry::clearPlaylist()
{
    setIsLoading(true);
    if(count>0){
        //here the data list is not empty


        emit beginRemoveRows(QModelIndex(),0,m_data.count()-1);
        m_data.clear();
        emit endRemoveRows();
        setCount(m_data.count());

    }
    setIsLoading(false);
}



void TracksDataEntry::handleFetchedTracks(QList<JTrack> *tracks)
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
