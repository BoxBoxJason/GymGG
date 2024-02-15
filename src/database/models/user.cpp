#include <QHash>
#include "user.h"
#include "general.h"
#include "../controllers/user.h"

int createUser(const QString& username, const QString& email, const QString& password){
    QString salt = generateSalt();
    QString hashed_password = hashPassword(password,salt);

    return createTableRow("Users",QHash<QString,QVariant>({
        {"username",username},
        {"email",email},
        {"password",hashed_password},
        {"salt",salt},
        {"created_at",QDateTime::currentDateTime()}
        }));
}


QHash<QString,QVariant> getUser(int user_id,const QStringList& fields){
    return getTableRow("Users",user_id,fields);
}


QHash<QString,QVariant> getUser(const QHash<QString,QVariant>& unique_filters,const QStringList& fields){
    return getTableRow("Users",unique_filters,fields);
}


bool setUserFields(int user_id, const QHash<QString,QVariant>& fields){
    return setTableRowFields("Users",user_id,fields);
}


bool deleteUser(int user_id){
    return deleteTableRow("Users",user_id);
}
