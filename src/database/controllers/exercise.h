#ifndef DATABASE_CONTROLLERS_EXERCISE_H
#define DATABASE_CONTROLLERS_EXERCISE_H

#include <QJsonArray>
#include <QJsonObject>
#include <QVector>

QJsonArray getExercisesJsonWorkoutTemplate(const QJsonArray& raw_workout_exercises);

QJsonObject getExerciseJson(int exercise_id);

#endif // DATABASE_CONTROLLERS_EXERCISE_H
