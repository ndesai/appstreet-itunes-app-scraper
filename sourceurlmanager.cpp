#include "sourceurlmanager.h"
#include "qdebug.h"
#include "qstringlist.h"
SourceUrlManager::SourceUrlManager(QString fileName, QObject *parent) : QObject(parent)
{
    m_fileName = fileName;
    Q_ASSERT(m_fileName != "");
    this->parseIni();
}
bool SourceUrlManager::parseIni()
{
    QSettings *settings = new QSettings(m_fileName, QSettings::IniFormat);
    Q_ASSERT(settings->allKeys().length() > 0);
    QListIterator<QString> i(settings->allKeys());
    while (i.hasNext())
    {
        QString _key = i.next();
        m_sourceUrls.insert(_key, settings->value(_key).toString());
    }
    emit sourceUrlsChanged(m_sourceUrls);
    return true;
}
