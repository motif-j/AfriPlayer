#ifndef COLORGENERATOR_H
#define COLORGENERATOR_H

#include <QObject>
#include <QRandomGenerator>
#include <QColor>

class ColorGenerator : public QObject
{
    Q_OBJECT
public:
    static ColorGenerator &getInstance(){
        static ColorGenerator instance;

        return instance;
    }
public:

    QString genColor();
private:
    explicit ColorGenerator(QObject *parent = nullptr);

private:
    QRandomGenerator *randomGen=QRandomGenerator::system();



signals:

};

#endif // COLORGENERATOR_H
