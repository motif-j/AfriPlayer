#include "audioengine.h"

#ifdef Q_OS_ANDROID


AudioEngine::AudioEngine(QObject *parent)
    : QObject{parent}
{

    qDebug()<<"Initializing Engine Android ";
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
    //delete vlcInstance;
}

AudioEngine::PlayerState AudioEngine::getPlayerState() const
{
    return playerState;
}

void AudioEngine::setVolume(int volume)
{


qDebug()<<"Set Volume andoid ";

}

void AudioEngine::play()
{


    if( locked )
        return;

    fadeVolume();

    qDebug()<<"Play Android";
   // activePlayer()->play();
}

void AudioEngine::resume()
{
    if(locked ){
        return;
    }
    antState=STATE_WILLSTART;
    fadeVolume();

   // activePlayer()->resume();
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

 //   activePlayer()->pause();
   // activePlayer()->setTime(time);
    //activePlayer()->play();

}

int AudioEngine::trackLength()
{

     //return activePlayer()->length();
return 0;

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



int *AudioEngine::activePlayer()
{
//    if(activePlayerState==PLAYER1){
//        return player1;
//    }

    return 0;//player2;
}

//void AudioEngine::initialiazeListeners(VlcMediaPlayer *player)
//{
//    qDebug()<<"INITIALIZING LISTENERS "<<activePlayerState;


//    connect(player,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
//    //connect(player,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
//    connect(player,&VlcMediaPlayer::error,this,&AudioEngine::onError);
//    connect(player,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
//    connect(player,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);
//    connect(player,&VlcMediaPlayer::positionChanged,this,&AudioEngine::onPositionChanged);



//}

//void AudioEngine::disconnectListeners(VlcMediaPlayer *player)
//{


//    qDebug()<<"DISCONNECTING  "<<activePlayerState;
//    disconnect(player,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
//    //disconnect(player,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
//    disconnect(player,&VlcMediaPlayer::error,this,&AudioEngine::onError);
//    disconnect(player,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
//    disconnect(player,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);
//    disconnect(player,&VlcMediaPlayer::positionChanged,this,&AudioEngine::onPositionChanged);

//}



void AudioEngine::loadAudio(QString fileUrl)
{



    if(locked){
        qDebug("Engine locked");
        return;
    }

    switch (activePlayerState) {
    case AudioEngine::PLAYER1:
    {

    }
        break;
    case AudioEngine::PLAYER2:

    {

    }
        break;
    case AudioEngine::PLAYER_NONE:
    {
        //This state means there is no player currently running so we can initialize any of the available

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
{/*
    switch (activePlayer()->state()) {
    case Vlc::Idle:
    {
     playerState=AudioEngine::Idle;
    }
        break;
    case Vlc::Opening:
    {
     playerState=AudioEngine::Opening;
    }
        break;
    case Vlc::Buffering:
    {
     playerState=AudioEngine::Buffering;
    }
        break;
    case Vlc::Playing:
    {
     playerState=AudioEngine::Playing;
    }
        break;
    case Vlc::Paused:
    {
     playerState=AudioEngine::Paused;
    }
        break;
    case Vlc::Stopped:
    {
     playerState=AudioEngine::Stopped;
    }
        break;
    case Vlc::Ended:
    {
     playerState=AudioEngine::Ended;
    }
        break;
    case Vlc::Error:
    {
     playerState=AudioEngine::Error;
    }
        break;

    }

*/

    emit playbackStateChanged(playerState);


}

void AudioEngine::onPositionChanged(float position)
{


    emit positionChanged(position,0);


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



            //            }

        }else{


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

      //player2->stop();


        }else{
      //player1->stop();


        }


    }
        break;
    case AudioEngine::STATE_WILLPAUSE:
    {


        //activePlayer()->pause();


    }
        break;

    }

    locked=false;
    lockedChanged(false);
}

#endif
