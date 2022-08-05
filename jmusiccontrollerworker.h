#ifndef JMUSICCONTROLLERWORKER_H
#define JMUSICCONTROLLERWORKER_H
#include<QObject>
#include<QThread>
#include "db_jmalkiadbinterface.h"

class JMusicControllerWorker : public QObject
{
    Q_OBJECT
public:
    explicit  JMusicControllerWorker (QObject *parent=nullptr){
        Q_UNUSED(parent)

    }

    int activeTrackId=0;

public slots:
    void getTrack(const int trackId){

        JTrack *tempTrack=db.getTrack(trackId);


        emit trackFetched(*tempTrack);


    }

    void getPlayingTrack(int trackId){
        JTrack *tempTrack=db.getTrack(trackId);
        emit playingTrackFetched(*tempTrack);
    }

    void fetchTracksFromRepository(int lastId,int limit){

        int lim=db.generateLimit(activeTrackId);

        if(lim<20){
            lim=limit;
        }

        auto tracks=db.getTracks(lastId,lim);

        QThread::msleep(500);


        emit tracksFetchedFromRepository(tracks);
    }

    void fetchHomePlaylistFromRepo(){

        auto playlists=db.fetchPlaylistsFromRepository(5);


        emit homePlaylistFetchedFromRepository(playlists);
    }

    void fetchPlaylistTracksFromRepo(int playlistId,int refreshCode){


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
        emit playlistTracksFetchedFromRepo(currentPlaylist);

    }


    void fetchRecentlyPlayedTracks(){

        auto tracks=db.fetchRecentlyPlayedTracks();


        QThread::msleep(500);

        qDebug()<<" Called "<<tracks->size();

        emit recentlyPlayedTracksFetched(tracks);
    }

    void addTrackToPlaylist(int trackId,int playlistId){
        auto track=db.getTrack(trackId);

        db.addTrackToPlaylist(*track,playlistId);

        delete track;

         QThread::msleep(500);

         getPlayingTrack(trackId);
        // getTrack(trackId);
      //  emit playlistTracksFetchedFromRepo(tracks);
    }

signals:
    void trackFetched(JTrack track);
    void playingTrackFetched(JTrack track);
    void tracksFetchedFromRepository(QList<JTrack>*);

    void playlistTracksFetchedFromRepo(QList<JTrack>*);
    void homePlaylistFetchedFromRepository(QList<JPlaylist>*);
    void recentlyPlayedTracksFetched(QList<JTrack>*);



private:

    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

};
#endif // JMUSICCONTROLLERWORKER_H
