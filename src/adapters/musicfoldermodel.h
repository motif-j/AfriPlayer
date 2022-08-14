#ifndef MUSICFOLDERMODEL_H
#define MUSICFOLDERMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include <QString>
#include <QStringList>
#include "src/fileio/file_jfileio.h"

class MusicFolderModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
     Q_PROPERTY(bool loading READ getLoading WRITE setLoading NOTIFY loadingChanged)
public:
     MusicFolderModel(QObject *parent = nullptr){

        Q_UNUSED(parent)


         connect(&fileIo,&JFileIO::foldersFetched,this,&MusicFolderModel::onFoldersFetched);

          setLoading(true);
         fileIo.getFolders();

    }




public:

    int getCount() const;
    void setCount(int newCount);

public slots:
    void addFolder(QString path);
    void deleteFolder(int index);

public slots:
  void onFoldersFetched(QStringList folders);


signals:
    void countChanged();

    void loadingChanged();

private:

    JFileIO &fileIo=JFileIO::getInstance();

    QStringList m_data;
    int count;
    bool loading;



public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    bool getLoading() const;
    void setLoading(bool newLoading);
};

#endif // MUSICFOLDERMODEL_H
