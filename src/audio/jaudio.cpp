#include "jaudio.h"



#include <QFile>


JAudio::JAudio(QObject *parent)
    : QObject{parent}
{


    //  playerEngine=new AudioEngine(this);

    int volume=appSettings.getVolume();
    setPlayerVolume(volume);

    connect(&playerEngine,&AudioEngine::playbackStateChanged,this,&JAudio::onPlaybackStatusChanged);
    connect(&playerEngine,&AudioEngine::lockedChanged,this,&JAudio::onEngineLockedChanged);
    connect(&playerEngine,&AudioEngine::positionChanged,this,&JAudio::onPositionChanged);
    connect(&playlistController,&JPlaylistController::trackPlaybackStarted,this,&JAudio::onPlaylistPlaybackStarted);
    connect(&playlistController,&JPlaylistController::notifyTrackAddedToPlaylist,this,&JAudio::onTrackAddedToPlaylist);
    connect(&playlistController,&JPlaylistController::notifyTrackRemovedFromPlaylist,this,&JAudio::onTrackRemovedFromPlaylist);





    await(worker.getTrack(appSettings.getPlayingTrackId()),this,[this](JTrack t){

        reloadTrack(t);

    });

    // player

    //  connect(player1,SIGNAL(error(QMediaPlayer::Error)),this,SLOT(onError(QMediaPlayer::Error)));
    //  connect (player1,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
    //  connect(player1,&QMediaPlayer::mediaStatusChanged,this,&JAudio::onMediaStatusChanged);
    ///  connect(player1,&QMediaPlayer::stateChanged,this,&JAudio::onPlaybackStatusChanged);


}


int JAudio::getPosition() const
{
    return position;
}

void JAudio::setPosition(int newPosition)
{
    if (position == newPosition)
        return;
    position = newPosition;

    emit positionChanged();
}

//void JAudio::play(QString fileUrl,int trackId)
//{
//     qDebug()<<"PLAYING ID "<<playingId<< "TRACK ID "<<trackId;
//    if(canPlay){
//        qDebug("Engine unlocked");

//        if(trackId==playingId){

//            switch (playerEngine.getPlayerState()) {

//            case AudioEngine::PlayerState::Idle:
//            {

//                 reloadTrack(fileUrl,trackId);
//            }
//                break;
//            case AudioEngine::PlayerState::Opening:
//            {

//            }
//                break;
//            case AudioEngine::PlayerState::Buffering:

//            {

//            }
//                break;
//            case AudioEngine::PlayerState::Playing:
//            {
//                setIsPlaying(false);
//                playerEngine.pause();


//            }
//                break;
//            case AudioEngine::PlayerState::Paused:
//            {

//                setIsPlaying(true);
//                playerEngine.resume();
//            }
//                break;
//            case AudioEngine::PlayerState::Stopped:
//            {

//                reloadTrack(fileUrl,trackId);
//            }
//                break;
//            case AudioEngine::PlayerState::Ended:
//                reloadTrack(fileUrl,trackId);
//                break;
//            case AudioEngine::PlayerState::Error:
//                break;

//            }

//        }else{

//            reloadTrack(fileUrl,trackId);
//        }
//    }else{
//        qDebug("engine locked ");
//    }
//}


void JAudio::pause()
{
    if(canPlay){
       // setIsPlaying(false);

        playerEngine.pause();
    }
}

void JAudio::setVolume(double volume)
{

    appSettings.setVolume(static_cast<int>(volume));
    // setPlayerVolume()
    playerEngine.setVolume(static_cast<int>(volume));


}


void JAudio::seek(int newPosition)
{
    //player1->setPosition(newPosition);
    playerEngine.seek(newPosition);

}

void JAudio::resume()
{
    if(canPlay){
        if(playerEngine.getPlayerState()==AudioEngine::Ended){
            playerEngine.loadAudio(ptrack.fileUrl);
            return;
        }

        playerEngine.resume();
    }
}

void JAudio::onPositionChanged(float position,int newPos)
{
    Q_UNUSED(position)
    setPosition(newPos);

    // qDebug()<<formatedTime;

    auto formatedTime=getFormattedTime(newPos);
    setTimeElapsed(*formatedTime);


    delete formatedTime;
}

void JAudio::onError(QMediaPlayer::Error error)
{
    //    switch (error) {
    //    case QMediaPlayer::NoError:
    //        break;
    //    case QMediaPlayer::FormatError:
    //        break;
    //    case QMediaPlayer::NetworkError:
    //        break;
    //    case QMediaPlayer::AccessDeniedError:
    //        break;
    //    case QMediaPlayer::ServiceMissingError:
    //        break;
    //    case QMediaPlayer::MediaIsPlaylist:
    //        break;

    //    case QMediaPlayer::ResourceError:
    //        qDebug()<<"Error "<<player1->errorString();
    //        break;

    //    }


}



void JAudio::onPlaybackStatusChanged(AudioEngine::PlayerState state)
{
    switch (state) {
    case AudioEngine::PlayerState::Idle:
        break;
    case AudioEngine::PlayerState::Opening:
        break;
    case AudioEngine::PlayerState::Buffering:
        break;
    case AudioEngine::PlayerState::Playing:
    {
        if(canPlay){
            if(ptrack.duration==0){
                qDebug()<<"Duration is "<<playerEngine.trackLength();
                setCanPlay(false);
                 pause();

                JTrack test=ptrack;
                test.duration=playerEngine.trackLength();
                await(worker.updateTrackDuration(test),this,[this](JTrack res){

                   reloadTrack(res);

                    resume();
                    setCanPlay(true);
                });
            }
        }


        // playerEngine.resume();
        setPlayingId(ptrack.trackId);

        setIsPlaying(true);
        setPlaybackStatus(0);
        // if(duration==0){
        //  playerEngine.pause();
        setDuration(playerEngine.trackLength());
        auto l=getFormattedTime(duration);

        setTrackLength(*l);
        delete l;
        // }

    }

        break;
    case AudioEngine::PlayerState::Paused:
        setIsPlaying(false);
        setPlaybackStatus(2);
        break;
    case AudioEngine::PlayerState::Stopped:
        // setIsPlaying(false);
        //setPlaybackStatus(1);

        qDebug()<<"Stopped";
        break;
    case AudioEngine::PlayerState::Ended:
        setIsPlaying(false);

        if(appSettings.getRepeatStatus()==RepeatMode::All){
           setPlayNext(1);
           setIsPlaying(true);
        }

        //
        // setIsPlaying(false);

        break;
    case AudioEngine::PlayerState::Error:
        qDebug()<<"Error occured on engine";
        break;



    }
}

void JAudio::onEngineLockedChanged(bool locked)
{
    setCanPlay(!locked);
}

void JAudio::onPlaylistPlaybackStarted(JTrack track)
{

    setPlaybackStarted(2);
    setCanPlay(false);
    await(worker.getTrack(track.trackId),this,[this](JTrack res){

        reloadTrack(res);
        setCanPlay(true);
    });



}

void JAudio::onTrackAddedToPlaylist(JTrack track)
{
    // qDebug()<<"ON TRACK Added "<<track.isFavorite;



    if(playingId==0){
        if(ptrack.isFavorite==track.isFavorite){
            return;
        }
        reloadTrack(track);
    }else{
        if(track.trackId==playingId){
            reloadTrack(track);


        }
    }


}

void JAudio::onTrackRemovedFromPlaylist(JTrack track)
{
    if(playingId==0){

        if(ptrack.isFavorite==track.isFavorite){
            return;
        }
        reloadTrack(track);
    }else{
        if(track.trackId==playingId){
            reloadTrack(track);


        }
    }
}

int JAudio::getPlaybackStarted() const
{
    return playbackStarted;
}

void JAudio::setPlaybackStarted(int newPlaybackStarted)
{
    if (playbackStarted == newPlaybackStarted)
        return;
    playbackStarted = newPlaybackStarted;
    emit playbackStartedChanged();
}

const QVariant &JAudio::getPlayingTrackVar() const
{
    return playingTrackVar;
}

void JAudio::setPlayingTrackVar(const QVariant &newPlayingTrackVar)
{
    if (playingTrackVar == newPlayingTrackVar)
        return;
    playingTrackVar = newPlayingTrackVar;
    emit playingTrackVarChanged();
}

const QString &JAudio::getTrackLength() const
{
    return trackLength;
}

void JAudio::setTrackLength(const QString &newTrackLength)
{
    if (trackLength == newTrackLength)
        return;
    trackLength = newTrackLength;
    emit trackLengthChanged();
}

int JAudio::getPlayNext() const
{
    return playNext;
}

void JAudio::setPlayNext(int newPlayNext)
{
    if (playNext == newPlayNext)
        return;
    playNext = newPlayNext;
    emit playNextChanged();
}



void JAudio::reloadTrack(JTrack tr)
{
    setCanPlay(false);

    await(worker.getTrack(tr.trackId),this,[this](JTrack t){

        ptrack=t;
        //  setIsPlaying(true);

        setDuration(t.duration);
        // setPlayingId(t.trackId);
        // playingId=t.trackId;
        if(duration>0){
            auto l=getFormattedTime(duration);

            setTrackLength(*l);
        }


        QTime *time =new QTime(0,0,0,0);

        QTime nT=time->addMSecs(t.duration);

        time=nullptr;

        delete time;

        QString formatedTime=formatTrackTime(nT);


        QVariantMap trackMap;
        trackMap["trackName"]=t.trackName;
        trackMap["trackId"]=t.trackId;
        trackMap["albumName"]=t.albumName;
        trackMap["artistName"]=t.artistName;
        trackMap["duration"]=formatedTime;
        trackMap["isFavorite"]=t.isFavorite;
        trackMap["colors"]=t.colors;
        trackMap["fileUrl"]=t.fileUrl;

        setPlayingTrackVar(trackMap);
        setCanPlay(true);
    });



}

QString *JAudio::getFormattedTime(int time)
{

    QTime *timer =new QTime(0,0,0,0);

    QTime *nT=new QTime(timer->addMSecs(time));



    QString *formatedTime=new QString(formatTrackTime(*nT));

    timer=nullptr;
    delete timer;
    delete nT;

    return formatedTime;

}




int JAudio::getPlaybackStatus() const
{
    return playbackStatus;
}

void JAudio::setPlaybackStatus(int newPlaybackStatus)
{
    if (playbackStatus == newPlaybackStatus)
        return;
    playbackStatus = newPlaybackStatus;
    emit playbackStatusChanged();
}

int JAudio::getPlayingId() const
{
    return playingId;
}

void JAudio::setPlayingId(int newPlayingId)
{
    if (playingId == newPlayingId)
        return;
    playingId = newPlayingId;
    emit playingIdChanged();
}

int JAudio::getPlayerVolume() const
{
    return playerVolume;
}

void JAudio::setPlayerVolume(int newPlayerVolume)
{
    if (playerVolume == newPlayerVolume)
        return;
    playerVolume = newPlayerVolume;

    emit playerVolumeChanged();
}

bool JAudio::getCanPlay() const
{
    return canPlay;
}

void JAudio::setCanPlay(bool newCanPlay)
{
    if (canPlay == newCanPlay)
        return;
    canPlay = newCanPlay;
    emit canPlayChanged();
}

bool JAudio::getIsPlaying() const
{
    return isPlaying;
}

void JAudio::setIsPlaying(bool newIsPlaying)
{
    if (isPlaying == newIsPlaying)
        return;
    isPlaying = newIsPlaying;
    emit isPlayingChanged();
}

int JAudio::getDuration() const
{
    return duration;
}

void JAudio::setDuration(int newDuration)
{
    if (duration == newDuration)
        return;
    duration = newDuration;
    emit durationChanged();
}

const QString &JAudio::getTimeElapsed() const
{
    return timeElapsed;
}

void JAudio::setTimeElapsed(const QString &newTimeElapsed)
{
    if (timeElapsed == newTimeElapsed)
        return;
    timeElapsed = newTimeElapsed;
    emit timeElapsedChanged();
}
