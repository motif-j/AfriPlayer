#include "thumbnailprovider.h"

#include <QPainter>
#include <math.h>



ThumbnailProvider::ThumbnailProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap ThumbnailProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{


    int width = 100;
    int height = 100;

    int pWidth=requestedSize.width() > 0 ? requestedSize.width() : width;
    int pHeight=requestedSize.height() > 0 ? requestedSize.height() : height;

    if (size)
        *size = QSize(width, height);
    QPixmap pixmap(pWidth,pHeight);




    if(id=="00"){
        QUrl *url= new  QUrl("assets/cover.png");
        pixmap.load(url->path());
        return pixmap;
    }
    auto colorArray=id.split("-");



    QRadialGradient linearGradient(QPointF(pWidth/2,pHeight),pWidth*0.25);
    QPainter painter(&pixmap);
    //  QLinearGradient linearGradient(0,0,0,height);


    if(colorArray.isEmpty()){
        linearGradient.setColorAt(0,"#cc0000");
        linearGradient.setColorAt(1,"#007fff");
    }else{

        int index=1;
        for(QString color:colorArray){

            if(index==1){
                linearGradient.setColorAt(0,color);
            }else{

                double colorInd=(static_cast<double>(index)/static_cast<double>(colorArray.count()))*1.0;

                linearGradient.setColorAt(colorInd,color);

            }


            index++;

        }
    }
    linearGradient.setSpread(QGradient::RepeatSpread);

    painter.fillRect(QRect(0,0,pWidth,pHeight),linearGradient);





    return pixmap;
    //  }

    //   return MetaDataManager::getCoverImage(track->fileUrl,pixmap);

}
