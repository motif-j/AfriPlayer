#ifndef JAUDIO_H
#define JAUDIO_H

#include <QObject>
#include <QMediaPlayer>
#include <QString>
#include "src/database/db_jmalkiadbinterface.h"
#include <QDebug>
#include <QTime>
#include <QPropertyAnimation>
#include <QSettings>

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
    Q_PROPERTY(bool mediaFinished READ getMediaFinished WRITE setMediaFinished NOTIFY mediaFinishedChanged)
    Q_PROPERTY(int prefferedVolume READ getPrefferedVolume WRITE setPrefferedVolume NOTIFY prefferedVolumeChanged)


public:
    explicit JAudio(QObject *parent = nullptr);

    QMediaPlayer *player1;

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

    bool getMediaFinished() const;
    void setMediaFinished(bool newMediaFinished);

    int getPrefferedVolume() const;
    void setPrefferedVolume(int newPrefferedVolume);

public slots:
    void play(QString fileUrl,int trackId);
    void pause();
    void setVolume(double volume);
    void setPrefVolMax(double volume);

    void seek(int newPosition);
    void resume();

public slots:
    void onPositionChanged(qint64);
    void onError(QMediaPlayer::Error error);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onPlaybackStatusChanged(QMediaPlayer::State state);

private:
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

    int position=0;
    int duration=0;

    int prefferedVolume=20;

    int playingId;
    int playerVolume;
    bool isPlaying=false;
    bool mediaFinished;
    int playbackStatus; //0=playing;1=stopped;2;paused
    bool canPlay=false;

    QString timeElapsed;


signals:

    void positionChanged();
    void timeElapsedChanged();
    void durationChanged();

    void isPlayingChanged();
    void canPlayChanged();
    void playerVolumeChanged();
    void playingIdChanged();
    void playbackStatusChanged();
    void mediaFinishedChanged();
    void prefferedVolumeChanged();
};

#endif // JAUDIO_H
