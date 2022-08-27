#ifndef JFILEWORKER_H
#define JFILEWORKER_H


#include <QDateTime>
#include <QDir>
#include <QDirIterator>
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent>
#include <QFuture>

#include "taglib/taglib.h"
#include <taglib/fileref.h>
#include <taglib/tfile.h>
#include <taglib/tag.h>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/attachedpictureframe.h>



#include <QDebug>
#include <string>
#include <wchar.h>
#include "../models/jmodels.h"
#include "../database/db_jmalkiadbinterface.h"
#include <src/utils/jsettings.h>

class JFileWorker : public QObject
{
    Q_OBJECT
public:
    static JFileWorker &getInstance(){
        static JFileWorker instance;

        return instance;
    }
private:
    JFileWorker(QObject *parent = nullptr);

private:
    QThreadPool *threadpool;
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();
    JSettings &settings=JSettings::getInstance();

public:
    QFuture<int> queryAllFiles();

signals:

};

#endif // JFILEWORKER_H
