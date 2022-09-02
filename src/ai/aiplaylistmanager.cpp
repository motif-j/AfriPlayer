#include "aiplaylistmanager.h"

AiPlaylistManager::AiPlaylistManager(QObject *parent)
    : QObject{parent}
{
    pool=mWorker.getPool();
   // pool->setMaxThreadCount(1);
    //pool->setExpiryTimeout(-1);


}

QFuture<QList<JTrack> > AiPlaylistManager::getAiTracks(int playlistId)
{
    return QtConcurrent::run(pool,[this,playlistId](){

        QThread::msleep(500);
        switch (playlistId) {
        case 2:
        {
            QList<JTrack> mostPlayedTracks=db.getMostPlayedTracks();
            bool hasCount=false;

            //confirm if there is a valid count

            foreach(JTrack t,mostPlayedTracks ){
                if(t.play_count>0){
                    hasCount=true;
                    break;
                }

            }

            if(!hasCount){
                mostPlayedTracks.clear();

                //generate a random playlist
                auto randList=db.randomizedPlaylist();

                foreach(JTrack nTrack,*randList){

                    mostPlayedTracks.append(nTrack);
                }

                randList->clear();

                delete  randList;

            }


            //get tracks  and order them by count

            return mostPlayedTracks;
        }
            break;

        case 3:
        {
            QList<JTrack> leastPlayedTracks=db.getLeastPlayedTracks();

            return leastPlayedTracks;
        }
            break;

        case 4:
        {
            QList<JTrack> newestTracks=db.getNewestTracks();


            //get tracks  and order them by count

            return newestTracks;
        }
            break;


        case 7:
        {
            QList<JTrack> oldestTracks=db.getOldestTracks();


            //get tracks  and order them by count

            return oldestTracks;
        }
            break;

        }

        return *new QList<JTrack>;

    });

}

QFuture<JTrack> AiPlaylistManager::incrementPlayCount(int trackId)
{

    return QtConcurrent::run(pool,[this,trackId](){

        auto track =db.getTrack(trackId);

        int lCount=track->play_count;
        lCount+=1;

        track->play_count=lCount;
        db.updateTrack(*track);

        delete track;

        return *db.getTrack(trackId);
    });
}
