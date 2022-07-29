#ifndef JLCD_H
#define JLCD_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QPainter>
#include <QPainterPath>

class JLCD : public QQuickPaintedItem
{
    Q_OBJECT


public:
    JLCD();
    ~JLCD();

    void paint (QPainter *painter) override;

private:
    QPainterPath *path;


};

#endif // JLCD_H
