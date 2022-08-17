#include "jaudio.h"
#include <QAudioProbe>



JAudio::JAudio(QObject *parent)
    : QObject{parent}
{
    QSettings settings("AfrikTek","Qplayer");

    auto vol=settings.value("volume",20).toInt();

    qDebug()<<"Vol  "<<vol;
    setPrefferedVolume(vol);

    player1=new QMediaPlayer(parent,QMediaPlayer::StreamPlayback);
    player1->setVolume(vol);


    connect(player1,SIGNAL(error(QMediaPlayer::Error)),this,SLOT(onError(QMediaPlayer::Error)));
    connect (player1,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
    connect(player1,&QMediaPlayer::mediaStatusChanged,this,&JAudio::onMediaStatusChanged);
    connect(player1,&QMediaPlayer::stateChanged,this,&JAudio::onPlaybackStatusChanged);

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


    player1->stop();

    player1->setMedia(QUrl::fromLocalFile(fileUrl));

    auto t=db.getTrack(trackId);

    setDuration(t->duration);
    playingId=t->trackId;



    // player1->play();
}

void JAudio::pause()
{



    player1->pause();
}

void JAudio::setVolume(double volume)
{

    player1->setVolume(volume);

}

void JAudio::setPrefVolMax(double volume)
{

    int vol=static_cast<int>(volume);

    QSettings settings("AfrikTek","Qplayer");
    settings.setValue("volume",vol);
    setPrefferedVolume(vol);
}

void JAudio::seek(int newPosition)
{
    player1->setPosition(newPosition);

}

void JAudio::resume()
{
    player1->play();
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
    switch (error) {
    case QMediaPlayer::NoError:
        break;
    case QMediaPlayer::FormatError:
        break;
    case QMediaPlayer::NetworkError:
        break;
    case QMediaPlayer::AccessDeniedError:
        break;
    case QMediaPlayer::ServiceMissingError:
        break;
    case QMediaPlayer::MediaIsPlaylist:
        break;

    case QMediaPlayer::ResourceError:
        qDebug()<<"Error "<<player1->errorString();
        break;

    }

    setMediaFinished(true);
}

void JAudio::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    switch (status) {
    case QMediaPlayer::UnknownMediaStatus:
        qDebug()<<"Unknown Media";
        break;
    case QMediaPlayer::NoMedia:
        qDebug()<<"No media";
        break;
    case QMediaPlayer::LoadingMedia:
        qDebug()<<"Loading";
        break;
    case QMediaPlayer::LoadedMedia:

        setMediaFinished(false);
        player1->play();

        break;
    case QMediaPlayer::StalledMedia:
        qDebug()<<"Stalled";
        break;
    case QMediaPlayer::BufferingMedia:
        qDebug()<<"Bufferring";
        break;
    case QMediaPlayer::BufferedMedia:
        qDebug()<<"Buffered";
        break;
    case QMediaPlayer::EndOfMedia:
        setMediaFinished(true);
        break;
    case QMediaPlayer::InvalidMedia:
        setMediaFinished(false);
        qDebug()<<"Invalid";
        break;

    }
}

void JAudio::onPlaybackStatusChanged(QMediaPlayer::State state)
{
    switch (state) {
    case QMediaPlayer::StoppedState:
        setIsPlaying(false);
        setPlaybackStatus(1);
        break;
    case QMediaPlayer::PlayingState:
        setIsPlaying(true);
        setPlaybackStatus(0);
        break;
    case QMediaPlayer::PausedState:
        setIsPlaying(false);
        setPlaybackStatus(2);
        break;

    }
}

int JAudio::getPrefferedVolume() const
{
    return prefferedVolume;
}

void JAudio::setPrefferedVolume(int newPrefferedVolume)
{
    if (prefferedVolume == newPrefferedVolume)
        return;
    prefferedVolume = newPrefferedVolume;
    emit prefferedVolumeChanged();
}

bool JAudio::getMediaFinished() const
{
    return mediaFinished;
}

void JAudio::setMediaFinished(bool newMediaFinished)
{
    if (mediaFinished == newMediaFinished)
        return;
    mediaFinished = newMediaFinished;
    emit mediaFinishedChanged();
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
    setVolume(newPlayerVolume);
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
