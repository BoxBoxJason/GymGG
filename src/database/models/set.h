#ifndef DATABASE_MODELS_SET_H
#define DATABASE_MODELS_SET_H

#include <QString>
#include <QDateTime>
#include <QHash>
#include <QVariant>
#include <QVector>

// ===== POST FUNCTIONS ===== //
/*!
 * @brief createSet creates a new set
 * @param user_id the id of the user who did the set
 * @param workout_id the id of the workout the set was done in
 * @param exercise_id the id of the exercise done in the set
 * @param exercise_workout_id the id of the exercise in the workout
 * @return the id of the new set
 */
int createSet(int user_id,int workout_id, int exercise_id, int exercise_workout_id);

// ===== PUT FUNCTIONS ===== //
/*!
 * @brief setSetFields sets the fields of a set
 * @param set_id the id of the set
 * @param fields the fields to set
 * @return true if the fields were set successfully
 */
bool setSetFields(int set_id,const QHash<QString, QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
 * @brief getSet gets a set
 * @param set_id the id of the set
 * @param fields the fields to get
 * @return a hash of the fields and values of the set
 */
QHash<QString, QVariant> getSet(int set_id, const QStringList& fields=QStringList());
/*!
 * @brief getSets gets sets
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a hash of set ids and hashes of fields and values of the sets
 */
QHash<int,QHash<QString, QVariant>> getSets(const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields=QStringList());
/*!
 * @brief getSetsOrdered gets sets ordered by datetime
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the sets
 */
QVector<QHash<QString, QVariant>> getSetsOrdered(const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(),const QStringList& fields=QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
 * @brief deleteSet deletes a set based on id
 * @param set_id the id of the set
 * @return true if the set was deleted successfully
 */
bool deleteSet(int set_id);
/*!
 * @brief deleteSets deletes sets based on filters
 * @param filters the filters to match
 * @return true if the sets were deleted successfully
 */
bool deleteSets(const QHash<QString,QVariant>& filters);

#endif // DATABASE_MODELS_SET_H
