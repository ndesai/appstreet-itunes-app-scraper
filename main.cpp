#include <QtCore/QCoreApplication>
#include <QDebug>
#include "scraper.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);    
    Scraper *m_scraper = new Scraper();
    QObject::connect((QObject*)m_scraper, SIGNAL(networkReplyMapEmpty()), &a, SLOT(quit()));
    return a.exec();
}
