#include "workouttemplate.h"
#include "general.h"

int createWorkoutTemplate(const QString& name, const QString& description, const QString& type, const QString& notes, const QString& icon, const QString& exercises,int user_id) {
    return createTableRow("workout_templates", QHash<QString,QVariant>{
        {"name",name},
        {"description",description},
        {"type",type},
        {"notes",notes},
        {"icon",icon},
        {"exercises",exercises},
        {"user_id",user_id}
    });
}


bool setWorkoutTemplateFields(int workout_template_id, const QHash<QString,QVariant>& fields) {
    return setTableRowFields("workout_templates",workout_template_id,fields);
}


QHash<QString,QVariant> getWorkoutTemplate(int workout_template_id,const QStringList& fields) {
    return getTableRow("workout_templates",workout_template_id,fields);
}


QHash<int,QHash<QString,QVariant>> getWorkoutTemplates(const QHash<QString,QVariant>& filters,const QStringList& fields) {
    return getTableRows("workout_templates",filters,fields);
}


QHash<int,QHash<QString,QVariant>> getWorkoutTemplatesFromPartialName(const QString& partial_name,const QStringList& fields) {
    return getTableRowsPartialFilter("workout_templates","name",partial_name,fields);
}


QHash<int,QHash<QString,QVariant>> getWorkoutTemplatesWithExercise(int exercise_id,const QStringList& fields) {
    return getTableRowsPartialFilter("workout_templates","exercises",QString::number(exercise_id),fields);
}


bool deleteWorkoutTemplate(int workout_template_id) {
    return deleteTableRow("workout_templates",workout_template_id);
}


bool deleteWorkoutTemplates(const QHash<QString,QVariant>& filters) {
    return deleteTableRows("workout_templates",filters);
}
