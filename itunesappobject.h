#ifndef ITUNESAPPOBJECT_H
#define ITUNESAPPOBJECT_H

#include <QObject>
#include <QMap>
#include <QString>
class ITunesAppObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString updated READ updated WRITE setUpdated)
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString bundleId READ bundleId WRITE setBundleId)
    Q_PROPERTY(QString appstoreUrl READ appstoreUrl WRITE setAppstoreUrl)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString summary READ summary WRITE setSummary)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString alternateAppstoreUrl READ alternateAppstoreUrl WRITE setAlternateAppstoreUrl)
    Q_PROPERTY(QString contentType READ contentType WRITE setContentType)
    Q_PROPERTY(QString categoryTerm READ categoryTerm WRITE setCategoryTerm)
    Q_PROPERTY(QString categoryUrl READ categoryUrl WRITE setCategoryUrl)
    Q_PROPERTY(QString categoryLabel READ categoryLabel WRITE setCategoryLabel)
    Q_PROPERTY(QString previewType READ previewType WRITE setPreviewType)
    Q_PROPERTY(QString previewUrl READ previewUrl WRITE setPreviewUrl)
    Q_PROPERTY(QString previewDuration READ previewDuration WRITE setPreviewDuration)
    Q_PROPERTY(QString artistUrl READ artistUrl WRITE artistUrl)
    Q_PROPERTY(QString artist READ artist WRITE setArtist)
    Q_PROPERTY(QString priceAmount READ priceAmount WRITE setPriceAmount)
    Q_PROPERTY(QString priceCurrency READ priceCurrency WRITE setPriceCurrency)
    Q_PROPERTY(QString priceLabel READ priceLabel WRITE setPriceLabel)
    Q_PROPERTY(QStringMap images READ images WRITE setImages)
    Q_PROPERTY(QString rights READ rights WRITE setRights)
    Q_PROPERTY(QString releaseDateLabel READ releaseDateLabel WRITE setReleaseDateLabel)
    Q_PROPERTY(QString releaseDate READ releaseDate WRITE setReleaseDate)
    Q_PROPERTY(QString html READ html WRITE setHtml)
public:
    explicit ITunesAppObject(QObject *parent = 0);
    typedef QMap<QString,QString> QStringMap;
    friend bool operator == (const ITunesAppObject& lhs, const ITunesAppObject& rhs);
    friend bool operator != (const ITunesAppObject& lhs, const ITunesAppObject& rhs);
    ITunesAppObject& operator = (const ITunesAppObject& a) {
       if (this == &a) return *this;

       m_updated = a.updated();
       m_id = a.id();
       m_bundleId = a.bundleId();
       m_appstoreUrl = a.appstoreUrl();
       m_title = a.title();
       m_summary = a.summary();
       m_name = a.name();
       m_alternateAppstoreUrl = a.alternateAppstoreUrl();
       m_contentType = a.contentType();
       m_categoryTerm = a.categoryTerm();
       m_categoryUrl = a.categoryUrl();
       m_categoryLabel = a.categoryLabel();
       m_previewType = a.previewType();
       m_previewUrl = a.previewUrl();
       m_previewDuration = a.previewDuration();
       m_artistUrl = a.artistUrl();
       m_artist = a.artist();
       m_priceAmount = a.priceAmount();
       m_priceCurrency = a.priceCurrency();
       m_priceLabel = a.priceLabel();
       m_images = a.images();
       m_rights = a.rights();
       m_releaseDateLabel = a.releaseDateLabel();
       m_releaseDate = a.releaseDate();
       m_html = a.html();

       return *this;
    }
    QString updated() const
    {
        return m_updated;
    }

    QString id() const
    {
        return m_id;
    }

    QString bundleId() const
    {
        return m_bundleId;
    }

    QString appstoreUrl() const
    {
        return m_appstoreUrl;
    }

    QString title() const
    {
        return m_title;
    }

    QString summary() const
    {
        return m_summary;
    }

    QString name() const
    {
        return m_name;
    }

    QString alternateAppstoreUrl() const
    {
        return m_alternateAppstoreUrl;
    }

    QString contentType() const
    {
        return m_contentType;
    }

    QString categoryTerm() const
    {
        return m_categoryTerm;
    }

    QString categoryUrl() const
    {
        return m_categoryUrl;
    }

    QString categoryLabel() const
    {
        return m_categoryLabel;
    }

    QString previewType() const
    {
        return m_previewType;
    }

    QString previewUrl() const
    {
        return m_previewUrl;
    }

    QString previewDuration() const
    {
        return m_previewDuration;
    }

    QString artistUrl() const
    {
        return m_artistUrl;
    }

    QString artist() const
    {
        return m_artist;
    }

    QString priceAmount() const
    {
        return m_priceAmount;
    }

    QString priceCurrency() const
    {
        return m_priceCurrency;
    }

    QString priceLabel() const
    {
        return m_priceLabel;
    }

    QStringMap images() const
    {
        return m_images;
    }

    QString rights() const
    {
        return m_rights;
    }

    QString releaseDateLabel() const
    {
        return m_releaseDateLabel;
    }

    QString releaseDate() const
    {
        return m_releaseDate;
    }

    QString html() const
    {
        return m_html;
    }

private:

    QString m_updated;

    QString m_id;

    QString m_bundleId;

    QString m_appstoreUrl;

    QString m_title;

    QString m_summary;

    QString m_name;

    QString m_alternateAppstoreUrl;

    QString m_contentType;

    QString m_categoryTerm;

    QString m_categoryUrl;

    QString m_categoryLabel;

    QString m_previewType;

    QString m_previewUrl;

    QString m_previewDuration;

    QString m_artistUrl;

    QString m_artist;

    QString m_priceAmount;

    QString m_priceCurrency;

    QString m_priceLabel;

    QStringMap m_images;

    QString m_rights;

    QString m_releaseDateLabel;

    QString m_releaseDate;

    QString m_html;

signals:
    
public slots:
    
    void setUpdated(QString arg)
    {
        m_updated = arg;
    }
    void setId(QString arg)
    {
        m_id = arg;
    }
    void setBundleId(QString arg)
    {
        m_bundleId = arg;
    }
    void setAppstoreUrl(QString arg)
    {
        m_appstoreUrl = arg;
    }
    void setTitle(QString arg)
    {
        m_title = arg;
    }
    void setSummary(QString arg)
    {
        m_summary = arg;
    }
    void setName(QString arg)
    {
        m_name = arg;
    }
    void setAlternateAppstoreUrl(QString arg)
    {
        m_alternateAppstoreUrl = arg;
    }
    void setContentType(QString arg)
    {
        m_contentType = arg;
    }
    void setCategoryTerm(QString arg)
    {
        m_categoryTerm = arg;
    }
    void setCategoryUrl(QString arg)
    {
        m_categoryUrl = arg;
    }
    void setCategoryLabel(QString arg)
    {
        m_categoryLabel = arg;
    }
    void setPreviewType(QString arg)
    {
        m_previewType = arg;
    }
    void setPreviewUrl(QString arg)
    {
        m_previewUrl = arg;
    }
    void setPreviewDuration(QString arg)
    {
        m_previewDuration = arg;
    }
    void artistUrl(QString arg)
    {
        m_artistUrl = arg;
    }
    void setArtist(QString arg)
    {
        m_artist = arg;
    }
    void setPriceAmount(QString arg)
    {
        m_priceAmount = arg;
    }
    void setPriceCurrency(QString arg)
    {
        m_priceCurrency = arg;
    }
    void setPriceLabel(QString arg)
    {
        m_priceLabel = arg;
    }
    void setImages(QStringMap arg)
    {
        m_images = arg;
    }
    void setRights(QString arg)
    {
        m_rights = arg;
    }
    void setReleaseDateLabel(QString arg)
    {
        m_releaseDateLabel = arg;
    }
    void setReleaseDate(QString arg)
    {
        m_releaseDate = arg;
    }
    void setHtml(QString arg)
    {
        m_html = arg;
    }
};

#endif // ITUNESAPPOBJECT_H
