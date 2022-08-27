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

    int getPlayingTrackId() const;
    void setPlayingTrackId(int newPlayingTrackId);

    bool getShuffle() const;
    void setShuffle(bool newShuffle);

    bool getIsQuering() const;
    void setIsQuering(bool newIsQuering);

private:
    explicit JSettings(QObject *parent = nullptr);


private:

    QSettings *settings;

    //auto vol=settings.value("volume",20).toInt();

private:
    int volume;
    bool crossfade;
    int playingTrackId;
    bool shuffle;
    bool isQuering=false;
signals:

};

#endif // JSETTINGS_H
