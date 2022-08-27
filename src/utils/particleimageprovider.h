#ifndef PARTICLEIMAGEPROVIDER_H
#define PARTICLEIMAGEPROVIDER_H

#include <QQuickImageProvider>

class ParticleImageProvider : public QQuickImageProvider
{
public:
    ParticleImageProvider();


    // QQuickImageProvider interface
public:
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
};

#endif // PARTICLEIMAGEPROVIDER_H
