#include "playergimageprovider.h"

#include <QPainter>
#include <QRadialGradient>

PlayerGImageProvider::PlayerGImageProvider()
    :QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap PlayerGImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
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



    QRadialGradient gradient(QPointF(pWidth/2,pHeight),pWidth*0.25);
    QPainter painter(&pixmap);
    //  QLinearGradient linearGradient(0,0,0,height);
    if(colorArray.isEmpty()){
        gradient.setColorAt(0,"#cc0000");
        gradient.setColorAt(1,"#007fff");
    }else{

        int index=1;
        for(QString color:colorArray){

            if(index==1){
                gradient.setColorAt(0,color);
            }else{
                double colorInd=(static_cast<double>(index)/static_cast<double>(colorArray.count()))*1.0;

                gradient.setColorAt(colorInd,color);

            }

            index++;

        }
    }
    gradient.setSpread(QGradient::ReflectSpread);

    gradient.setInterpolationMode(QGradient::InterpolationMode::ColorInterpolation);
    painter.fillRect(QRect(0,0,pWidth,pHeight),gradient);

    return pixmap;

}
