#include "tracksadpater.h"


//TracksAdpater::TracksAdpater(QObject *parent)
//    : QAbstractListModel{parent}
//{



//}


AbstractTracksAdapter::~AbstractTracksAdapter()
{
    tracks.clear();
}

int AbstractTracksAdapter::getCount() const
{
    return count;
}

void AbstractTracksAdapter::setCount(int newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged();
}

void AbstractTracksAdapter::add(JTrack track, int index)
{
    if(!tracks.contains(track)){

        emit beginInsertRows(QModelIndex(),index,index);

        tracks.insert(index,track);

        emit endInsertRows();

        setCount(tracks.count());
    }
}

void AbstractTracksAdapter::update(JTrack track, int index)
{
    if(index<0 || index>tracks.count()-1){
        return;
    }

    if(!tracks.isEmpty()){

        tracks.replace(index,track);

        QModelIndex topLeft=createIndex(index,0);
        QModelIndex bottomLeft=createIndex(index,0);

        emit dataChanged(topLeft,bottomLeft);
    }
}

int AbstractTracksAdapter::getIndexFromId(int trackId)
{
    int index=-1;

    foreach(JTrack t,tracks){
        if(t.trackId==trackId)
            break;

        index++;
    }

    return index;
}



bool AbstractTracksAdapter::getIsLoading() const
{
    return isLoading;
}

void AbstractTracksAdapter::setIsLoading(bool newIsLoading)
{
    if (isLoading == newIsLoading)
        return;
    isLoading = newIsLoading;
    emit isLoadingChanged();
}



void AbstractTracksAdapter::clearTracks()
{

    if(tracks.isEmpty()){
        return;
    }
    qDebug()<<"Clear Playlist new Method ";
    emit beginRemoveRows(QModelIndex(),0,tracks.count()-1);
    tracks.clear();
    emit endRemoveRows();

    setCount(tracks.count());

}

void AbstractTracksAdapter::onBusyChanged(bool loading)
{
    setIsLoading(loading);
}

void AbstractTracksAdapter::onTrackAddedToPlaylist(JTrack track)
{
  int ind=getIndexFromId(track.trackId);
  if(ind==-1){
      return;
  }

  if(tracks.isEmpty()){
      return;
  }
  ind+=1;
  auto t=tracks.value(ind);

  track.isPlaying=t.isPlaying;
  update(track,ind);

}

int AbstractTracksAdapter::rowCount(const QModelIndex &parent) const
{

    Q_UNUSED(parent)

    return tracks.count();
}

QVariant AbstractTracksAdapter::data(const QModelIndex &index, int role) const
{
    int row=index.row();

    if(row<0 ||row>tracks.count()){
        return QVariant();
    }

    auto track=tracks.value(row);

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

    case JRole::ROLE_COLORS:
        return track.colors;

    }
    return QVariant();
}

QHash<int, QByteArray> AbstractTracksAdapter::roleNames() const
{

    return roles.roles();
}
