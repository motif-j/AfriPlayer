#include "musicfoldermodel.h"




int MusicFolderModel::getCount() const
{
    return count;
}

void MusicFolderModel::setCount(int newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged();
}

void MusicFolderModel::addFolder(QString path)
{
    setLoading(true);
    fileIo.addFolder(path);
}

void MusicFolderModel::deleteFolder(int index)
{


    if(index>=0 && index<m_data.count() ){
 setLoading(true);
        auto path=m_data.value(index);
        fileIo.deleteFolder(path);
    }



}

void MusicFolderModel::onFoldersFetched(QStringList folders)
{
    if(!m_data.isEmpty()){
        //clear
        emit beginRemoveRows(QModelIndex(),0,m_data.count()-1);
        m_data.clear();
        emit endRemoveRows();

    }

    int i=0;
    foreach(QString folder,folders){
        emit beginInsertRows(QModelIndex(),i,i);
        m_data.append(folder);
        emit   endInsertRows();
        i=i+1;
    }

    setCount(m_data.count());

     setLoading(false);
   // qDebug()<<"Folders Fetched "<<folders.count();


}

bool MusicFolderModel::getLoading() const
{
    return loading;
}

void MusicFolderModel::setLoading(bool newLoading)
{
    if (loading == newLoading)
        return;
    loading = newLoading;
    emit loadingChanged();
}

int MusicFolderModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();//getCount();
}

QVariant MusicFolderModel::data(const QModelIndex &index, int role) const
{

    int row=index.row();

    if(row<0 || row>=count){
        return QVariant();
    }


    auto value=m_data.value(row);

    if(role==Qt::DisplayRole){
        return value.remove(0,8);
    }
    return QVariant();
}
