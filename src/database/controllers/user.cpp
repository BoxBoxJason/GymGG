#include <QCryptographicHash>
#include <QDateTime>
#include <QHash>
#include <QJsonDocument>
#include "user.h"
#include "../models/user.h"
#include "../utils/utils.h"

QJsonObject getUserJson(int user_id){
    QHash<QString,QVariant> user_info = getUser(user_id,QStringList{"id","username","email","gender","weights","height","goal","created_at"});
    QJsonObject user_json = qHashToJson(user_info);
    user_json["weights"] = QJsonDocument::fromJson(user_info["weights"].toString().toUtf8()).object();
    return user_json;
}


bool userEmailExists(const QString& email){
    return getUserIdFromEmail(email) != -1;
}


bool usernameExists(const QString& username){
    return getUserIdFromUsername(username) != -1;
}


bool userExists(const QString& username_or_email){
    return userEmailExists(username_or_email) || usernameExists(username_or_email);
}


int getUserIdFromUsernameOrEmail(const QString& email){
    int user_id = getUserIdFromEmail(email);
    if(user_id == -1){
        user_id = getUserIdFromUsername(email);
    }
    return user_id;
}


int getUserIdFromUsername(const QString& username){
    QHash<QString,QVariant> user = getUser(QHash<QString,QVariant>({{"username",username}}),QStringList({"id"}));
    if(user.isEmpty()){
        return -1;
    }
    return user["id"].toInt();
}


int getUserIdFromEmail(const QString& email){
    QHash<QString,QVariant> user = getUser(QHash<QString,QVariant>({{"email",email}}),QStringList({"id"}));
    if(user.isEmpty()){
        return -1;
    }
    return user["id"].toInt();
}


bool addUserWeight(int user_id,double weight, const QDate& date){
    QHash<QString,QVariant> user_data = getUser(user_id,QStringList({"weight"}));
    QString user_weights = user_data["weight"].toString();
    QJsonObject user_weights_json = user_weights.isEmpty() ? QJsonObject() : QJsonDocument::fromJson(user_weights.toUtf8()).object();
    
    QString stringified_date = formatDate(date);
    bool success = false;
    if(!user_weights_json.contains(stringified_date)){
        user_weights_json[stringified_date] = weight;
        success = setUserFields(user_id,QHash<QString,QVariant>({{"weight",QString::fromUtf8(QJsonDocument(user_weights_json).toJson())}}));
    }
    return success;
}


bool editUserWeight(int user_id,double weight, const QDate& date){
    QHash<QString,QVariant> user_data = getUser(user_id,QStringList({"weight"}));
    QString user_weights = user_data["weight"].toString();
    QJsonObject user_weights_json = user_weights.isEmpty() ? QJsonObject() : QJsonDocument::fromJson(user_weights.toUtf8()).object();
    
    QString stringified_date = formatDate(date);
    bool success = false;
    if(user_weights_json.contains(stringified_date)){
        user_weights_json[stringified_date] = weight;
        success = setUserFields(user_id,QHash<QString,QVariant>({{"weight",QString::fromUtf8(QJsonDocument(user_weights_json).toJson())}}));
    }
    return success;
}


bool deleteUserWeight(int user_id, const QDate& date){
    QHash<QString,QVariant> user_data = getUser(user_id,QStringList({"weight"}));
    QString user_weights = user_data["weight"].toString();
    QJsonObject user_weights_json = user_weights.isEmpty() ? QJsonObject() : QJsonDocument::fromJson(user_weights.toUtf8()).object();
    
    QString stringified_date = formatDate(date);
    bool success = false;
    if(user_weights_json.contains(stringified_date)){
        user_weights_json.remove(stringified_date);
        success = setUserFields(user_id,QHash<QString,QVariant>({{"weight",QString::fromUtf8(QJsonDocument(user_weights_json).toJson())}}));
    }
    return success;
}


double getUserWeight(int user_id, const QDate& date){
    QHash<QString,QVariant> user_data = getUser(user_id,QStringList({"weight"}));
    QString user_weights = user_data["weight"].toString();
    QJsonObject user_weights_json = user_weights.isEmpty() ? QJsonObject() : QJsonDocument::fromJson(user_weights.toUtf8()).object();

    double user_weight = -1;
    if(!user_weights_json.isEmpty() && user_weights_json.contains(formatDate(date))){
        user_weight = user_weights_json[formatDate(date)].toDouble();
    } else {
        QString stringified_date = formatDate(date);
        QStringList user_ordered_weights = user_weights_json.keys();
        user_ordered_weights.sort();

        QString closest_date = "";
        for(QString weight_date : user_ordered_weights){
            if(weight_date > stringified_date){
                break;
            }
            closest_date = weight_date;
        }
        if(!closest_date.isEmpty()){
            user_weight = user_weights_json[closest_date].toDouble();
        }
    }
    return user_weight;
}


bool validatePassword(const QString& attempted_password, const QString& hashed_password, const QString& salt) {
    QString hashedAttempt = hashPassword(attempted_password, salt);
    return hashedAttempt == hashed_password;
}


bool checkUserPasswordMatches(int user_id, const QString& password){
    QHash<QString,QVariant> user = getUser(user_id,QStringList({"password","salt"}));
    if(user.isEmpty()){
        return false;
    }
    return validatePassword(password,user["password"].toString(),user["salt"].toString());
}


QString hashPassword(const QString& password, const QString& salt){
    QByteArray combinedData = password.toUtf8() + salt.toUtf8();
    QByteArray hash = combinedData;
    
    for (int i = 0; i < 10000; ++i) {
        hash = QCryptographicHash::hash(hash, QCryptographicHash::Sha256);
    }
    return QString(hash.toHex());
}


QString generateSalt(){
    return QString(QCryptographicHash::hash(QByteArray::fromRawData(QByteArray::number(QDateTime::currentMSecsSinceEpoch()),QDateTime::currentMSecsSinceEpoch()),QCryptographicHash::Sha256).toHex());
}
