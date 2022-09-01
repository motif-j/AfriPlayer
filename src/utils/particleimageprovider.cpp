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


    QRadialGradient linearGradient(QPointF(pWidth/2,pHeight/2),pWidth*0.25);
    QPainter painter(&pixmap);
    //  painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;

    path.addRoundedRect(QRect(0,0,pWidth,pHeight),pWidth/2,pHeight/2);

    QPen pen(Qt::transparent);


    painter.setPen(pen);
    painter.fillRect(QRect(0,0,pWidth,pHeight),Qt::transparent);
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

    painter.fillPath(path,linearGradient);
    painter.drawPath(path);







    return pixmap;

}
