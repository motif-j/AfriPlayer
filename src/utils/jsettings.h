#ifndef JSETTINGS_H
#define JSETTINGS_H

#include <QSettings>
#include <QObject>

class JSettings : public QObject
{
    Q_OBJECT
public:

    static JSettings &getInstance(){
        static JSettings instance;

        return instance;
    }


    int getVolume() const;
    void setVolume(int newVolume);

    bool getCrossfade() const;
    void setCrossfade(bool newCrossfade);

private:
    explicit JSettings(QObject *parent = nullptr);


private:

    QSettings *settings;

    //auto vol=settings.value("volume",20).toInt();

private:
    int volume;
    bool crossfade;
signals:

};

#endif // JSETTINGS_H
