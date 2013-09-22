#ifndef SCRAPER_H
#define SCRAPER_H

#include <QObject>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QtNetwork/QNetworkReply>
#include "itunesappcontenthandler.h"
#include "sourceurlmanager.h"
#include "databasemanager.h"

class Scraper : public QObject
{
    Q_OBJECT
public:
    explicit Scraper(QObject *parent = 0);
    typedef QMap<QString,QString> QStringMap;
private:
    QNetworkAccessManager *m_networkAccessManager;
    SourceUrlManager *m_sourceUrlManager;
    QMap<QString,QNetworkReply*> m_networkReplyMap;
    DatabaseManager *m_databaseManager;
    void getXmlFromUrl(QUrl url);
private slots:
    void replyFinished(QNetworkReply* p_reply);
    void parseXmlFromUrls(QStringMap arg);
signals:
    void networkReplyMapEmpty();
public slots:
    
};

#endif // SCRAPER_H
