#ifndef QTRACK_H
#define QTRACK_H

#include <QObject>
#include <QString>

class QTrack : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString trackName READ getTrackName WRITE setTrackName NOTIFY trackNameChanged)

   // QML_ELEMENT;
public:
    explicit QTrack(QObject *parent = nullptr);

    const QString &getTrackName() const;
    void setTrackName(const QString &newTrackName);

private:
    QString trackName;



signals:

    void trackNameChanged();
};

#endif // QTRACK_H
