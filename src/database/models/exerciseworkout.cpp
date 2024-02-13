#include "exerciseworkout.h"
#include "general.h"

int createExerciseWorkout(int user_id, int workout_id, int exercise_id,const QDateTime& datetime,const QString& notes){
    return createTableRow("ExerciseWorkouts",QHash<QString,QVariant>({
        {"user_id",user_id},
        {"workout_id",workout_id},
        {"exercise_id",exercise_id},
        {"datetime",datetime},
        {"notes",notes}
        }));
}


bool setExerciseWorkoutFields(int exercise_workout_id, const QHash<QString,QVariant>& fields){
    return setTableRowFields("ExerciseWorkouts",exercise_workout_id,fields);
}


QHash<QString,QVariant> getExerciseWorkout(int exercise_workout_id,const QStringList& fields){
    return getTableRow("ExerciseWorkouts",exercise_workout_id,fields);
}


QVector<QHash<QString,QVariant>> getExerciseWorkouts(const QHash<QString,QVariant>& filters,const QStringList& fields){
    return getTableOrderedRows("ExerciseWorkouts","datetime",filters,fields);
}


bool deleteExerciseWorkout(int exercise_workout_id){
    return deleteTableRow("ExerciseWorkouts",exercise_workout_id);
}


bool deleteExerciseWorkouts(const QHash<QString,QVariant>& filters){
    return deleteTableRows("ExerciseWorkouts",filters);
}
