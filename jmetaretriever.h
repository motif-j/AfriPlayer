#ifndef JMETARETRIEVER_H
#define JMETARETRIEVER_H

#include "taglib/taglib.h"
#include <taglib/fileref.h>
#include <taglib/tfile.h>
#include <taglib/tag.h>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/attachedpictureframe.h>

#include <QMediaPlayer>
#include <QObject>
#include <QDebug>

class JMetaRetriever : public QObject
{
    Q_OBJECT
public:
    explicit JMetaRetriever(QObject *parent = nullptr);

public slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:

    QMediaPlayer *metaPlayer;

private:
    void init();
signals:

};

#endif // JMETARETRIEVER_H
