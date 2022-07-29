#include "md_jartist.h"



JArtist::JArtist()
{

}

int JArtist::getArtistId() const
{
    return artistId;
}

void JArtist::setArtistId(int newArtistId)
{
    artistId = newArtistId;
}

const QString &JArtist::getArtistTitle() const
{
    return artistTitle;
}

void JArtist::setArtistTitle(const QString &newArtistTitle)
{
    artistTitle = newArtistTitle;
}
