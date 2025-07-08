#include "scream.h"

Scream::Scream(int categoryIndex, const QString &string, QDateTime date, QObject *parent)
    : QObject(parent), classCategory(categoryIndex),content(string), screamDate(date){
}

QDateTime Scream::getDate() const {
    return screamDate;
}
//    screamDate = QDateTime::currentDateTimeUtc();
int Scream::getCategoryIndex() const{ return classCategory; }


QString Scream::getCategory() const {
    switch(classCategory){
    case studySchool: return QString("Study/School");
    case work: return QString("Work");
    case relationship: return QString("Relationship");
    case finance: return QString("Financial issues");
    case politicsSociety:return QString("Politics/Society");
    default: return QString("Unknown");
    }
}

