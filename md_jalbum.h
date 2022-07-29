#ifndef JALBUM_H
#define JALBUM_H

#include <QObject>
#include <QString>

class JAlbum : public QObject
{
    Q_OBJECT
public:
    explicit JAlbum(QObject *parent = nullptr);

    int getAlbumId() const;
    void setAlbumId(int newAlbumId);
    const QString &getAlbumName() const;
    void setAlbumName(const QString &newAlbumName);

private:
    int albumId;
    QString albumName;


signals:

};

#endif // JALBUM_H
