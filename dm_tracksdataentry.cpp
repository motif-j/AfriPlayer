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

    case JRole::ROLE_ISFAVORITE:
        return track.isFavorite;

    case JRole::ROLE_ISPLAYING:
        return track.isPlaying;
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

void TracksDataEntry::addTrackToPlaylist(int trackId, int playlistId)
{

    emit this->addTrackToPlaylistSig(trackId,playlistId);
}

void TracksDataEntry::loadQuedTracks()
{

    playlistId=-2;
    emit loadQueuedTracksSig();
}

void TracksDataEntry::addTrackToQue(int trackId)
{
    emit addTrackToQueSig(trackId);
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

void TracksDataEntry::newListIndex(int newIndex)
{
    setActiveIndex(newIndex);
    setActiveTrackId(m_data.value(newIndex).trackId);

}

void TracksDataEntry::playNext()
{
    QSettings settings("AfrikTek","Qplayer");
    if(playlistId==-2){

        if(!m_data.isEmpty()){

            int cId=settings.value("playingTrackId",0).toInt();
            JTrack pTrack;

            int oldIndex=getPlayingIndex(cId);


            if(oldIndex>-1 && oldIndex<count-1){


                pTrack=m_data.value(oldIndex);

                pTrack.isPlaying=false;
                m_data.replace(oldIndex,pTrack);
                QModelIndex topLeft=createIndex(oldIndex,0);
                QModelIndex bottomRight=createIndex(oldIndex,0);

                emit dataChanged(topLeft,bottomRight);
            }

            oldIndex++;;


            if(oldIndex>m_data.count()-1){{
                    oldIndex=m_data.count()-1;
                }

            }


            pTrack=m_data.value(oldIndex);
            pTrack.isPlaying=true;
            m_data.replace(oldIndex,pTrack);

            QModelIndex topLeft=createIndex(oldIndex,0);
            QModelIndex bottomRight=createIndex(oldIndex,0);

            emit dataChanged(topLeft,bottomRight);
            int playingId=pTrack.trackId;

            mController.getPlayingTrack(playingId);

            //  auto

            emit dataChanged(topLeft,bottomRight);

            activeIndex=oldIndex;

            emit activeIndexChanged();
            if((m_data.count()-activeIndex)<5){


                loadQuedTracks();
            }
        }

    }
}

void TracksDataEntry::playPrevious()
{
    QSettings settings("AfrikTek","Qplayer");

    if(playlistId==-2){
        //activeIndex=getPlayingIndex();

        if(!m_data.isEmpty()){


            JTrack pTrack;
            int cId=settings.value("playingTrackId",0).toInt();


            int oldIndex=getPlayingIndex(cId);


            if(oldIndex>-1 && oldIndex<count-1){


                pTrack=m_data.value(oldIndex);

                pTrack.isPlaying=false;
                m_data.replace(oldIndex,pTrack);
                QModelIndex topLeft=createIndex(oldIndex,0);
                QModelIndex bottomRight=createIndex(oldIndex,0);

                emit dataChanged(topLeft,bottomRight);
            }

            oldIndex--;

            if(oldIndex<0 ){{
                    oldIndex=0;
                }

            }

            pTrack=m_data.value(oldIndex);
            pTrack.isPlaying=true;
            m_data.replace(oldIndex,pTrack);

            QModelIndex topLeft=createIndex(oldIndex,0);
            QModelIndex bottomRight=createIndex(oldIndex,0);

            emit dataChanged(topLeft,bottomRight);
            int playingId=pTrack.trackId;

            mController.getPlayingTrack(playingId);

            //  auto


            emit dataChanged(topLeft,bottomRight);

            activeIndex=oldIndex;
            emit activeIndexChanged();
        }
    }
}

void TracksDataEntry::playQueuedTrack(int trackId)
{

    if(playlistId==-2){
        if(!m_data.isEmpty()){


            QSettings settings("AfrikTek","Qplayer");


            int cId=settings.value("playingTrackId",0).toInt();

            JTrack pTrack;
            int oldIndex=getPlayingIndex(trackId);

            if(oldIndex==-1){
                oldIndex=getPlayingIndex(cId);
            }

            if(oldIndex<0 || oldIndex>m_data.count()-1){

                 //qDebug()<<"OUT OF BOUND EXC";
                //oldIndex=0;
                bool hasFound=false;
                for(JTrack t :m_data){
                    if(t.isPlaying){
                        hasFound=true;
                        break;
                    }
                    oldIndex++;
                }

                if(!hasFound){

                    pTrack= mController.getTrackSync(trackId);
                    pTrack.isPlaying=true;

                    emit beginInsertRows(QModelIndex(),0,0);

                    m_data.insert(0,pTrack);

                    emit endInsertRows();

                    activeIndex=0;

                    emit activeIndexChanged();


                    mController.getPlayingTrack(pTrack.trackId);
                    return;
                }



            }else{


                 int cIndex=getPlayingIndex(cId);
                 if(cIndex>-1){
                     oldIndex=cIndex;
                 }
                pTrack=m_data.value(oldIndex);

                pTrack.isPlaying=false;
                m_data.replace(oldIndex,pTrack);

                QModelIndex topLeft=createIndex(oldIndex,0);
                QModelIndex bottomRight=createIndex(m_data.count()-1,0);

                // qDebug()<<" Two "<<oldIndex;

                emit dataChanged(topLeft,bottomRight);
            }

            oldIndex=getPlayingIndex(trackId);



            if(oldIndex<0 || oldIndex>m_data.count()-1){


                //The item is not available so insert it at top


                pTrack= mController.getTrackSync(trackId);
                pTrack.isPlaying=true;

                emit beginInsertRows(QModelIndex(),0,0);

                m_data.insert(0,pTrack);

                emit endInsertRows();

                activeIndex=0;

                emit activeIndexChanged();

                mController.getPlayingTrack(pTrack.trackId);

                return;


            }


            pTrack=m_data.value(oldIndex);
            pTrack.isPlaying=true;
            m_data.replace(oldIndex,pTrack);


            QModelIndex topLeft=createIndex(oldIndex,0);
            QModelIndex bottomRight=createIndex(oldIndex,0);

            emit dataChanged(topLeft,bottomRight);
            int playingId=pTrack.trackId;

            mController.getPlayingTrack(playingId);

            //  auto

            activeIndex=oldIndex;
            emit dataChanged(topLeft,bottomRight);

            emit activeIndexChanged();

        }
    }

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

        clearPlaylist();
        addData(tracks);
    }

}

void TracksDataEntry::handlePlayingTrackFetched(QVariantMap trackMap)
{

    int trackId=trackMap["trackId"].toInt();

    if(playlistId!=-2){



        int newIndex=0;
        foreach(JTrack track,m_data){

            if(track.trackId==trackId){

                break;
            }
            newIndex++;
        }


        if(newIndex<0 || newIndex>count-1){
            return;
        }



        auto track=m_data.value(newIndex);
        track.isFavorite=trackMap["isFavorite"].toBool();

        m_data.replace(newIndex,track);

        QModelIndex topLeft=createIndex(newIndex,0);
        QModelIndex bottomRight=createIndex(newIndex,0);
        emit dataChanged(topLeft,bottomRight);
    }
}

void TracksDataEntry::handleQueuedTracksFetched(QList<JTrack> *queuedTracks)
{

    if(playlistId==-2){

        addData(queuedTracks);
    }else{

        if(this->activeTrackId!=mController.getActiveTrackId()){
            handleActiveTrackIdChanged(mController.getActiveTrackId());
        }
    }


}

void TracksDataEntry::handleSoloQueuedTrackFetched(JTrack track)
{
    if(playlistId==-2){

        //This will not be the case always

        if(!m_data.contains(track)){

            emit beginInsertRows(QModelIndex(),count,count);
            m_data.append(track);
            emit   endInsertRows();
            setCount(m_data.count());
        }




    }



}


int TracksDataEntry::getActiveIndex() const
{
    return activeIndex;
}

void TracksDataEntry::setActiveIndex(int newActiveIndex)
{

    if(playlistId>-2){

        if (activeIndex == newActiveIndex)
            return;
        activeIndex = newActiveIndex;

        emit activeIndexChanged();
    }


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
    emit activeTrackIdChanged(newActiveTrackId);
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

            if(!m_data.contains(track)){
                emit beginInsertRows(QModelIndex(),i,i);
                m_data.append(track);
                emit   endInsertRows();
                i=i+1;
                setCount(m_data.count());
            }



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
