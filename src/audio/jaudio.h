#ifndef JAUDIO_H
#define JAUDIO_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include "src/database/db_jmalkiadbinterface.h"
#include <QDebug>
#include <QTime>

#include "src/utils/jsettings.h"

#include "src/engine/audioengine.h"
#include <src/controllers/jplaylistcontroller.h>
#include <QVariant>





extern QString formatTrackTime(QTime);

class JAudio : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QString timeElapsed READ getTimeElapsed WRITE setTimeElapsed NOTIFY timeElapsedChanged)
    Q_PROPERTY(int duration READ getDuration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(bool isPlaying READ getIsPlaying WRITE setIsPlaying NOTIFY isPlayingChanged)
    Q_PROPERTY(bool canPlay READ getCanPlay WRITE setCanPlay NOTIFY canPlayChanged)
    Q_PROPERTY(int playerVolume READ getPlayerVolume WRITE setPlayerVolume NOTIFY playerVolumeChanged)
    Q_PROPERTY(int playingId READ getPlayingId WRITE setPlayingId NOTIFY playingIdChanged)
    Q_PROPERTY(int playbackStatus READ getPlaybackStatus WRITE setPlaybackStatus NOTIFY playbackStatusChanged)
    Q_PROPERTY(int playNext READ getPlayNext WRITE setPlayNext NOTIFY playNextChanged)
    Q_PROPERTY(QVariant playingTrackVar READ getPlayingTrackVar WRITE setPlayingTrackVar NOTIFY playingTrackVarChanged)


    Q_PROPERTY(QString trackLength READ getTrackLength WRITE setTrackLength NOTIFY trackLengthChanged)
public:
    explicit JAudio(QObject *parent = nullptr);



    int getPosition() const;
    void setPosition(int newPosition);

    const QString &getTimeElapsed() const;
    void setTimeElapsed(const QString &newTimeElapsed);

    int getDuration() const;
    void setDuration(int newDuration);

    bool getIsPlaying() const;
    void setIsPlaying(bool newIsPlaying);

    bool getCanPlay() const;
    void setCanPlay(bool newCanPlay);

    int getPlayerVolume() const;
    void setPlayerVolume(int newPlayerVolume);

    int getPlayingId() const;
    void setPlayingId(int newPlayingId);

    int getPlaybackStatus() const;
    void setPlaybackStatus(int newPlaybackStatus);


    int getPlayNext() const;
    void setPlayNext(int newPlayNext);

    const QString &getTrackLength() const;
    void setTrackLength(const QString &newTrackLength);

    const QVariant &getPlayingTrackVar() const;
    void setPlayingTrackVar(const QVariant &newPlayingTrackVar);

public slots:
    void pause();
    void setVolume(double volume);
    void seek(int newPosition);
    void resume();

public slots:
    void onPositionChanged(float,int);
    void onError(QMediaPlayer::Error error);
    void onPlaybackStatusChanged(AudioEngine::PlayerState state);
    void onEngineLockedChanged(bool locked);
    void onPlaylistPlaybackStarted(JTrack track);
    void onTrackAddedToPlaylist(JTrack track);




private:

    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();
    AudioEngine &playerEngine=AudioEngine::getInstance();
    JSettings &appSettings=JSettings::getInstance();
    JPlaylistController &playlistController=JPlaylistController::getInstance();
    MainWorker &worker=MainWorker::getInstance();


    int position=0;
    int duration=0;


    int playingId=0;
    int playerVolume=0;
    bool isPlaying=false;
    int playbackStatus; //0=playing;1=stopped;2;paused
    bool canPlay=true;
    int playNext=0;

    QString timeElapsed="00:00";
    QString trackLength="00:00";
    QVariant playingTrackVar;
    JTrack ptrack;


private:
    void reloadTrack(JTrack t);
    QString *getFormattedTime(int time);




signals:

    void positionChanged();
    void timeElapsedChanged();
    void durationChanged();

    void isPlayingChanged();
    void canPlayChanged();
    void playerVolumeChanged();
    void playingIdChanged();
    void playbackStatusChanged();

    void playNextChanged();
    void trackLengthChanged();
    void playingTrackVarChanged();
};

#endif // JAUDIO_H
