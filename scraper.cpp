#include "scraper.h"
#include "qdebug.h"
#include "itunesappobject.h"
Scraper::Scraper(QObject *parent) : QObject(parent)
{
    m_networkAccessManager = new QNetworkAccessManager(this);
    connect(m_networkAccessManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    m_sourceUrlManager = new SourceUrlManager("source_urls.ini", this);
    connect(m_sourceUrlManager, SIGNAL(sourceUrlsChanged(QStringMap)),this, SLOT(parseXmlFromUrls(QStringMap)));
    this->parseXmlFromUrls(m_sourceUrlManager->sourceUrls());

    m_databaseManager = new DatabaseManager(this);
}

void Scraper::replyFinished(QNetworkReply *p_reply)
{
    if(p_reply->error() == QNetworkReply::NoError)
    {
        QString _key = m_networkReplyMap.key(p_reply);
        qDebug() << "NOTICE: Reply OK" << _key << "@" << p_reply->url().toString();
        QXmlInputSource xmlInputSource;
        QByteArray _data = p_reply->readAll();
        xmlInputSource.setData(_data);
        QXmlSimpleReader reader;
        ITunesAppContentHandler _handler;
        reader.setContentHandler(&_handler);
        if(reader.parse(xmlInputSource))
        {
            QList<ITunesAppObject*> _appObjectList = _handler.appObjectList;
            for(int i = 0; i < _appObjectList.length(); i++)
            {
                if(!m_databaseManager->insertAppObject(_key, _appObjectList.at(i)))
                {
                    qDebug() << "ERROR: Failed to insert app " << _appObjectList.at(i)->name() ;
                } else
                {
                    qDebug() << "NOTICE: Inserted " << _appObjectList.at(i)->name();
                }
            }
        }
        p_reply->deleteLater();
        m_networkReplyMap.remove(_key);
        if(m_networkReplyMap.empty())
            emit networkReplyMapEmpty();
        return;
    }
    qDebug() << "ERROR: " << p_reply->errorString();
}

void Scraper::parseXmlFromUrls(QStringMap arg)
{
    for(int i = 0; i < arg.keys().length(); i++)
    {
        QString _key = arg.keys().at(i);
        QString _urlStr = arg.values().at(i);
        qDebug() << "NOTICE: Requesting" << _urlStr;
        QNetworkReply *_tempReply = m_networkAccessManager->get(QNetworkRequest(QUrl(_urlStr)));
        m_networkReplyMap.insert(_key,_tempReply);
    }
}

