#ifndef METADATAMANAGER_H
#define METADATAMANAGER_H


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

#include <QPixmap>
#include <QString>
#include <QFile>




class MetaDataManager
{
public:
    MetaDataManager();
    static QPixmap getCoverImage(QString fileName,QPixmap image);
};

#endif // METADATAMANAGER_H
