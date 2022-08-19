#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantAnimation>
#include <VLCQtCore/Audio.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Enums.h>
#include <VLCQtCore/Media.h>
#include "src/utils/jsettings.h"

class AudioEngine : public QObject
{
    Q_OBJECT
public:
    explicit AudioEngine(QObject *parent = nullptr);

    ~AudioEngine();


private:
    VlcInstance *vlcInstance;
    VlcMediaPlayer *player1;
    VlcAudio *audio=nullptr;
    VlcMedia *activeMedia;
    Vlc::State playerState;
    QVariantAnimation *faderAnim;

    JSettings &appSettings=JSettings::getInstance();

    bool locked=false;
    int maxVolume=appSettings.getVolume();

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

private:
    void fadeOutPlayer();
    void fadeInPlayer();


    //Receivers
private  slots:
    void  onMediaEnded();
    void onBuffer(float valuePercent);
    void onError();
    void onPlaying();
    void onStateChanged();
    void onFaderValueChanged(const QVariant &value);
    void  onFaderFinished();

private:


signals:
    void playbackStateChanged(Vlc::State playbackState);
    void lockedChanged(bool locked);

};

#endif // AUDIOENGINE_H
