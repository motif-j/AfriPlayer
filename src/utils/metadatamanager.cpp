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
