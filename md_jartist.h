#ifndef JARTIST_H
#define JARTIST_H

#include <QObject>
#include <QString>

class JArtist : public QObject
{
    Q_OBJECT
public:
     JArtist();
     JArtist(QObject *parent = nullptr){
        Q_UNUSED(parent)
    }

    int getArtistId() const;
    void setArtistId(int newArtistId);
    const QString &getArtistTitle() const;
    void setArtistTitle(const QString &newArtistTitle);

private:
    int artistId;
    QString artistTitle;
signals:

};

#endif // JARTIST_H
