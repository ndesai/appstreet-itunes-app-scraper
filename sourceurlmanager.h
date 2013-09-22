#ifndef SOURCEURLMANAGER_H
#define SOURCEURLMANAGER_H

#include <QObject>
#include <QSettings>

class SourceUrlManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringMap sourceUrls READ sourceUrls NOTIFY sourceUrlsChanged)
 public:
    explicit SourceUrlManager(QString fileName, QObject *parent = 0);
    typedef QMap<QString,QString> QStringMap;

    QStringMap sourceUrls() const
    {
        return m_sourceUrls;
    }

private:
    bool parseIni();
    QString m_fileName;

    QStringMap m_sourceUrls;
signals:

    void sourceUrlsChanged(QStringMap arg);
public slots:
    
};

#endif // SOURCEURLMANAGER_H
