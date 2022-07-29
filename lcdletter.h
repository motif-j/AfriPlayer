#ifndef LCDLETTER_H
#define LCDLETTER_H

#include <QObject>
#include <QPainterPath>

class LcdLetter : public QObject
{
    Q_OBJECT
public:
    explicit LcdLetter(QObject *parent = nullptr);

signals:

};

#endif // LCDLETTER_H
