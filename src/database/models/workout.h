#ifndef DATABASE_MODELS_WORKOUT_H
#define DATABASE_MODELS_WORKOUT_H

#include <QString>
#include <QVariant>
#include <QDateTime>
#include <QHash>

// ===== POST FUNCTIONS ===== //
/*!
 * @brief createWorkout creates a new workout
 * @param name the name of the workout
 * @param user_id the id of the user who did the workout
 * @param date the date of the workout
 * @param notes the notes of the workout
 * @param type the type of the workout
 * @param template_id the id of the template used for the workout
 * @return the id of the new workout
 */
int createWorkout(const QString& name, int user_id, const QDateTime& date, const QString& notes, const QString& type, int template_id);

// ===== PUT FUNCTIONS ===== //
/*!
 * @brief setWorkoutFields sets the fields of a workout
 * @param workout_id the id of the workout
 * @param fields the fields to set
 * @return true if the fields were set successfully
 */
bool setWorkoutFields(int workout_id,const QHash<QString, QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
 * @brief getWorkout gets a workout
 * @param workout_id the id of the workout
 * @param fields the fields to get
 * @return a hash of the fields and values of the workout
 */
QHash<QString, QVariant> getWorkout(int workout_id);
/*!
 * @brief getWorkouts gets workouts
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a hash of workout ids and hashes of fields and values of the workouts
 */
QHash<int, QHash<QString, QVariant>> getWorkouts(const QHash<QString, QVariant>& filters= QHash<QString, QVariant>(), const QStringList& fields=QStringList());
/*!
 * @brief getWorkoutsOrdered gets workouts ordered by date
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the workouts
 */
QVector<QHash<QString, QVariant>> getWorkoutsOrdered(const QHash<QString, QVariant>& filters= QHash<QString,QVariant>(), const QStringList& fields=QStringList());
/*!
 * @brief getUserWorkouts gets workouts for a user
 * @param user_id the id of the user
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the workouts
 */
QVector<QHash<QString, QVariant>> getUserWorkouts(int user_id, const QStringList& fields=QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
 * @brief deleteWorkout deletes a workout based on id
 * @param workout_id the id of the workout
 * @return true if the workout was deleted successfully
 */
bool deleteWorkout(int workout_id);
/*!
 * @brief deleteWorkouts deletes workouts based on filters
 * @param filters the filters to match
 * @return true if the workouts were deleted successfully
 */
bool deleteWorkouts(const QHash<QString, QVariant>& filters);

#endif // DATABASE_MODELS_WORKOUT_H
