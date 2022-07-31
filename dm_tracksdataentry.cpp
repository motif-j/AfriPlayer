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

    QString timeFormat;

    if(nT.hour()==0){
        timeFormat="mm:ss ";
    }else{
        timeFormat="hh:mm:ss";
    }

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

        return nT.toString(timeFormat);

    case JRole::ROLE_FILEURL:
        return track.fileUrl;
    }

    return QVariant();

}



void TracksDataEntry::loadMoreTracks()
{
    qDebug("Load more tracks");

    loadTracks();
}



void TracksDataEntry::handleFetchedTracks(QList<JTrack> *tracks)
{

    if(tracks->count()>0){
        qDebug("list >0");

        int i=count;
        for(auto track:*tracks){
            emit beginInsertRows(QModelIndex(),i,i);
            m_data.append(track);
            emit   endInsertRows();

            i=i+1;
        }

    }else{
        qDebug("Done refreshing");
        setDoneFetching(true);
    }
    setCount(m_data.count());
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
    qDebug("Load tracks");
    int lastId=0;
    if(count>0){
        qDebug()<<"count = "<<count;

        auto lastElement=m_data.value(count-1);
        lastId=lastElement.trackId;
        qDebug()<<"Id "<<lastId;

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
