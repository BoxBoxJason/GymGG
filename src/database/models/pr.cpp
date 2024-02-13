#include "pr.h"
#include "general.h"

int createPR(int user_id, int workout_id, int exercise_id, int exercise_workout_id, int set_id,const QDateTime& datetime,const QString& type, float value){
    return createTableRow("PRs",QHash<QString,QVariant>({
        {"user_id",user_id},
        {"workout_id",workout_id},
        {"exercise_id",exercise_id},
        {"exercise_workout_id",exercise_workout_id},
        {"set_id",set_id},
        {"datetime",datetime},
        {"type",type},
        {"value",value}
    }));
}

bool setPRFields(int pr_id, const QHash<QString, QVariant>& fields){
    return setTableRowFields("PRs",pr_id,fields);
}


QHash<QString, QVariant> getPR(int pr_id, const QStringList& fields){
    return getTableRow("PRs",pr_id,fields);
}


QHash<int,QHash<QString,QVariant>> getPRs(const QVector<int>& prs_ids, const QStringList& fields){
    return getTableRows("PRs",prs_ids,fields);
}


QHash<int,QHash<QString, QVariant>> getPRs(const QHash<QString,QVariant>& filters, const QStringList& fields){
    return getTableRows("PRs",filters,fields);
}


QVector<QHash<QString, QVariant>> getPRsOrdered(const QHash<QString,QVariant>& filters, const QStringList& fields){
    return getTableOrderedRows("PRs","datetime",filters,fields);
}


bool deletePR(int pr_id){
    return deleteTableRow("PRs",pr_id);
}
