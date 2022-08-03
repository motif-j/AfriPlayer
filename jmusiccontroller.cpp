#include "jmusiccontroller.h"
#include <QTime>


void JMusicController::getTrack(int trackId)
{
    emit fetchTrackFromRepository(trackId);
}

void JMusicController::loadTracks(int lastId, int limit)
{
    emit fetchTracksFromRepository(lastId,limit);

}

void JMusicController::loadHomePlaylist()
{
    emit fetchHomePlaylistFromRepository();
}

void JMusicController::loadPlaylistTrack(int playlistId)
{
    emit fetchPlaylistTracksFromRepo(playlistId);

}

void JMusicController::handleFetchTrack(JTrack trackResult)
{
    qDebug()<<" called "<<trackResult.trackName;

    QTime *time =new QTime(0,0,0,0);

    QTime nT=time->addMSecs(trackResult.duration);

    time=nullptr;

    delete time;

    QString formatedTime=formatTrackTime(nT);


    QVariantMap trackMap;
    trackMap["trackName"]=trackResult.trackName;
    trackMap["trackId"]=trackResult.trackId;
    trackMap["albumName"]=trackResult.albumName;
    trackMap["artistName"]=trackResult.artistName;
    trackMap["duration"]=formatedTime;


    emit trackFetched(trackMap);
}

void JMusicController::handleTracksFromRepository(QList<JTrack> *tracks)
{
    emit tracksLoaded(tracks);
}

void JMusicController::handleHomePlaylistsFetchedFromRepository(QList<JPlaylist> *result)
{
    emit homePlaylistFetched(result);
}
