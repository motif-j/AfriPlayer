#include "colorgenerator.h"



ColorGenerator::ColorGenerator(QObject *parent)
    : QObject{parent}
{

}

QString ColorGenerator::genColor()
{
    int maxColors=2;//randomGen->bounded(1,3);
    QStringList *colors=new QStringList;

    for(int i=1;i<=maxColors;i++){
        int red=randomGen.bounded(0,255);
        int green=randomGen.bounded(0,255);
        int blue=randomGen.bounded(0,255);

        QColor *color=new QColor(red,green,blue);
        colors->append(color->name(QColor::HexRgb));

        delete color;


    }

    QString finalColor;
    foreach(QString color,*colors){

        finalColor.append(color).append("-");
    }

    finalColor.remove(finalColor.length()-1,finalColor.length()-1);

    delete colors;
    return finalColor;

}
