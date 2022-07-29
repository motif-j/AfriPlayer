#include "md_jalbum.h"

JAlbum::JAlbum(QObject *parent)
    : QObject{parent}
{

}

int JAlbum::getAlbumId() const
{
    return albumId;
}

void JAlbum::setAlbumId(int newAlbumId)
{
    albumId = newAlbumId;
}

const QString &JAlbum::getAlbumName() const
{
    return albumName;
}

void JAlbum::setAlbumName(const QString &newAlbumName)
{
    albumName = newAlbumName;
}
