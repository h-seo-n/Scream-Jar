#ifndef SCREAM_H
#define SCREAM_H

#include <QDateTime>
#include <QObject>
#include <QString>

class User;

class Scream : public QObject{
    Q_OBJECT

public:
    explicit Scream(int categoryIndex, const QString& string, QDateTime date = QDateTime::currentDateTimeUtc(), QObject *parent = nullptr);
    QString content;

    QDateTime getDate() const;
    QString getCategory() const;
    int getCategoryIndex() const;

private:
    enum Category{
        studySchool,
        work,
        relationship,
        finance,
        politicsSociety,
    };

    int classCategory;
    User *user;
    QDateTime screamDate;



};

#endif // SCREAM_H
