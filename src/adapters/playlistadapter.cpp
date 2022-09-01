#include "playlistadapter.h"

PlaylistAdapter::PlaylistAdapter(QObject *parent)
    : QAbstractListModel{parent}
{

}

int PlaylistAdapter::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return playlists.count();

}

QVariant PlaylistAdapter::data(const QModelIndex &index, int role) const
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
    case JRole::ROLE_ISPLAYLISTFOLDER:

        return QVariant(playlistItem.isFolder);


    case JRole::ROLE_PLAYLIST_COLORS:
        return QVariant(playlistItem.colors);
    }

    return QVariant();
}

QHash<int, QByteArray> PlaylistAdapter::roleNames() const
{

    return mRoles.roles();
}

void PlaylistAdapter::loadPlaylists(bool isHome,bool folders)
{
    setIsLoading(true);
    await(worker.getPlaylists(isHome,folders),this,[this](QList<JPlaylist> result){

        int index=0;
        foreach(JPlaylist p,result){
            add(p,index);
            index++;
        }

        setIsLoading(false);

    });


}

void PlaylistAdapter::addPlaylist(QString title)
{
    setIsLoading(true);
    JPlaylist pl;
    pl.playlistTitle=title;

    await(worker.addPlaylist(pl),this,[this](JPlaylist res){

        add(res,count);
        setIsLoading(false);
    });

}

void PlaylistAdapter::add(JPlaylist p, int index)
{
    if(!playlists.contains(p)){

        emit beginInsertRows(QModelIndex(),index,index);

        playlists.insert(index,p);

        emit endInsertRows();

        setCount(playlists.count());
    }
}

int PlaylistAdapter::getCount() const
{
    return count;
}

void PlaylistAdapter::setCount(int newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged();
}

bool PlaylistAdapter::getIsLoading() const
{
    return isLoading;
}

void PlaylistAdapter::setIsLoading(bool newIsLoading)
{
    if (isLoading == newIsLoading)
        return;
    isLoading = newIsLoading;
    emit isLoadingChanged();
}
