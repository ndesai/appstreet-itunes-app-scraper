#include "itunesappcontenthandler.h"
#include <QDebug>
ITunesAppContentHandler::ITunesAppContentHandler()
{

}

bool ITunesAppContentHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes)
{
    Q_UNUSED(namespaceURI);
    Q_UNUSED(localName);
    m_path.append(qName);
    if(qName == "entry")
    {
        m_appObject = new ITunesAppObject();
    }
    if(attributes.length() > 0)
    {
        m_attributeMap.clear();
        for(int i = 0; i < attributes.length(); i++)
        {
            m_attributeMap.insert(attributes.qName(i),attributes.value(i));
        }
    }
    return true;
}

bool ITunesAppContentHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    Q_UNUSED(namespaceURI);
    Q_UNUSED(localName);
    m_path.removeLast();
    QString _path = m_path.join("/");
    Q_UNUSED(_path);
    if(qName == "entry")
    {
        appObjectList.append(m_appObject);
        m_appObject = 0;
    }
    return true;
}

bool ITunesAppContentHandler::characters(const QString &str)
{
    QString _path = m_path.join("/");

    if(_path == "feed/entry/updated")
    {
        m_appObject->setUpdated(str);
    }
    else if(_path == "feed/entry/id")
    {
        m_appObject->setId(m_attributeMap.value("im:id"));
        m_appObject->setBundleId(m_attributeMap.value("im:bundleId"));
        m_appObject->setAppstoreUrl(str);
    }
    else if(_path == "feed/entry/title")
    {
        m_appObject->setTitle(str);
    }
    else if(_path == "feed/entry/summary")
    {
        m_appObject->setSummary(str);
    }
    else if(_path == "feed/entry/im:name")
    {
        m_appObject->setName(str);
    }
    else if(_path == "feed/entry/link")
    {
        if(m_attributeMap.value("rel") == "alternate")
        {
            if(m_attributeMap.value("type") == "text/html")
            {
                m_appObject->setAlternateAppstoreUrl(str);
            }
        }
        else if(m_attributeMap.value("title") == "Preview" && m_attributeMap.value("rel") == "enclosure")
        {
            m_appObject->setPreviewType(m_attributeMap.value("type"));
            m_appObject->setPreviewUrl(m_attributeMap.value("href"));
        }
    }
    else if(_path == "feed/entry/link/im:duration")
    {
        m_appObject->setPreviewDuration(str);
    }
    else if(_path == "feed/entry/im:contentType")
    {
        m_appObject->setContentType(m_attributeMap.value("term"));
    }
    else if(_path == "feed/entry/category")
    {
        m_appObject->setCategoryTerm(m_attributeMap.value("term"));
        m_appObject->setCategoryUrl(m_attributeMap.value("scheme"));
        m_appObject->setCategoryLabel(m_attributeMap.value("label"));
    }
    else if(_path == "feed/entry/im:artist")
    {
        m_appObject->setArtist(str);
    }
    else if(_path == "feed/entry/im:price")
    {
        m_appObject->setPriceLabel(str);
    }
    else if(_path == "feed/entry/im:image")
    {
        m_appObject->images().insert(m_attributeMap.value("height"),str);
    }
    else if(_path == "feed/entry/rights")
    {
        m_appObject->setRights(str);
    }
    else if(_path == "feed/entry/im:releaseDate")
    {
        m_appObject->setReleaseDate(str);
    }
    else if(_path == "feed/entry/content")
    {
        if(m_attributeMap.value("type") == "html")
        {
            m_appObject->setHtml(str);
        }
    }

    return true;
}
