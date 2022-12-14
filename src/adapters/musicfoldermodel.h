#ifndef MUSICFOLDERMODEL_H
#define MUSICFOLDERMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QStringList>
#include  <src/fileio/jfileworker.h>
#include <src/workers/mainworker.h>

class MusicFolderModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool loading READ getLoading WRITE setLoading NOTIFY loadingChanged)

public:
    MusicFolderModel(QObject *parent = nullptr){

        Q_UNUSED(parent)


      //  connect(&fileIo,&JFileIO::foldersFetched,this,&MusicFolderModel::onFoldersFetched);
        // connect(&fileIo,&JFileIO::queringCompleted,this,&MusicFolderModel::onQueryingCompleted);

        setLoading(true);

        await(worker.loadFolders(),this,[this](QStringList folders){

            onFoldersFetched(folders);
        });

       //settings.setValue("queryingFiles",false);

    }



public:

    int getCount() const;
    void setCount(int newCount);

public slots:
    void addFolder(QString path);
    void deleteFolder(int index);


private :
    void onFoldersFetched(QStringList folders);


signals:
    void countChanged();

    void loadingChanged();

    void isQueringFilesChanged();

private:


    MainWorker &worker=MainWorker::getInstance();


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
