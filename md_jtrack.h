#ifndef JTRACK_H
#define JTRACK_H

#include <QObject>
#include <QString>


class JTrack : public QObject
{
    Q_OBJECT
public:
    explicit JTrack(QObject *parent = nullptr){
        Q_UNUSED(parent);
    }

    int getTrackId() const;
    void setTrackId(int newTrackId);
    int getArtistId() const;
    void setArtistId(int newArtistId);
    int getAlbumId() const;
    void setAlbumId(int newAlbumId);
    long getDuration() const;
    void setDuration(long newDuration);
    const QString &getTrackName() const;
    void setTrackName(const QString &newTrackName);
    const QString &getFileUrl() const;
    void setFileUrl(const QString &newFileUrl);

private:
    int trackId;
    int artistId;
    int albumId;
    long duration;

    QString trackName;
    QString fileUrl;

signals:

};

#endif // JTRACK_H
