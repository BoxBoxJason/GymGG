#ifndef DATABASE_MODELS_USERS_H
#define DATABASE_MODELS_USERS_H

#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QJsonObject>

bool userEmailExists(const QString& email);
bool usernameExists(const QString& username);
bool userExists(const QString& username_or_email);

bool createUser(const QString& username, const QString& email, const QString& password);

QString getUserIdFromUsernameOrEmail(const QString& email);
QString getUserIdFromUsername(const QString& username);
QString getUserIdFromEmail(const QString& email);
QJsonObject getUser(const QString& user_id,const QStringList& fields = QStringList());

bool setUserFields(const QString& user_id, const QJsonObject& fields);

bool deleteUser(const QString& user_id, const QString& password);
bool deleteUserWeight(const QString& user_id, const QString& weight_id);
bool deleteUserHeight(const QString& user_id, const QString& height_id);

bool checkUserPasswordMatches(const QString& user_id, const QString& password);

#endif // DATABASE_MODELS_USERS_H
