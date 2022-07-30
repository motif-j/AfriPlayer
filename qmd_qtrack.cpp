#include "qmd_qtrack.h"

QTrack::QTrack(QObject *parent)
    : QObject{parent}
{

}

const QString &QTrack::getTrackName() const
{
    return trackName;
}

void QTrack::setTrackName(const QString &newTrackName)
{
    if (trackName == newTrackName)
        return;
    trackName = newTrackName;
    emit trackNameChanged();
}
