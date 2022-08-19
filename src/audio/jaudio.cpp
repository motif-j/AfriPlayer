#include "jaudio.h"



#include <QFile>


JAudio::JAudio(QObject *parent)
    : QObject{parent}
{


    //inst=libvlc_new(0,NULL);

    playerEngine=new AudioEngine(this);

    faderAnim=new QVariantAnimation(this);
    faderAnim->setDuration(5000);


    connect(faderAnim,&QVariantAnimation::valueChanged,this,&JAudio::onFaderValueChanged);
    connect(faderAnim,&QVariantAnimation::finished,this,&JAudio::onFaderFinished);

    connect(playerEngine,&AudioEngine::playbackStateChanged,this,&JAudio::onPlaybackStatusChanged);

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

void JAudio::play(QString fileUrl,int trackId)
{
    if(canPlay){


        if(trackId==playingId){

            switch (playerEngine->getPlayerState()) {

            case Vlc::Idle:
            {
                fadeOutPlayer();
                setIsPlaying(true);

                playerEngine->loadAudio(fileUrl);

                auto t=db.getTrack(trackId);

                setDuration(t->duration);
                playingId=t->trackId;

                playerEngine->play();
            }
                break;
            case Vlc::Opening:
            {

            }
                break;
            case Vlc::Buffering:

            {

            }
                break;
            case Vlc::Playing:
            {
                setIsPlaying(false);
                fadeInPlayer();


            }
                break;
            case Vlc::Paused:
            {
                fadeOutPlayer();
                setIsPlaying(true);
                playerEngine->play();
            }
                break;
            case Vlc::Stopped:
            {
                fadeOutPlayer();

                setIsPlaying(true);
                playerEngine->loadAudio(fileUrl);

                auto t=db.getTrack(trackId);

                setDuration(t->duration);
                playingId=t->trackId;

                playerEngine->play();
            }
                break;
            case Vlc::Ended:
                break;
            case Vlc::Error:
                break;

            }

        }else{
            fadeOutPlayer();
            setIsPlaying(true);
            playerEngine->loadAudio(fileUrl);

            auto t=db.getTrack(trackId);

            setDuration(t->duration);
            playingId=t->trackId;

            playerEngine->play();
        }
    }
}


void JAudio::pause()
{
    if(canPlay){

        playerEngine->pause();
    }
}

void JAudio::setVolume(double volume)
{

    playerEngine->setVolume(static_cast<int>(volume));


}


void JAudio::seek(int newPosition)
{
    //player1->setPosition(newPosition);

}

void JAudio::resume()
{
  if(canPlay){

    playerEngine->resume();
  }
}

void JAudio::onPositionChanged(qint64 newPos)
{

    setPosition(newPos);


    QTime *time =new QTime(0,0,0,0);

    QTime *nT=new QTime(time->addMSecs(newPos));



    QString *formatedTime=new QString(formatTrackTime(*nT));

    // qDebug()<<formatedTime;

    setTimeElapsed(*formatedTime);

    time=nullptr;
    delete time;
    delete nT;
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



void JAudio::onPlaybackStatusChanged(Vlc::State state)
{
    switch (state) {
    case Vlc::Idle:
        break;
    case Vlc::Opening:
        break;
    case Vlc::Buffering:
        break;
    case Vlc::Playing:
        setIsPlaying(true);
        setPlaybackStatus(0);
        break;
    case Vlc::Paused:
        setIsPlaying(false);
        setPlaybackStatus(2);
        break;
    case Vlc::Stopped:
        setIsPlaying(false);
        setPlaybackStatus(1);
        break;
    case Vlc::Ended:
        break;
    case Vlc::Error:
        break;



    }
}

void JAudio::onFaderValueChanged(const QVariant &value)
{
    setVolume(value.toInt());


    // setPlayerVolume(value.toInt());

}

void JAudio::onFaderFinished()
{
    setCanPlay(true);
    if(faderAnim->currentValue().toInt()==0){
        playerEngine->pause();
    }

}
void JAudio::fadeOutPlayer()
{

    setCanPlay(false);
    faderAnim->setStartValue(0);
    faderAnim->setEndValue(100);
    faderAnim->start();
    // locked=true;
    // emit lockedChanged(true);
}

void JAudio::fadeInPlayer()
{
    setCanPlay(false);
    faderAnim->setStartValue(100);
    faderAnim->setEndValue(0);
    faderAnim->start();
    //locked=false;
    // emit lockedChanged(false);
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
