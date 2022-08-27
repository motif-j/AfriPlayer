#include "jsettings.h"

JSettings::JSettings(QObject *parent)
    : QObject{parent}
{

    settings=new QSettings("AfrikTek","AfriMuzik");
}

bool JSettings::getIsQuering() const
{
    bool nQuering=settings->value("isQuering",false).toBool();

    return nQuering;
}

void JSettings::setIsQuering(bool newIsQuering)
{
    isQuering = newIsQuering;
    settings->setValue("isQuering",isQuering);
}

bool JSettings::getShuffle() const
{
    bool nShuffle=settings->value("shuffle",false).toBool();

    return nShuffle;
}

void JSettings::setShuffle(bool newShuffle)
{
    shuffle = newShuffle;
    settings->setValue("shuffle",shuffle);
}

int JSettings::getPlayingTrackId() const
{
    int   playingTrackId=settings->value("playingTrackId",0).toInt();
    return playingTrackId;
}

void JSettings::setPlayingTrackId(int newPlayingTrackId)
{
    playingTrackId = newPlayingTrackId;
    settings->setValue("playingTrackId",newPlayingTrackId);
}

bool JSettings::getCrossfade() const
{
    bool nCrossfade=settings->value("crossfade",true).toBool();


    return nCrossfade;
}

void JSettings::setCrossfade(bool newCrossfade)
{
    crossfade = newCrossfade;

    settings->setValue("crossfade",crossfade);
}

int JSettings::getVolume() const
{
    int  nVol=settings->value("maxVolume",80).toInt();

    return nVol;
}

void JSettings::setVolume(int newVolume)
{
    volume = newVolume;
    settings->setValue("maxVolume",newVolume);
}
