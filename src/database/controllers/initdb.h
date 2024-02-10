#ifndef DATABASE_CONTROLLERS_INITDB_H
#define DATABASE_CONTROLLERS_INITDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>

bool initDB();
bool createTables();
bool createDefaultWorkoutTemplates();
bool createDefaultExercises();

QSqlDatabase getDB();

#endif // DATABASE_CONTROLLERS_INITDB_H
