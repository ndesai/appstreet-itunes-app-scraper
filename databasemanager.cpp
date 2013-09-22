#include "databasemanager.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
DatabaseManager::DatabaseManager(QObject *parent) :
    QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("appstreet");
    m_db.setUserName("root");
    m_db.setPassword("password");
    if (!m_db.open()) qDebug() << "Failed to connect to mysql as user testuser" ;

    QString queryString =
            "CREATE  TABLE IF NOT EXISTS `appstreet`.`apps` ( \
            `id` INT NOT NULL AUTO_INCREMENT , \
            `appId` VARCHAR(45) NOT NULL UNIQUE , \
            `bundleId` VARCHAR(256) NULL , \
            `updated` VARCHAR(256) NULL, \
            `appstoreUrl` VARCHAR(512) NULL , \
            `title` VARCHAR(128) NULL , \
            `summary` TEXT NULL , \
            `name` VARCHAR(128) NULL , \
            `alternateAppstoreUrl` VARCHAR(512) NULL , \
            `contentType` VARCHAR(128) NULL , \
            `categoryUrl` VARCHAR(512) NULL , \
            `categoryTerm` VARCHAR(128) NULL , \
            `categoryLabel` VARCHAR(128) NULL , \
            `previewType` VARCHAR(128) NULL , \
            `previewUrl` VARCHAR(512) NULL , \
            `previewDuration` VARCHAR(128) NULL , \
            `artistUrl` VARCHAR(512) NULL , \
            `artist` VARCHAR(128) NULL , \
            `priceAmount` VARCHAR(32) NULL , \
            `priceCurrency` VARCHAR(32) NULL , \
            `priceLabel` VARCHAR(128) NULL , \
            `rights` VARCHAR(128) NULL , \
            `releaseDateLabel` VARCHAR(128) NULL , \
            `releaseDate` VARCHAR(128) NULL , \
            `html` TEXT NULL , \
            `type` VARCHAR(128) NULL , \
            PRIMARY KEY (`id`, `appId`) ) \
            ENGINE = MyISAM \
            DEFAULT CHARACTER SET = utf8 \
            COLLATE = utf8_bin;";

    QSqlQuery query;
    query.exec(queryString);

}

DatabaseManager::~DatabaseManager()
{
    QSqlDatabase::removeDatabase("QMYSQL");
}

bool DatabaseManager::insertAppObject(QString type, ITunesAppObject *appObj)
{

    QSqlQuery query;
    query.prepare("INSERT INTO `appstreet`.`apps` (\
                  appId, \
                  updated, \
                  bundleId, \
                  appstoreUrl, \
                  title, \
                  summary, \
                  name, \
                  alternateAppstoreUrl, \
                  contentType, \
                  categoryTerm, \
                  categoryUrl, \
                  categoryLabel, \
                  previewType, \
                  previewUrl, \
                  previewDuration, \
                  artistUrl, \
                  artist, \
                  priceAmount, \
                  priceCurrency, \
                  priceLabel, \
                  rights, \
                  releaseDateLabel, \
                  releaseDate, \
                  html, \
                  type \
                  ) "
            "VALUES (:appId, :updated, :bundleId,:appstoreUrl,:title,  :summary, :name, :alternateAppstoreUrl, :contentType, :categoryTerm, :categoryUrl, :categoryLabel, :previewType, :previewUrl, :previewDuration, :artistUrl, :artist, :priceAmount, :priceCurrency, :priceLabel, :rights, :releaseDateLabel, :releaseDate, :html, :type)");



//    ON DUPLICATE KEY UPDATE \
//    updated = VALUES(:updated), \
//    bundleId = VALUES(:bundleId), \
//    appstoreUrl = VALUES(:appstoreUrl), \
//    title = VALUES(:title), \
//    summary = VALUES(:summary), \
//    name = VALUES(:name), \
//    alternateAppstoreUrl = VALUES(:alternateAppstoreUrl), \
//    contentType = VALUES(:contentType), \
//    categoryTerm = VALUES(:categoryTerm), \
//    categoryUrl = VALUES(:categoryUrl), \
//    categoryLabel = VALUES(:categoryLabel), \
//    previewType = VALUES(:previewType), \
//    previewUrl = VALUES(:previewUrl), \
//    previewDuration = VALUES(:previewDuration), \
//    artistUrl = VALUES(:artistUrl), \
//    artist = VALUES(:artist), \
//    priceAmount = VALUES(:priceAmount), \
//    priceCurrency = VALUES(:priceCurrency), \
//    priceLabel = VALUES(:priceLabel), \
//    rights = VALUES(:rights), \
//    releaseDateLabel = VALUES(:releaseDateLabel), \
//    releaseDate = VALUES(:releaseDate), \
//    html = VALUES(:html), \
//    type = VALUES(:type)

    query.bindValue(":appId", appObj->id());
    query.bindValue(":updated", appObj->updated());
    query.bindValue(":bundleId", appObj->bundleId());
    query.bindValue(":appstoreUrl", appObj->appstoreUrl());
    query.bindValue(":title", appObj->title());
    query.bindValue(":summary", appObj->summary());
    query.bindValue(":name", appObj->name());
    query.bindValue(":alternateAppstoreUrl", appObj->alternateAppstoreUrl());
    query.bindValue(":contentType", appObj->contentType());
    query.bindValue(":categoryTerm", appObj->categoryTerm());
    query.bindValue(":categoryUrl", appObj->categoryUrl());
    query.bindValue(":categoryLabel", appObj->categoryLabel());
    query.bindValue(":previewType", appObj->previewType());
    query.bindValue(":previewUrl", appObj->previewUrl());
    query.bindValue(":previewDuration", appObj->previewDuration());
    query.bindValue(":artistUrl", appObj->artistUrl());
    query.bindValue(":artist", appObj->artist());
    query.bindValue(":priceAmount", appObj->priceAmount());
    query.bindValue(":priceCurrency", appObj->priceCurrency());
    query.bindValue(":priceLabel", appObj->priceLabel());
    query.bindValue(":rights", appObj->rights());
    query.bindValue(":releaseDateLabel", appObj->releaseDateLabel());
    query.bindValue(":releaseDate", appObj->releaseDate());
    query.bindValue(":html", appObj->html());
    query.bindValue(":type", type);

    if(query.exec())
        return true;
    qDebug() << query.lastError();
    return false;
}
