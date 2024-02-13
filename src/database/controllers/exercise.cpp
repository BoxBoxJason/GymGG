#include "exercise.h"
#include "../models/exercise.h"
#include "../utils/utils.h"

QJsonArray getExercisesJsonWorkoutTemplate(const QJsonArray& raw_workout_exercises){
    QVector<int> exercises_ids;
    for(const QJsonValue& value : raw_workout_exercises){
        QJsonObject raw_exercise_dict = value.toObject();
        exercises_ids.append(raw_exercise_dict["id"].toInt());
    }
    QHash<int,QHash<QString,QVariant>> exercises = getExercises(exercises_ids,QStringList{"id","name"});

    QJsonArray exercises_json_array;
    for(int i=0;i<raw_workout_exercises.size();i++){
        QJsonObject raw_exercise_dict = raw_workout_exercises[i].toObject();
        QJsonObject new_exercise_dict = qHashToJson(exercises[raw_exercise_dict["id"].toInt()]);
        new_exercise_dict.insert("sets",raw_exercise_dict["sets"]);
    
        exercises_json_array.append(new_exercise_dict);
    }
    return exercises_json_array;
}


QJsonObject getExerciseJson(int exercise_id){
    QHash<QString,QVariant> exercise_info = getExercise(exercise_id,QStringList{"id","name","description","type","notes","muscles","equipments","icon"});
    QJsonArray muscles = QJsonArray::fromStringList(exercise_info["muscles"].toString().split(","));
    QJsonArray equipments = QJsonArray::fromStringList(exercise_info["equipments"].toString().split(","));
    QJsonObject exercise_json = qHashToJson(exercise_info);
    exercise_json["muscles"] = muscles;
    exercise_json["equipments"] = equipments;
    return exercise_json;
}
