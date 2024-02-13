#ifndef DATABASE_MODELS_EXERCISEWORKOUT_H
#define DATABASE_MODELS_EXERCISEWORKOUT_H

#include <QString>
#include <QHash>
#include <QVariant>
#include <QStringList>
#include <QDateTime>
#include <QVector>

// ===== POST FUNCTIONS ===== //
/*!
    * \brief createExerciseWorkout Creates a new exercise workout
    * \param user_id The id of the user who did the workout
    * \param workout_id The id of the workout the exercise is part of
    * \param exercise_id The id of the exercise
    * \param datetime The date and time the exercise was done
    * \param notes Any notes about the exercise
    * \return The id of the new exercise workout
*/
int createExerciseWorkout(int user_id, int workout_id, int exercise_id,const QDateTime& datetime,const QString& notes);

// ===== PUT FUNCTIONS ===== //
/*!
    * \brief setExerciseWorkoutFields Updates the fields of an exercise workout
    * \param exercise_workout_id The id of the exercise workout to update
    * \param fields A hash of field names and values to update in the exercise workout
    * \return True if the exercise workout was updated successfully, false otherwise
*/
bool setExerciseWorkoutFields(int exercise_workout_id, const QHash<QString,QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
    * \brief getExerciseWorkout Retrieves an exercise workout given its id
    * \param exercise_workout_id The id of the exercise workout to retrieve
    * \param fields A list of field names to retrieve from the exercise workout. If empty, all fields will be retrieved
    * \return A hash of field names and values from the exercise workout
*/
QHash<QString,QVariant> getExerciseWorkout(int exercise_workout_id,const QStringList& fields = QStringList());
/*!
    * \brief getExerciseWorkouts Retrieves exercise workouts given filters to match
    * \param filters A hash of field names and values to filter the exercise workouts by
    * \param fields A list of field names to retrieve from the exercise workouts. If empty, all fields will be retrieved
    * \return A list of hashes of field names and values from the exercise workouts
*/
QVector<QHash<QString,QVariant>> getExerciseWorkouts(const QHash<QString,QVariant>& filters=QHash<QString,QVariant>(),const QStringList& fields = QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
    * \brief deleteExerciseWorkout Deletes an exercise workout given its id
    * \param exercise_workout_id The id of the exercise workout to delete
    * \return True if the exercise workout was deleted successfully, false otherwise
*/
bool deleteExerciseWorkout(int exercise_workout_id);
/*!
    * \brief deleteExerciseWorkouts Deletes exercise workouts given filters to match
    * \param filters A hash of field names and values to filter the exercise workouts by
    * \return True if the exercise workouts were deleted successfully, false otherwise
*/
bool deleteExerciseWorkouts(const QHash<QString,QVariant>& filters);

#endif // DATABASE_MODELS_EXERCISEWORKOUT_H
