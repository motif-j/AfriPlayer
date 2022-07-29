#include "md_jtrack.h"



int JTrack::getTrackId() const
{
    return trackId;
}

void JTrack::setTrackId(int newTrackId)
{
    trackId = newTrackId;
}

int JTrack::getArtistId() const
{
    return artistId;
}

void JTrack::setArtistId(int newArtistId)
{
    artistId = newArtistId;
}

int JTrack::getAlbumId() const
{
    return albumId;
}

void JTrack::setAlbumId(int newAlbumId)
{
    albumId = newAlbumId;
}

long JTrack::getDuration() const
{
    return duration;
}

void JTrack::setDuration(long newDuration)
{
    duration = newDuration;
}

const QString &JTrack::getTrackName() const
{
    return trackName;
}

void JTrack::setTrackName(const QString &newTrackName)
{
    trackName = newTrackName;
}

const QString &JTrack::getFileUrl() const
{
    return fileUrl;
}

void JTrack::setFileUrl(const QString &newFileUrl)
{
    fileUrl = newFileUrl;
}
