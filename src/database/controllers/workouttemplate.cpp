#include <QVector>
#include <QVariant>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include "workouttemplate.h"
#include "../models/workouttemplate.h"
#include "../models/exercise.h"
#include "../controllers/exercise.h"


QString getTemplateJson(int template_id){
    QHash<QString,QVariant> template_infos = getWorkoutTemplate(template_id);
    QJsonObject template_json;
    // Default keys
    template_json["id"] = template_id;
    for(QString template_key : {"name","description","notes","type","icon"}){
        template_json[template_key] = template_infos[template_key].toString();
    }
    // Exercises
    QString exercises = template_infos["exercises"].toString();
    QJsonArray exercises_base_json = exercises.isEmpty() ? QJsonArray() : QJsonDocument::fromJson(exercises.toUtf8()).array();
    template_json["exercises"] = getExercisesJsonWorkoutTemplate(exercises_base_json);

    return QString::fromUtf8(QJsonDocument(template_json).toJson());
}


bool removeExerciseFromTemplate(int template_id, int exercise_id){
    QString exercises = getWorkoutTemplate(template_id,QStringList{"exercises"})["exercises"].toString();
    QJsonArray exercises_json = exercises.isEmpty() ? QJsonArray() : QJsonDocument::fromJson(exercises.toUtf8()).array();

    QJsonArray corrected_exercises;
    for(const QJsonValue& value: exercises_json){
        QJsonObject exercise_dict = value.toObject();
        if(exercise_dict.value("id").toInt() != exercise_id){
            corrected_exercises.append(value);
        }
    }
    return setWorkoutTemplateFields(template_id,QHash<QString,QVariant>{{"exercises",QString::fromUtf8(QJsonDocument(corrected_exercises).toJson())}});
}


bool removeExerciseFromAllTemplates(int exercise_id){
    QVector<int> templates_ids = getWorkoutTemplatesWithExercise(exercise_id,QStringList{"id"}).keys();
    bool success = true;
    for(int template_id : templates_ids){
        success &= removeExerciseFromTemplate(template_id,exercise_id);
    }
    return success;
}
