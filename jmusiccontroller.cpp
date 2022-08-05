#include "jmusiccontroller.h"
#include <QTime>


void JMusicController::getTrack(int trackId)
{
    emit fetchTrackFromRepository(trackId);
}

void JMusicController::getPlayingTrack(int trackId)
{
    playingTrackId=trackId;
    emit fetchPlayingTrackFromRepository(trackId);
}

void JMusicController::loadTracks(int lastId, int limit)
{
    emit fetchTracksFromRepository(lastId,limit);

}

void JMusicController::loadHomePlaylist()
{
    emit fetchHomePlaylistFromRepository();
}

void JMusicController::loadPlaylistTrack(int playlistId,int refreshCode)
{
    emit fetchPlaylistTracksFromRepo(playlistId,refreshCode);

}

void JMusicController::loadRecentlyPlayedTracks()
{
    emit fetchRecentlyPlayedTracks();
}

void JMusicController::addTrackToPlaylist(int trackId, int playlistId)
{
  emit addTrackToPlaylistSig(trackId,playlistId);

}

void JMusicController::handleFetchTrack(JTrack trackResult)
{


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
    trackMap["isFavorite"]=trackResult.isFavorite;


    emit trackFetched(trackMap);
}

void JMusicController::handlePlayingTrackFetched(JTrack trackResult)
{

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
     trackMap["isFavorite"]=trackResult.isFavorite;

     qDebug()<<" "<<trackMap["duration"].toString();
    emit playingTrackFetched(trackMap);

}

void JMusicController::handleTracksFromRepository(QList<JTrack> *tracks)
{
    emit tracksLoaded(tracks);
}

void JMusicController:: handlePlaylistTracksFetchedFromRepo(QList<JTrack> *tracks)
{
    emit playlistTracksLoaded(tracks);
}

void JMusicController::handleHomePlaylistsFetchedFromRepository(QList<JPlaylist> *result)
{
    emit homePlaylistFetched(result);
}

void JMusicController::handleRecentlyPlayedTracksFetched(QList<JTrack> *tracks)
{
    emit recentlyPlayedTracksFetched(tracks);
}

void JMusicController::addTrackToRecentsPlaylist(int trackId)
{
    dbInterface.addTrackToRecentlyPlayed(trackId);


    emit fetchRecentlyPlayedTracks();
}

int JMusicController::getActiveTrackId() const
{
    return activeTrackId;
}

void JMusicController::setActiveTrackId(int newActiveTrackId)
{
    activeTrackId = newActiveTrackId;
    worker->activeTrackId=newActiveTrackId;
    emit this->activeTrackIdChanged(newActiveTrackId);
}


