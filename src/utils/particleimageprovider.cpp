#include "particleimageprovider.h"

#include <QPainter>
#include <QPainterPath>
#include <QRadialGradient>

ParticleImageProvider::ParticleImageProvider()
    :QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap ParticleImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    int width = 100;
    int height = 100;

    int pWidth=requestedSize.width() > 0 ? requestedSize.width() : width;
    int pHeight=requestedSize.height() > 0 ? requestedSize.height() : height;

    if (size)
        *size = QSize(pWidth, pHeight);
    QPixmap pixmap(pWidth,pHeight);




    if(id=="00"){
        QUrl *url= new  QUrl("assets/cover.png");
        pixmap.load(url->path());
        return pixmap;
    }
    auto colorArray=id.split("-");


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
    QRadialGradient linearGradient(QPointF(pWidth/2,pHeight/2),pWidth*0.25);
    QPainter painter(&pixmap);
    //  painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;

    path.addRoundedRect(QRect(0,0,pWidth,pHeight),pWidth/2,pHeight/2);

    QPen pen(Qt::transparent);


    painter.setPen(pen);
    painter.fillRect(QRect(0,0,pWidth,pHeight),Qt::transparent);
    //  QLinearGradient linearGradient(0,0,0,height);
    linearGradient.setColorAt(0,color1);
    // linearGradient.setColorAt(0.5,Qt::blue);
    linearGradient.setColorAt(1,color2);
    linearGradient.setSpread(QGradient::RepeatSpread);

    painter.fillPath(path,linearGradient);
    painter.drawPath(path);







    return pixmap;

}
