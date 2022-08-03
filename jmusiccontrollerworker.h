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
public slots:
    void getTrack(const int trackId){

        JTrack *tempTrack=db.getTrack(trackId);


        emit trackFetched(*tempTrack);


    }

    void fetchTracksFromRepository(int lastId,int limit){
        auto tracks=db.getTracks(lastId,limit);

        QThread::msleep(500);

        emit tracksFetchedFromRepository(tracks);
    }

    void fetchHomePlaylistFromRepo(){

        auto playlists=db.fetchPlaylistsFromRepository(5);


        emit homePlaylistFetchedFromRepository(playlists);
    }

    void fetchPlaylistTracksFromRepo(int playlistId){

        switch (playlistId) {

        case 1:
        case 3:
        {
            auto randPlaylist=db.randomizedPlaylist();

            QThread::msleep(500);

            emit tracksFetchedFromRepository(randPlaylist);

            break;
        }
        default:
            emit tracksFetchedFromRepository(new QList<JTrack>());
            break;

        }



    }

signals:
    void trackFetched(JTrack track);
    void tracksFetchedFromRepository(QList<JTrack>*);
    void homePlaylistFetchedFromRepository(QList<JPlaylist>*);


private:

    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

};
#endif // JMUSICCONTROLLERWORKER_H
