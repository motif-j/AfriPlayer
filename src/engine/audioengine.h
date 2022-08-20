#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantAnimation>
#include <VLCQtCore/Audio.h>
#include <VLCQtCore/Video.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Enums.h>
#include <VLCQtCore/Media.h>
#include "src/utils/jsettings.h"
#include <math.h>

class AudioEngine : public QObject
{
    Q_OBJECT
public:
    explicit AudioEngine(QObject *parent = nullptr);

    ~AudioEngine();

    enum AnticipatedState
    {
        STATE_NOTHING=0,
        STATE_WILLLOAD=1,
        STATE_WILLPAUSE=2,
        STATE_WILLSTART=3

    };

    enum ActivePlayer{
        PLAYER1=1,
        PLAYER2=2,
        PLAYER_NONE=3
    };

private:
    VlcInstance *vlcInstance;

    VlcMediaPlayer *player1=nullptr;
    VlcMediaPlayer *player2=nullptr;


    VlcAudio *audio1=nullptr;
    VlcAudio *audio2=nullptr;

    VlcMedia *activeMedia1;
    VlcMedia *activeMedia2;

    Vlc::State playerState;
    QVariantAnimation *faderAnim;

    JSettings &appSettings=JSettings::getInstance();
    AnticipatedState antState=STATE_WILLPAUSE;
    ActivePlayer activePlayerState=PLAYER_NONE;

    bool locked=false;
    int maxVolume=appSettings.getVolume();
    QString fileUrl;

    //getters
public:
    Vlc::State getPlayerState() const;

    //functions
public:
    void setVolume(int volume);
    void loadAudio(QString fileUrl);
    void play();
    void resume();
    void pause();

    void seek(int time);

    int trackLength();
private:
    void fadeVolume();


    VlcMediaPlayer *activePlayer();
    VlcAudio *activeAudio();

    VlcMedia *activeMedia();
    void initialiazeListeners(VlcMediaPlayer *player);
    void disconnectListeners(VlcMediaPlayer *player);

    //Receivers
private  slots:
    void  onMediaEnded();
    void onBuffer(float valuePercent);
    void onError();
    void onPlaying();
    void onStateChanged();
    void onPositionChanged(float position);

    void onFaderValueChanged(const QVariant &value);
    void  onFaderFinished();

private:


signals:
    void playbackStateChanged(Vlc::State playbackState);
    void lockedChanged(bool locked);
    void positionChanged(float position,int time);

};

#endif // AUDIOENGINE_H
