#include "../adapters/jplaylistdataentry.h"

JPlaylistDataEntry::JPlaylistDataEntry(QObject *parent)
    : QAbstractListModel{parent}
{
 connect(this,&JPlaylistDataEntry::fetchHomePlaylistsFromRepo,&mController,&JMusicController::loadHomePlaylist);

 connect(&mController,&JMusicController::homePlaylistFetched,this,&JPlaylistDataEntry::handleHomePlaylistsFetched);


}

int JPlaylistDataEntry::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return playlists.count();
}

QVariant JPlaylistDataEntry::data(const QModelIndex &index, int role) const
{
    auto row=index.row();

    if(row >=playlists.count() || row<0){

        return QVariant();
    }

    JPlaylist playlistItem=playlists.value(row);

    switch (role) {
    case JRole::ROLE_PLAYLISTNAME:
        return QVariant(playlistItem.playlistTitle);

    case JRole::ROLE_PLAYLISTID:

        return QVariant(playlistItem.playlistId);
        break;

    }


    return QVariant();
}

QHash<int, QByteArray> JPlaylistDataEntry::roleNames() const
{

    return mRoles.roles();
}

void JPlaylistDataEntry::handleHomePlaylistsFetched(QList<JPlaylist> *result)
{
    if(result->count()>0){

        int i=count;
        for(auto track : *result){

            emit beginInsertRows(QModelIndex(),i,i);
            playlists.append(track);
            emit endInsertRows();

            i=i+1;

        }
    }

   setCount(result->count());

}

int JPlaylistDataEntry::getCount() const
{
    return count;
}

void JPlaylistDataEntry::setCount(int newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged();
}
