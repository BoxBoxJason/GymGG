#ifndef DATABASE_UTILS_UTILS_H
#define DATABASE_UTILS_UTILS_H

#include <QHash>
#include <QJsonObject>
#include <QJsonArray>

QJsonObject qHashToJson(const QHash<QString,QVariant>& hash);
QJsonObject qHashToJson(const QHash<int,QHash<QString,QVariant>>& hash);
QHash<QString,QVariant> jsonToQHash(const QJsonObject& json);

QJsonArray qListToJson(const QList<QHash<QString,QVariant>>& list);

QString formatDate(const QDate& date);

#endif // DATABASE_UTILS_UTILS_H
