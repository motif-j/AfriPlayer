#include "jmusiccontroller.h"
#include <QTime>


void JMusicController::getTrack(int trackId)
{
    emit fetchTrackFromRepository(trackId);
}

void JMusicController::getPlayingTrack(int trackId)
{
    QSettings settings("AfrikTek","Qplayer");
    playingTrackId=trackId;

    settings.setValue("playingTrackId",trackId);

    //toggle queue track played
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

void JMusicController::addTrackToQueue(int trackId)
{
    emit queueTrack(trackId);
}

void JMusicController::addPlaylistToQueue(int playlistId, bool append)
{
    emit queuePlaylistTracks(playlistId,append);

}

void JMusicController::loadQueueList()
{
  emit fetchPlayingQueue();
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

     //que the track
     //queueTrack(trackResult.trackId);
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

void JMusicController::handleQueuedTracksFetched(QList<JTrack> *tracks)
{

    emit queuedTracksFetched(tracks);
}

void JMusicController::handleQueuedSoloTrackFetched(JTrack track)
{

    emit trackQueued(track);
}

JTrack JMusicController::getTrackSync(int trackId)
{
return *dbInterface.getTrack(trackId);
}

void JMusicController::addTrackToRecentsPlaylist(int trackId)
{
    dbInterface.addTrackToRecentlyPlayed(trackId);


    emit fetchRecentlyPlayedTracks();
}

void JMusicController::toggleQueuedTrack(int trackId)
{
  worker->togglePlayingQue(trackId);
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


