#ifndef PLAYERGIMAGEPROVIDER_H
#define PLAYERGIMAGEPROVIDER_H

#include <QQuickImageProvider>


class PlayerGImageProvider : public QQuickImageProvider
{
public:
    PlayerGImageProvider();


    // QQuickImageProvider interface
public:
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
};

#endif // PLAYERGIMAGEPROVIDER_H
