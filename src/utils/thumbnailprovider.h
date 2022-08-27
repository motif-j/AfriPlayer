#ifndef THUMBNAILPROVIDER_H
#define THUMBNAILPROVIDER_H
#include <QQuickImageProvider>
#include <QDebug>




#include "../database/db_jmalkiadbinterface.h"
#include <src/utils/jsettings.h>
#include <src/utils/metadatamanager.h>

class ThumbnailProvider: public QQuickImageProvider
{
public:
    ThumbnailProvider();

    // QQuickImageProvider interface
public:
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
private:
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

};

#endif // THUMBNAILPROVIDER_H
