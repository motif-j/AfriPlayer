#ifndef TRACKSDATAENTRY_H
#define TRACKSDATAENTRY_H

#include <QAbstractListModel>
#include <QObject>
#include <QString>
#include <QList>
#include<QtGui>


class TracksDataEntry : public QAbstractListModel
{
    Q_OBJECT
     Q_PROPERTY(int count READ getCount WRITE setCount RESET resetCount NOTIFY countChanged)
public:
    explicit TracksDataEntry(QObject *parent = nullptr){
        Q_UNUSED(parent);
        m_data=QColor::colorNames();
    }


    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;


    int getCount() const;
    void setCount(int newCount);
    void resetCount();

public slots:
   // void add(int index,const QString &color);
    void add(const QString &color);



    //fields
signals:
    void countChanged(int count);

private:
    QList<QString> m_data;
    int count;



};

#endif // TRACKSDATAENTRY_H
