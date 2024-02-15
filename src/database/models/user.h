#ifndef DATABASE_MODELS_USERS_H
#define DATABASE_MODELS_USERS_H

#include <QString>
#include <QStringList>
#include <QHash>
#include <QDate>

// ===== POST FUNCTIONS ===== //
/*!
    * \brief createUser Creates a new user
    * \param username The username of the user
    * \param email The email of the user
    * \param password The password of the user
    * \param birthdate The birthdate of the user
*/
int createUser(const QString& username, const QString& email, const QString& password);

// ===== PUT FUNCTIONS ===== //
/*!
    * \brief setUserFields Updates the fields of a user
    * \param user_id The id of the user to update
    * \param fields A hash of field names and values to update in the user
    * \return True if the user was updated successfully, false otherwise
*/
bool setUserFields(int user_id, const QHash<QString,QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
    * \brief getUser Retrieves a user given their id
    * \param user_id The id of the user to retrieve
    * \param fields A list of field names to retrieve from the user. If empty, all fields will be retrieved
    * \return A hash of field names and values from the user
*/
QHash<QString,QVariant> getUser(int user_id,const QStringList& fields = QStringList());
/*!
    * \brief getUser Retrieves a user given their filters
    * \param filters A hash of field names and values to filter the user by
    * \param fields A list of field names to retrieve from the user. If empty, all fields will be retrieved
    * \return A hash of field names and values from the user
*/
QHash<QString,QVariant> getUser(const QHash<QString,QVariant>& filters,const QStringList& fields = QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
    * \brief deleteUser Deletes a user given their id
    * \param user_id The id of the user to delete
    * \return True if the user was deleted successfully, false otherwise
*/
bool deleteUser(int user_id);

#endif // DATABASE_MODELS_USERS_H
