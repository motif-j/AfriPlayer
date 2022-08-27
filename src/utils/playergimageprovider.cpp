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

    qDebug()<<"Color Arr "<<colorArray.size();
    QString color1="";
    QString color2="";

    if(colorArray.count()==2){
        color1=colorArray[0];
        color2=colorArray[1];

    }

    if(color1.isEmpty() || color2.isEmpty()){
        color1="#cc0000";
        color2="#007fff";
    }

    QRadialGradient gradient(QPointF(pWidth/2,pHeight),pWidth*0.25);
    QPainter painter(&pixmap);
    //  QLinearGradient linearGradient(0,0,0,height);
    gradient.setColorAt(0,color1);
    gradient.setColorAt(1,color2);
    gradient.setSpread(QGradient::ReflectSpread);

    gradient.setInterpolationMode(QGradient::InterpolationMode::ColorInterpolation);
    painter.fillRect(QRect(0,0,pWidth,pHeight),gradient);

//    //topLeft
//    int sWidth=pWidth/2;
//    int sHeight=pHeight/2;
//    QRadialGradient tLgradient(QPointF(0,0),sWidth*0.25);

//    tLgradient.setColorAt(0,color1);
//    tLgradient.setColorAt(1,color2);

//    tLgradient.setSpread(QGradient::RepeatSpread);

//    painter.fillRect(QRect(0,0,sWidth,sHeight),tLgradient);

//    //bottom right

//    QRadialGradient bRgradient(QPointF(sWidth,sHeight),sWidth*0.25);

//    bRgradient.setColorAt(0,color1);
//    bRgradient.setColorAt(1,color2);

//    bRgradient.setSpread(QGradient::RepeatSpread);

//    painter.fillRect(QRect(pWidth-sWidth,pHeight-sHeight,sWidth,sHeight),bRgradient);
    return pixmap;

}
