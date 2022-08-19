#include "audioengine.h"


AudioEngine::AudioEngine(QObject *parent)
    : QObject{parent}
{



    vlcInstance=new VlcInstance(VlcCommon::args(),this);
    player1=new VlcMediaPlayer(vlcInstance);
    faderAnim=new QVariantAnimation(this);
    faderAnim->setDuration(2000);


    connect(faderAnim,&QVariantAnimation::valueChanged,this,&AudioEngine::onFaderValueChanged);
    connect(faderAnim,&QVariantAnimation::finished,this,&AudioEngine::onFaderFinished);


    connect(player1,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
    connect(player1,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
    connect(player1,&VlcMediaPlayer::error,this,&AudioEngine::onError);
    connect(player1,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
    connect(player1,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);

    //connect
}

AudioEngine::~AudioEngine()
{
    delete vlcInstance;
}

Vlc::State AudioEngine::getPlayerState() const
{
    return playerState;
}



void AudioEngine::setVolume(int volume)
{
    if(audio==nullptr)
    {
        qDebug()<<"NULL P";
        return;

    }
    audio->setVolume(volume);

}

void AudioEngine::play()
{

  //  fadeOutPlayer();

  if(activeMedia==nullptr || locked)
      return;

  fadeOutPlayer();

  player1->play();
}

void AudioEngine::resume()
{
    if(locked){
        return;
    }
    fadeOutPlayer();
    player1->resume();
}

void AudioEngine::pause()

{
    if(locked){
        return;
    }

    fadeInPlayer();
  //  player1->pause();


}

void AudioEngine::fadeOutPlayer()
{

    faderAnim->setStartValue(0);
    faderAnim->setEndValue(100);
    faderAnim->start();
    locked=true;
    emit lockedChanged(true);
}

void AudioEngine::fadeInPlayer()
{
    faderAnim->setStartValue(100);
    faderAnim->setEndValue(0);
    faderAnim->start();
    locked=true;
    emit lockedChanged(true);
}



void AudioEngine::loadAudio(QString fileUrl)
{
    if(locked){
        return;
    }

    activeMedia=nullptr;
    activeMedia=new VlcMedia(fileUrl,true,vlcInstance);
    player1->openOnly(activeMedia);


}

void AudioEngine::onMediaEnded()
{

}

void AudioEngine::onBuffer(float valuePercent)
{

}

void AudioEngine::onError()
{

}

void AudioEngine::onPlaying()
{
    qDebug()<<"Me is Playing";

}

void AudioEngine::onStateChanged()
{
    playerState=player1->state();

    switch (playerState) {
    case Vlc::Idle:
        break;
    case Vlc::Opening:
        break;
    case Vlc::Buffering:
        break;
    case Vlc::Playing:
    {

        //check if audio is initialized
        if(audio==nullptr){
            //initialize the audio when playback starts
            audio=player1->audio();
        }
    }
        break;
    case Vlc::Paused:
        break;
    case Vlc::Stopped:
        break;
    case Vlc::Ended:
        break;
    case Vlc::Error:
        break;

    }



    emit playbackStateChanged(playerState);


}

void AudioEngine::onFaderValueChanged(const QVariant &value)
{

    setVolume(value.toInt());

}

void AudioEngine::onFaderFinished()
{
    if(faderAnim->currentValue().toInt()==0){
        player1->pause();
    }
    locked=false;
    lockedChanged(false);
}
