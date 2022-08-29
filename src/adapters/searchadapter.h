#ifndef SEARCHADAPTER_H
#define SEARCHADAPTER_H

#include <QObject>
#include "src/adapters/tracksadpater.h"

class SearchAdapter : public AbstractTracksAdapter
{
    Q_OBJECT
public:
    explicit SearchAdapter(QObject *parent = nullptr);

public slots:

    void querySong(QString query);
};

#endif // SEARCHADAPTER_H
