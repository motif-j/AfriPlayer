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
    if(!isLoading){
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

}

void PlaylistAdapter::loadAiPlaylists()
{
    if(!isLoading){
        setIsLoading(true);

        await(worker.getAiPlaylist(),this,[this](QList<JPlaylist> result){

            int index=0;
            foreach(JPlaylist p,result){
                add(p,index);
                index++;
            }

            setIsLoading(false);

        });
    }
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

void PlaylistAdapter::renamePlaylist(QString newTitle, int playlistId)
{

    await(worker.updatePlaylist(playlistId,newTitle),this,[this](JPlaylist pl){


        int index=getIndexFromId(pl.playlistId);

        if(index==-1){
            return;
        }

        playlists.replace(index,pl);

        QModelIndex top=createIndex(index,0);
        QModelIndex bottom=createIndex(index,0);
        emit dataChanged(top,bottom);


    });


}

void PlaylistAdapter::deletePlaylist(int playlistId)
{

    await(worker.deletePlaylist(playlistId),this,[this,playlistId](int res){


        int index=getIndexFromId(playlistId);

        if(index==-1){
            return;
        }

        emit beginRemoveRows(QModelIndex(),index,index);
        playlists.removeAt(index);
        emit endRemoveRows();

        setCount(playlists.count());


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

int PlaylistAdapter::getIndexFromId(int plId)
{
    bool hasFound=false;
    int index=0;

    foreach(JPlaylist t,playlists){
        if(t.playlistId==plId)
        {
            hasFound=true;
            break;
        }



        index++;
    }
    if(hasFound){
        return index;
    }

    return -1;
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
