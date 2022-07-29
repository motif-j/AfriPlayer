#include "jlcd.h"
#include <QPoint>
#include <QColor>
#include <QPen>

JLCD::JLCD()
{
    setAntialiasing(true);


}
void JLCD::paint(QPainter *painter){

    QPen pen;
    pen.setColor(QColor(255,10,232,255));
    pen.setWidth(5);
    path->lineTo(QPoint(0,40));



    painter->setPen(pen) ;
    painter->drawPath(*path);




}

JLCD::~JLCD(){
    qDebug()<<"Clean up";

}
