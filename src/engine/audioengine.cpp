#include "audioengine.h"


AudioEngine::AudioEngine(QObject *parent)
    : QObject{parent}
{


    vlcInstance=new VlcInstance(VlcCommon::args(),this);
    player1=new VlcMediaPlayer(vlcInstance);
    player2=new VlcMediaPlayer(vlcInstance);

    audio1=player1->audio();
    audio2=player2->audio();


    faderAnim=new QVariantAnimation(this);
    faderAnim->setDuration(1000);
    faderAnim->setStartValue(0);
    faderAnim->setEndValue(appSettings.getVolume());


    connect(faderAnim,&QVariantAnimation::valueChanged,this,&AudioEngine::onFaderValueChanged);
    connect(faderAnim,&QVariantAnimation::finished,this,&AudioEngine::onFaderFinished);


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

    if(activePlayerState==PLAYER1){


        audio1->setVolume(volume);
    }else{

        audio2->setVolume(volume);
    }



}

void AudioEngine::play()
{


    if(activeMedia1==nullptr || locked || activePlayer()==nullptr)
        return;

    fadeVolume();

    activePlayer()->play();
}

void AudioEngine::resume()
{
    if(locked ){
        return;
    }
    antState=STATE_WILLSTART;
    fadeVolume();

    activePlayer()->resume();
}

void AudioEngine::pause()

{
    if(locked ){
        return;
    }

    antState=STATE_WILLPAUSE;
    fadeVolume();

}

void AudioEngine::seek(int time)
{


    if(locked){
        return;
    }

    activePlayer()->pause();
    activePlayer()->setTime(time);
    activePlayer()->play();
}

int AudioEngine::trackLength()
{
    if(activePlayer()==nullptr){
        return 0;
    }

    return activePlayer()->length();
}

bool AudioEngine::crossFade()
{
    return appSettings.getCrossfade();
}

void AudioEngine::fadeVolume(int duration )
{
    locked=true;
    emit lockedChanged(true);


    faderAnim->setDuration(duration);
    faderAnim->setStartValue(0);
    faderAnim->setEndValue(appSettings.getVolume());
    faderAnim->start();

}



VlcMediaPlayer *AudioEngine::activePlayer()
{
    if(activePlayerState==PLAYER1){
        return player1;
    }

    return player2;
}

VlcAudio *AudioEngine::activeAudio()
{
    if(activePlayerState==PLAYER2){

        return audio2;
    }

    return audio1;
}

VlcMedia *AudioEngine::activeMedia()
{

    if(activePlayerState==PLAYER2){
        return activeMedia2;
    }

    return activeMedia1;
}

void AudioEngine::initialiazeListeners(VlcMediaPlayer *player)
{

    qDebug()<<"INITIALIZING LISTENERS "<<activePlayerState;


    connect(player,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
    //connect(player,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
    connect(player,&VlcMediaPlayer::error,this,&AudioEngine::onError);
    connect(player,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
    connect(player,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);
    connect(player,&VlcMediaPlayer::positionChanged,this,&AudioEngine::onPositionChanged);

}

void AudioEngine::disconnectListeners(VlcMediaPlayer *player)
{
    qDebug()<<"DISCONNECTING  "<<activePlayerState;
    disconnect(player,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
    //disconnect(player,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
    disconnect(player,&VlcMediaPlayer::error,this,&AudioEngine::onError);
    disconnect(player,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
    disconnect(player,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);
    disconnect(player,&VlcMediaPlayer::positionChanged,this,&AudioEngine::onPositionChanged);
}



void AudioEngine::loadAudio(QString fileUrl)
{


    if(locked){
        return;
    }

    switch (activePlayerState) {
    case AudioEngine::PLAYER1:
    {
        activePlayerState=PLAYER2;
        disconnectListeners(player1);

        initialiazeListeners(player2);


        activeMedia2=new VlcMedia(fileUrl,true,vlcInstance);
        player2->openOnly(activeMedia2);

        player2->play();
    }
        break;
    case AudioEngine::PLAYER2:

    {
        disconnectListeners(player2);
        activePlayerState=PLAYER1;


        initialiazeListeners(player1);

        activeMedia1=new VlcMedia(fileUrl,true,vlcInstance);
        player1->openOnly(activeMedia1);

        player1->play();
    }
        break;
    case AudioEngine::PLAYER_NONE:
    {
        //This state means there is no player currently running so we can initialize any of the available
        disconnectListeners(player2);

        activePlayerState=PLAYER1;

        initialiazeListeners(player1);


        activeMedia1=new VlcMedia(fileUrl,true,vlcInstance);
        player1->openOnly(activeMedia1);

        player1->play();
    }
        break;

    }


    antState=STATE_WILLLOAD;

    fadeVolume();




}

void AudioEngine::onMediaEnded()
{


}

void AudioEngine::onBuffer(float valuePercent)
{

}

void AudioEngine::onError()
{
    qDebug()<<"Error ";
}

void AudioEngine::onPlaying()
{
    int volume=appSettings.getVolume();


    setVolume(volume);

}

void AudioEngine::onStateChanged()
{
    playerState=activePlayer()->state();


    if(playerState==Vlc::State::Error){
        qDebug()<<"Error ";
    }
    emit playbackStateChanged(playerState);


}

void AudioEngine::onPositionChanged(float position)
{


    emit positionChanged(position,activePlayer()->time());


}

void AudioEngine::onFaderValueChanged(const QVariant &value)
{

    /*
       * There are two scenarios here:
       * 1. When there are 2 active players- i.e STATEWILL LOAD
       *    Change the volumes separately for each player
       * 2. When there is only one active player i.e STATEWILL PAUSE
       *    Set main volume directly
       *
      */

    int maxVolume=appSettings.getVolume();
    int incrVal=value.toInt();
    int decVal= std::abs(maxVolume-incrVal);



    switch (antState) {
    case AudioEngine::STATE_WILLSTART:
        setVolume(incrVal);
        break;
    case AudioEngine::STATE_NOTHING:
    {

    }
        break;
    case AudioEngine::STATE_WILLLOAD:
    {
        //to realize  the fade effect increment the volume by a slighter margin



        if(activePlayerState==PLAYER1){


            audio1->setVolume(incrVal);

            audio2->setVolume(decVal);

            //            }

        }else{


            audio2->setVolume(incrVal);

            audio1->setVolume(decVal);


        }


    }
        break;
    case AudioEngine::STATE_WILLPAUSE:
    {

        setVolume(decVal);
    }
        break;

    }



}

void AudioEngine::onFaderFinished()
{
    switch (antState) {
    case AudioEngine::STATE_WILLSTART:

        break;
    case AudioEngine::STATE_NOTHING:
        qDebug()<<"Just chilling ";
        break;
    case AudioEngine::STATE_WILLLOAD:
    {
        if(activePlayerState==PLAYER1){

            player2->stop();

        }else{
            player1->stop();
        }


    }
        break;
    case AudioEngine::STATE_WILLPAUSE:
    {


        activePlayer()->pause();


    }
        break;

    }

    locked=false;
    lockedChanged(false);
}
