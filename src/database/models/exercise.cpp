#include <QSqlQuery>
#include "exercise.h"
#include "general.h"
#include "../controllers/initdb.h"

int createExercise(const QString& name, const QString& description, const QString& type, const QString& notes, const QStringList& muscles, const QStringList& equipments, const QString& icon){
    
    return createTableRow("Exercises",QHash<QString,QVariant>{
        {"name",name},
        {"description",description},
        {"type",type},
        {"notes",notes},
        {"muscles",QVariant(muscles)},
        {"equipments",QVariant(equipments)},
        {"icon",icon}
    });
}


bool setExerciseFields(int exercise_id,const QHash<QString, QVariant>& fields){
    return setTableRowFields("Exercises",exercise_id,fields);
}


QHash<QString, QVariant> getExercise(int exercise_id, const QStringList& fields){
    return getTableRow("Exercises",exercise_id,fields);
}


QHash<int,QHash<QString,QVariant>> getExercises(const QVector<int>& row_ids,const QStringList& fields){
    return getTableRows("Exercises",row_ids,fields);
}


QHash<int,QHash<QString, QVariant>> getExercises(const QHash<QString,QVariant>& filters, const QStringList& fields){
    return getTableRows("Exercises",filters,fields);
}


QVector<QHash<QString, QVariant>> getExercisesOrdered(const QHash<QString,QVariant>& filters,const QStringList& fields){
    return getTableOrderedRows("Exercises","name",filters,fields);
}


QVector<QHash<QString,QVariant>> getExercisesFromPartialName(const QString& partial_name,const QHash<QString,QVariant>& filters, const QStringList& fields){
    QSqlQuery query;
    QStringList field_names;
    if (fields.isEmpty()) {
        field_names << "*";
    } else {
        field_names = fields;
    }

    QStringList filter_names;
    for (auto it = filters.begin(); it != filters.end(); ++it) {
        filter_names << it.key() + " = :" + it.key();
    }
    filter_names << "name LIKE :partial_name";
    query.prepare("SELECT " + field_names.join(", ") + " FROM Exercises WHERE " + filter_names.join(" AND ") + " ORDER BY name ASC");
    for (auto it = filters.begin(); it != filters.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }
    query.bindValue(":partial_name", "%" + partial_name + "%");

    QVector<QHash<QString,QVariant>> rows;
    if(query.exec()){
        while (query.next()) {
            QHash<QString,QVariant> row;
            if (!fields.isEmpty()){
                for (auto it = field_names.begin(); it != field_names.end(); ++it) {
                    row[*it] = query.value(*it);
                }
            } else {
                for (int i = 0; i < query.record().count(); ++i) {
                    row[query.record().fieldName(i)] = query.value(i);
                }
            }
            rows.append(row);
        }
    } else {
        QHash<QString,QVariant> row;
        row["error"] = query.lastError().text();
        rows.append(row);
    }
    return rows;
}


bool deleteExercise(int exercise_id){
    return deleteTableRow("Exercises",exercise_id);
}
