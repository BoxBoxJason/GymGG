#ifndef DATABASE_CONTROLLERS_INITDB_H
#define DATABASE_CONTROLLERS_INITDB_H

#include <QString>
#include <QDate>
#include <QJsonObject>

QJsonObject getUserJson(int user_id);

bool userEmailExists(const QString& email);
bool usernameExists(const QString& username);
bool userExists(const QString& username_or_email);

/*!
    * \brief getUserIdFromUsernameOrEmail Retrieves the id of a user given their username or email
    * \param email The username or email of the user
    * \return The id of the user, or -1 if the user was not found
*/
int getUserIdFromUsernameOrEmail(const QString& email);
/*!
    * \brief getUserIdFromUsername Retrieves the id of a user given their username
    * \param username The username of the user
    * \return The id of the user, or -1 if the user was not found
*/
int getUserIdFromUsername(const QString& username);
/*!
    * \brief getUserIdFromEmail Retrieves the id of a user given their email
    * \param email The email of the user
    * \return The id of the user, or -1 if the user was not found
*/
int getUserIdFromEmail(const QString& email);

bool addUserWeight(int user_id,double weight, const QDate& date);
bool editUserWeight(int user_id,double weight, const QDate& date);
bool deleteUserWeight(int user_id, const QDate& date);
double getUserWeight(int user_id, const QDate& date);

bool checkUserPasswordMatches(int user_id, const QString& password);
bool validatePassword(const QString& attempted_password, const QString& hashed_assword, const QString& salt);

QString hashPassword(const QString& password, const QString& salt);
QString generateSalt();

#endif // DATABASE_CONTROLLERS_INITDB_H
