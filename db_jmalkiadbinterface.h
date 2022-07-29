#ifndef JMALKIADBINTERFACE_H
#define JMALKIADBINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>


class JMalkiaDbInterface : public QObject
{
    Q_OBJECT
public:
    static JMalkiaDbInterface &getInstace(){
        static JMalkiaDbInterface instance;

        return instance;

    }

private:

   JMalkiaDbInterface(QObject *parent = nullptr){
        Q_UNUSED(parent);

       this->intializeDatabase();
      // initializeDa
    }

   const QString DRIVER_NAME=QString("QSQLITE");

   QSqlDatabase mDb;


   //functions

   void intializeDatabase();

signals:

};

#endif // JMALKIADBINTERFACE_H
