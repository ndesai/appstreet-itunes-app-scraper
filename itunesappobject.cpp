#include "itunesappobject.h"

ITunesAppObject::ITunesAppObject(QObject *parent) :
    QObject(parent)
{
}
bool operator == (const ITunesAppObject& lhs, const ITunesAppObject& rhs) {
    return (lhs.id()   == rhs.id());
}
bool operator != (const ITunesAppObject& lhs, const ITunesAppObject& rhs) {
    return !(lhs == rhs);
}
