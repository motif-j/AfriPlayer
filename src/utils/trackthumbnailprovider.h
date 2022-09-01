#ifndef TRACKTHUMBNAILPROVIDER_H
#define TRACKTHUMBNAILPROVIDER_H

#include <QQuickImageProvider>

class TrackThumbnailProvider : public QQuickImageProvider
{
public:
    TrackThumbnailProvider();


    // QQuickImageProvider interface


public:
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
};

#endif // TRACKTHUMBNAILPROVIDER_H
