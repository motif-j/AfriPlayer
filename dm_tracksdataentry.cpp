#include "dm_tracksdataentry.h"



int TracksDataEntry::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_data.count();
}

QVariant TracksDataEntry::data(const QModelIndex &index, int role) const
{
    int row=index.row();

    if(row<0 ||row>m_data.count()){
        return QVariant();
    }

    if(role==Qt::DisplayRole){
        return m_data.value(row);

    }

    return QVariant();

}



void TracksDataEntry::add(const QString &color)
{
    auto index=getCount();

    if(index<0 || index>count){
        return;
    }

     QColor color2(color);
     if(!color2.isValid()){
         return;
     }

    emit beginInsertColumns(QModelIndex(),index,index);

     m_data.append(color2.name());

    emit endInsertRows();

     setCount(m_data.count());



}

int TracksDataEntry::getCount() const
{
    return count;
}

void TracksDataEntry::setCount(int newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged(count);
}

void TracksDataEntry::resetCount()
{
    setCount({}); // TODO: Adapt to use your actual default value
}
