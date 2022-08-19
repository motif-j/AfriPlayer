#include "jsettings.h"

JSettings::JSettings(QObject *parent)
    : QObject{parent}
{

    settings=new QSettings("AfrikTek","AfriMuzik");
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
