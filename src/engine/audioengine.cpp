#include "audioengine.h"


AudioEngine::AudioEngine(QObject *parent)
    : QObject{parent}
{




    vlcInstance=new VlcInstance(VlcCommon::args(),this);


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
    if(activeAudio()==nullptr)
    {
        qDebug()<<"NULL P";
        return;

    }

    activeAudio()->setVolume(volume);

}

void AudioEngine::play()
{

    //  fadeOutPlayer();

    if(activeMedia1==nullptr || locked || activePlayer()==nullptr)
        return;

    fadeVolume();

    activePlayer()->play();
}

void AudioEngine::resume()
{
    if(locked || activePlayer()==nullptr){
        return;
    }
    antState=STATE_WILLSTART;
    fadeVolume();
    activePlayer()->resume();
}

void AudioEngine::pause()

{
    if(locked || activePlayer()==nullptr){
        return;
    }

    antState=STATE_WILLPAUSE;
    fadeVolume();



}

void AudioEngine::seek(int time)
{
  if(activePlayer()==nullptr){
      return;
  }

  activePlayer()->setTime(time);
}

int AudioEngine::trackLength()
{
   if(activePlayer()==nullptr){
       return 0;
   }

   return activePlayer()->length();
}

void AudioEngine::fadeVolume()
{

    faderAnim->setStartValue(0);
    faderAnim->setEndValue(appSettings.getVolume());
    faderAnim->start();
    locked=true;
    emit lockedChanged(true);
}



VlcMediaPlayer *AudioEngine::activePlayer()
{
    if(player1==nullptr){
        return player2;
    }

    return player1;
}

VlcAudio *AudioEngine::activeAudio()
{
    if(audio1==nullptr){
        return audio2;
    }

    return audio1;
}

VlcMedia *AudioEngine::activeMedia()
{
    if(activeMedia1==nullptr){
        return activeMedia2;
    }

    return activeMedia1;
}

void AudioEngine::initialiazeListeners(VlcMediaPlayer *player)
{

    qDebug()<<"INITIALIZING LISTENERS";


    connect(player,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
    connect(player,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
    connect(player,&VlcMediaPlayer::error,this,&AudioEngine::onError);
    connect(player,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
    connect(player,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);
    connect(player,&VlcMediaPlayer::positionChanged,this,&AudioEngine::onPositionChanged);

}

void AudioEngine::disconnectListeners(VlcMediaPlayer *player)
{
    disconnect(player,&VlcMediaPlayer::end,this,&AudioEngine::onMediaEnded);
    disconnect(player,SIGNAL(VlcMediaPlayer::buffering(float)),this,SLOT(AudioEngine::onBuffer(float)));
    disconnect(player,&VlcMediaPlayer::error,this,&AudioEngine::onError);
    disconnect(player,&VlcMediaPlayer::playing,this,&AudioEngine::onPlaying);
    disconnect(player,&VlcMediaPlayer::stateChanged,this,&AudioEngine::onStateChanged);
    disconnect(player,&VlcMediaPlayer::positionChanged,this,&AudioEngine::onPositionChanged);
}



void AudioEngine::loadAudio(QString fileUrl)
{
    qDebug()<<"LOADING AUDIO ";

    if(locked){
        return;
    }

    if(playerState==Vlc::State::Playing){
        qDebug()<<"LOADING AUDIO STATE PLAYING";
        /*
         *This is a case where a player is still active and playing but we need to play another track
         *First we would need to fade in the active player and fade out the new player
         *To determine the active player we will use  the state
         *
         *Initialize the inactive player start it and fade other player
         *Since the active player might be playing its better to acces each player natively
        */

        if(activePlayerState==PLAYER1){

            qDebug()<<" active player is 1 so intialize 2 " ;

            if(player2!=nullptr){
                player2->stop();
                player2=nullptr;
            }

            player2=new VlcMediaPlayer(vlcInstance);
            audio2=player2->audio();

            if(player1!=nullptr){
                disconnectListeners(player1);
            }
            initialiazeListeners(player2);
            activePlayerState=PLAYER2;

            activeMedia2=new VlcMedia(fileUrl,true,vlcInstance);
            player2->openOnly(activeMedia2);

            player2->play();
        }else{
            qDebug()<<" active player is 2 so intialize 1 " ;
            if(player1!=nullptr){
                player1->stop();
                player1=nullptr;
            }
            player1=new VlcMediaPlayer(vlcInstance);
            audio1=player1->audio();
            activePlayerState=PLAYER1;

            if(player2!=nullptr){
                disconnectListeners(player2);
            }

            initialiazeListeners(player1);
            activeMedia1=new VlcMedia(fileUrl,true,vlcInstance);
            player1->openOnly(activeMedia1);

            player1->play();
        }

        //  initialiazeListeners();

        antState=STATE_WILLLOAD;


        //fadeVolume();
        this->fileUrl=fileUrl;

    }else{
        qDebug()<<"LOADING AUDIO STATE NOT PLAYING";
        antState=STATE_WILLSTART;


        if(activePlayer()==nullptr){
            qDebug()<<"ACTIVE PLAYER == null";
            /*
             * Initially all players will be nullptr so Initialize any of the  players
             *

            */
            player1=new VlcMediaPlayer(vlcInstance);
            player2=nullptr;

            activeMedia2=nullptr;

            activePlayerState=PLAYER1;

            if(player2!=nullptr){
                disconnectListeners(player2);
            }

            initialiazeListeners(player1);


            audio1=player1->audio();
            audio2=nullptr;


            activeMedia1=new VlcMedia(fileUrl,true,vlcInstance);
            activePlayer()->openOnly(activeMedia1);

            activePlayer()->play();
        }else{
            /*
             *The player is active so we need to initialize the null player and kill the other player
             *Since there is no active player we just need to start the player
             *
            */



            qDebug()<<" ACTIVE PLAYER NOT NULL ";

            if(activePlayer()==player1){


                activeMedia1=new VlcMedia(fileUrl,true,vlcInstance);

                activePlayerState=PLAYER1;



            }else{

                activePlayerState=PLAYER2;


                activeMedia2=new VlcMedia(fileUrl,true,vlcInstance);

            }



            initialiazeListeners(activePlayer());

            activePlayer()->openOnly(activeMedia());

            activePlayer()->play();



        }



    }

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
    playerState=player1->state();


    if(playerState==Vlc::State::Error){
         qDebug()<<"Error ";
    }
    emit playbackStateChanged(playerState);


}

void AudioEngine::onPositionChanged(float position)
{
    if(activePlayer()!=nullptr){



        emit positionChanged(position,activePlayer()->time());
    }

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

    int incrVal=value.toInt();
    int decVal= std::abs(appSettings.getVolume()-incrVal);



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
        //Here we need to set the player volumes individually


        if(activePlayerState==PLAYER1){
            // qDebug()<<"active player 1 volume "<<incrVal;
            if(audio1!=nullptr){

                //increase this volume
                audio1->setVolume(incrVal);
            }

            if(audio2!=nullptr){
                //decrease this volume
                audio2->setVolume(decVal);

            }

        }else{

            if(audio2!=nullptr){
                //increase this volume

                audio2->setVolume(incrVal);
            }

            if(audio1!=nullptr){
                //decrease this volume
                audio1->setVolume(decVal);

            }
            //qDebug()<<"ACTIVE PLAYER == 2 "<<vol;
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
            if(player2!=nullptr){
                player2->stop();
            }

            player2=nullptr;
            audio2=nullptr;
            activeMedia2=nullptr;
        }else{
            if(player1!=nullptr){
                player1->stop();
            }

            player1=nullptr;
            audio1=nullptr;
            activeMedia1=nullptr;
        }

        //initialiazeListeners();
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
