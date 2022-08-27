#ifndef MTRACKSADAPTER_H
#define MTRACKSADAPTER_H

#include <QObject>
#include <src/adapters/tracksadpater.h>

class MTracksAdapter : public AbstractTracksAdapter
{
    Q_OBJECT
      Q_PROPERTY(bool doneFetching READ getDoneFetching WRITE setDoneFetching NOTIFY doneFetchingChanged)
public:
    explicit MTracksAdapter(QObject *parent = nullptr);

    bool getDoneFetching() const;
    void setDoneFetching(bool newDoneFetching);

public slots:

    void loadTracks();

signals:
    void doneFetchingChanged();

private:

    bool doneFetching=false;

};

#endif // MTRACKSADAPTER_H
