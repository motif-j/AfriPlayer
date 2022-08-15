#include "../fileio/file_jfileio.h"


void JFileIO::onFileQueryCompleted()
{

    emit queringCompleted();
}

void JFileIO::onFoldersFetched(QStringList folders)
{

    emit foldersFetched(folders);

}

void JFileIO::addFolder(QString path)
{
    emit addFolderSig(path);

}

void JFileIO::deleteFolder(QString dirPath)
{
    emit deleteFolderSig(dirPath);

}

void JFileIO::getFolders()
{
    emit fetchFolders();
}
