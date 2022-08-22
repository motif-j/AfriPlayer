#include "jsettings.h"

JSettings::JSettings(QObject *parent)
    : QObject{parent}
{

    settings=new QSettings("AfrikTek","AfriMuzik");
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
