#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include "itunesappobject.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);
    ~DatabaseManager();
    bool insertAppObject(QString type, ITunesAppObject *appObj);
private:
    QSqlDatabase m_db;
signals:
    
public slots:    
};

#endif // DATABASEMANAGER_H
