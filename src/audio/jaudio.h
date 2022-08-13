#ifndef JAUDIO_H
#define JAUDIO_H

#include <QObject>

class JAudio : public QObject
{
    Q_OBJECT
public:
    explicit JAudio(QObject *parent = nullptr);

signals:

};

#endif // JAUDIO_H
