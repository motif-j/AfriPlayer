#include "mainworker.h"
#include "QThread"



QFuture<QList<JTrack> > MainWorker::getPlaylistTracks(int playlistId, int refreshCode)
{

    return QtConcurrent::run(threadPool,[this,playlistId,refreshCode](){

        if(playlistId==-1){

            return *db.fetchRecentlyPlayedTracks();
        }

        auto currentPlaylist=db.fetchPlaylistTracksFromRepo(playlistId);
        switch (playlistId) {

        case JMalkiaDbInterface::ID_RAND:
        case JMalkiaDbInterface::ID_SONGSYOUMAYKNOW:
        {

            if(currentPlaylist->isEmpty() || refreshCode==1){

                currentPlaylist->clear();
                db.clearPlaylist(playlistId);
                auto randPlaylist=db.randomizedPlaylist();

                for(JTrack t:*randPlaylist){
                    //add playlist to db
                    db.addTrackToPlaylist(t,playlistId);
                    currentPlaylist->append(t);
                }
                delete randPlaylist;
            }

            break;
        }


        }
        QThread::msleep(500);

        return *currentPlaylist;

    });



}

QFuture<JTrack> MainWorker::getTrack(int trackId)
{
    return QtConcurrent::run(threadPool,[this,trackId](){


        return *db.getTrack(trackId);
    });
}

QFuture<QList<JTrack> > MainWorker::queuePlaylistTrack(int playlistId, bool append)
{

    return QtConcurrent::run(threadPool,[this,playlistId,append](){
        auto tracks=db.fetchPlaylistTracksFromRepo(playlistId);
        if(!append){
            //clear the que

            db.clearQueue();
        }

        foreach(JTrack t, *tracks){
            db.queueTrack(t.trackId);
        }

        delete tracks;

        auto queue=db.fetchNext10QueuedTracks();

        return *queue;


    });


}

QFuture<QList<JTrack> > MainWorker::getQueuedPlaylist()
{
    return QtConcurrent::run(threadPool,[this](){

        auto queue=db.fetchNext10QueuedTracks();

        return *queue;
    });
}

QFuture<QList<JTrack> > MainWorker::getTracks(int lastId)
{
    return  QtConcurrent::run(threadPool,[this,lastId](){
        // int lim=db.generateLimit(lastId);
        //        int limit=20;

        //        if(lim<20){
        //            lim=limit;
        //        }


        return *db.getTracks(lastId,20);
    });

}

QFuture<int> MainWorker::toggleQueuedTrackAsPlayed(int trackId)
{
    return QtConcurrent::run(threadPool,[this,trackId](){

        db.toggleQueuedTrackPlayed(trackId);
        db.addTrackToRecentlyPlayed(trackId);

        return 0;
    });
}

QFuture<JTrack> MainWorker::addTrackToPlaylist(int trackId, int playlistId)
{

    return QtConcurrent::run(threadPool,[this,playlistId,trackId](){
        JTrack *t= db.getTrack(trackId);

        db.addTrackToPlaylist(*t,playlistId);

        t=db.getTrack(trackId);

        return *t;
    });
}

QFuture<JTrack> MainWorker::removeTrackFromPlaylist(int trackId, int playlistId)
{
    return QtConcurrent::run(threadPool,[this,playlistId,trackId](){
        JTrack *t= db.getTrack(trackId);

        db.deleteTrackFromPlaylist(*t,playlistId);
        t=db.getTrack(trackId);

        return *t;
    });
}

QFuture<JTrack> MainWorker::addTrackToQueue(int trackId)
{
    return QtConcurrent::run(threadPool,[this,trackId](){

        db.queueTrack(trackId);

        return *db.getTrack(trackId);

    });

}

QFuture<QStringList> MainWorker::loadFolders()
{
    return QtConcurrent::run(threadPool,[this](){

        return db.getFolders();
    });

}

QFuture<QStringList>MainWorker::addFolderToLib(QString folder)
{

    return QtConcurrent::run(threadPool,[this,folder](){

        db.addFolderToLibs(folder);
        return db.getFolders();
    });
}

QFuture<QStringList> MainWorker::deleteFolderFromLib(QString folder)
{
    return QtConcurrent::run(threadPool,[this,folder](){

        db.removeFolder(folder);
        return db.getFolders();
    });

}

QFuture<QList<JTrack> > MainWorker::searchForTracksByQuery(QString query)
{

    return QtConcurrent::run(threadPool,[this,query](){

        QList<JTrack> searchResult=db.searchTrackByQuery(query);

        return searchResult;
    });
}

QFuture<QList<JPlaylist> > MainWorker::getPlaylists(bool isHome)
{
    return QtConcurrent::run(threadPool,[this,isHome](){

        return *db.fetchPlaylistsFromRepository(10,isHome);
    });


}

QFuture<JPlaylist> MainWorker::addPlaylist(JPlaylist playlist)
{
    return QtConcurrent::run(threadPool,[this,playlist](){

        db.addNewPlaylist(playlist);

        auto pls=db.fetchPlaylistsFromRepository(10);

        JPlaylist first =pls->first();
        return first;
    });

}
