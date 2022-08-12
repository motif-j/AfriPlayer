#ifndef FILE_FILEWORKER_H
#define FILE_FILEWORKER_H

#include <QDir>
#include <QDirIterator>
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QThread>
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
#include "jmodels.h"
#include "db_jmalkiadbinterface.h"

class FilWorker : public QObject
{
    Q_OBJECT
public:
    FilWorker(QObject *parent=nullptr) {
        Q_UNUSED(parent)
    }



public slots:

    void queryAllDirectories(QDir directory){

        // QThread::msleep(10000);

        if(!directory.exists()){
            return;
        }
        QStringList filters;
        filters<<"*.m4a"<<"*.mp3"<<"*.wav"<<"*aac"<<"*.flac"<<"*.ogg";

        directory.setNameFilters(filters);

        QFileInfoList dirList=directory.entryInfoList();


        QDirIterator dirIterator(directory,QDirIterator::Subdirectories);

        while(dirIterator.hasNext()){

            auto dirEntryPath=dirIterator.next();

            QFileInfo dirInfo(dirEntryPath);


            if(dirInfo.isFile()){
                QString path=dirInfo.path();

                QByteArray fileName=QFile::encodeName(path.append("\\").append(dirInfo.fileName()));

                const char  *encodedName=fileName.constData();



                TagLib::FileRef *file=new TagLib::FileRef(encodedName);

                if(!file->isNull()){

                    JTrack track;
                    QString suffix=dirInfo.suffix();

                    QString title=file->tag()->title().toCString();
                    QString album =file->tag()->album().toCString();
                    QString artistName=file->tag()->artist().toCString();
                    QString fileUrl=path.append("\\").append(dirInfo.fileName());

                    long long duration=file->audioProperties()->lengthInMilliseconds();

                    if(title.isEmpty()){
                        title=dirInfo.fileName();
                    }

                    if(album.isEmpty()){
                        album="Unknown Album";
                    }

                    if(artistName.isEmpty()){
                        artistName="Unknown Artist";
                    }

                    track.trackName=title.simplified();
                    track.albumName=album.simplified();
                    track.duration=duration;
                    track.fileUrl=fileUrl.trimmed();
                    track.artistName=artistName.simplified();



                    db.addNewTrack(track);


                    //                   TagLib::MPEG::File mpegFile(file->file()->name());
                    //                       if (mpegFile.isValid() == true || mpegFile.ID3v2Tag() != nullptr) {
                    //                           TagLib::ID3v2::Tag *tag = mpegFile.ID3v2Tag();
                    //                           const TagLib::ID3v2::FrameList frameList = tag->frameList("APIC");
                    //                           if (!frameList.isEmpty()) {
                    //                               TagLib::ID3v2::AttachedPictureFrame* picFrame;
                    //                               picFrame = dynamic_cast<TagLib::ID3v2::AttachedPictureFrame*>(frameList.front());
                    //                               if (picFrame != nullptr) {
                    //                                   QString cover = picFrame->mimeType().toCString();
                    //                                   if(!cover.isEmpty()){
                    //                                       QPixmap pixMap;
                    //                                       pixMap.loadFromData(reinterpret_cast<const uchar *>(picFrame->picture().data()),picFrame->picture().size());
                    //                                       //emit signalMetaLoaded(metaList,pixMap);
                    //                                   }
                    //                               }
                    //                           }else{
                    //                               QPixmap pixMap(":/data/noCover.png");
                    //                             //  emit signalMetaLoaded(metaList,pixMap);
                    //                           }
                    //                       }
                }




            }
        }



        emit queryAllDirCompleted();

    }

private:
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

signals:

    void queryAllDirCompleted();

};
#endif // FILE_FILEWORKER_H
