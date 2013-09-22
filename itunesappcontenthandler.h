#ifndef ITUNESAPPCONTENTHANDLER_H
#define ITUNESAPPCONTENTHANDLER_H

#include "itunesappobject.h"
#include <QXmlDefaultHandler>

class ITunesAppContentHandler : public QXmlDefaultHandler
{
public:
    ITunesAppContentHandler();
    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);


public:
     QList<ITunesAppObject*> appObjectList;
     typedef QMap<QString,QString> QStringMap;
private:
     QStringList m_path;
     ITunesAppObject *m_appObject;
     QStringMap m_attributeMap;

};

#endif // ITUNESAPPCONTENTHANDLER_H
