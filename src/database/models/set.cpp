#include "set.h"
#include "general.h"

int createSet(int user_id, int workout_id, int exercise_id, int exercise_workout_id){
    return createTableRow("Sets",QHash<QString,QVariant>({
        {"user_id",user_id},
        {"workout_id",workout_id},
        {"exercise_id",exercise_id},
        {"exercise_workout_id",exercise_workout_id}
    }));
}


bool setSetFields(int set_id, const QHash<QString, QVariant>& fields){
    return setTableRowFields("Sets",set_id,fields);
}


QHash<QString, QVariant> getSet(int set_id, const QStringList& fields){
    return getTableRow("Sets",set_id,fields);
}


QHash<int, QHash<QString, QVariant>> getSets(const QHash<QString, QVariant>& filters, const QStringList& fields){
    return getTableRows("Sets",filters,fields);
}


QVector<QHash<QString, QVariant>> getSetsOrdered(const QHash<QString, QVariant>& filters, const QStringList& fields){
    return getTableOrderedRows("Sets","datetime",filters,fields);
}


bool deleteSet(int set_id){
    return deleteTableRow("Sets",set_id);
}


bool deleteSets(const QHash<QString, QVariant>& filters){
    return deleteTableRows("Sets",filters);
}
