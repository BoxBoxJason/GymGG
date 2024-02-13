#include "workout.h"
#include "general.h"

int createWorkout(const QString& name, int user_id, const QDateTime& date, const QString& notes, const QString& type, int template_id){
    return createTableRow("Workouts",QHash<QString, QVariant>({
        {"name",name},
        {"user_id",user_id},
        {"datetime",date},
        {"notes",notes},
        {"type",type},
        {"template_id",template_id}
    }));
}


bool setWorkoutFields(int workout_id,const QHash<QString, QVariant>& fields){
    return setTableRowFields("Workouts",workout_id,fields);
}


QHash<QString, QVariant> getWorkout(int workout_id){
    return getTableRow("Workouts",workout_id);
}


QHash<int, QHash<QString, QVariant>> getWorkouts(const QHash<QString, QVariant>& filters, const QStringList& fields){
    return getTableRows("Workouts",filters,fields);
}

QVector<QHash<QString, QVariant>> getWorkoutsOrdered(const QHash<QString, QVariant>& filters, const QStringList& fields){
    return getTableOrderedRows("Workouts","datetime",filters,fields);
}


QVector<QHash<QString, QVariant>> getUserWorkouts(int user_id, const QStringList& fields){
    return getWorkoutsOrdered(QHash<QString, QVariant>({{"user_id",user_id}}),fields);
}


bool deleteWorkout(int workout_id){
    return deleteTableRow("Workouts",workout_id);
}


bool deleteWorkouts(const QHash<QString, QVariant>& filters){
    return deleteTableRows("Workouts",filters);
}
