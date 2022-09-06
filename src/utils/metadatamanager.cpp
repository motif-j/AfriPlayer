#include "metadatamanager.h"
#include <stdexcept>






MetaDataManager::MetaDataManager()
{

}

QPixmap MetaDataManager::getCoverImage(QString fileName,QPixmap image)
{


    QByteArray encodedName=QFile::encodeName(fileName);

    auto ptrName=encodedName.constData();

    try{
        TagLib::FileRef *file=new TagLib::FileRef(ptrName);
        qDebug("Initialized file ref ");


        TagLib::MPEG::File mpegFile(file->file()->name());
        if (mpegFile.isValid() == true || mpegFile.ID3v2Tag() != nullptr) {
            TagLib::ID3v2::Tag *tag = mpegFile.ID3v2Tag();
            const TagLib::ID3v2::FrameList frameList = tag->frameList("APIC");
            if (!frameList.isEmpty()) {
                TagLib::ID3v2::AttachedPictureFrame* picFrame;
                picFrame = dynamic_cast<TagLib::ID3v2::AttachedPictureFrame*>(frameList.front());
                if (picFrame != nullptr) {
                    QString cover = picFrame->mimeType().toCString();
                    if(!cover.isEmpty()){
                        //  QPixmap pixMap;
                        image.loadFromData(reinterpret_cast<const uchar *>(picFrame->picture().data()),picFrame->picture().size());


                        return image;
                        //emit signalMetaLoaded(metaList,pixMap);
                    }

                }

            }
        }
    }catch(...){

        return image;
    }




    return image;
}

JTrack MetaDataManager::retrieveMetaInfo(QFileInfo dirInfo)
{
    QDateTime *lastMd=new QDateTime(dirInfo.birthTime());

    QByteArray fileName=QFile::encodeName(dirInfo.absoluteFilePath());

    const char  *encodedName=fileName.constData();

    TagLib::FileRef *file=new TagLib::FileRef(encodedName);
     JTrack track;
    if(!file->isNull()){


        QString suffix=dirInfo.suffix();

        QString title=file->tag()->title().toCString(true);
        QString album =file->tag()->album().toCString(true);
        QString artistName=file->tag()->artist().toCString(true);
        QString fileUrl=dirInfo.absoluteFilePath();
        int releaseYear=file->tag()->year();


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
        track.releaseYear=releaseYear;
        track.dateAdded=lastMd->toMSecsSinceEpoch();

    }
     delete lastMd;

    return track;
}
