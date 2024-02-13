#include "utils.h"
#include <QJsonArray>

QJsonObject qHashToJson(const QHash<QString,QVariant>& hash){
    QJsonObject json;
    for(auto it = hash.begin(); it != hash.end(); it++){
        json[it.key()] = QJsonValue::fromVariant(it.value());
    }
    return json;
}


QJsonObject qHashToJson(const QHash<int,QHash<QString,QVariant>>& hash){
    QJsonObject json;
    for(auto it = hash.begin(); it != hash.end(); it++){
        json[QString::number(it.key())] = qHashToJson(it.value());
    }
    return json;
}


QJsonArray qListToJson(const QList<QHash<QString,QVariant>>& list){
    QJsonArray json;
    for(auto it = list.begin(); it != list.end(); it++){
        json.append(qHashToJson(*it));
    }
    return json;
}


QHash<QString,QVariant> jsonToQHash(const QJsonObject& json){
    QHash<QString,QVariant> hash;
    for(auto it = json.begin(); it != json.end(); it++){
        hash[it.key()] = it.value().toVariant();
    }
    return hash;
}


QString formatDate(const QDate& date){
    return date.toString("yyyy/MM/dd");
}
