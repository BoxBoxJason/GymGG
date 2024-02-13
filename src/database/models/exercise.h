#ifndef DATABASE_MODELS_EXERCISE_H
#define DATABASE_MODELS_EXERCISE_H

#include <QString>
#include <QHash>
#include <QVariant>
#include <QStringList>
#include <QVector>

// ===== POST FUNCTIONS ===== //
/*!
 * @brief createExercise creates a new exercise
 * @param name the name of the exercise
 * @param description the description of the exercise
 * @param type the type of the exercise
 * @param notes the notes of the exercise
 * @param muscles the muscles worked by the exercise
 * @param equipments the equipments used in the exercise
 * @param icon the icon of the exercise
 * @return the id of the new exercise
 */
int createExercise(const QString& name, const QString& description, const QString& type, const QString& notes, const QStringList& muscles=QStringList(), const QStringList& equipments=QStringList(), const QString& icon="default.png");

// ===== PUT FUNCTIONS ===== //
/*!
 * @brief setExerciseFields sets the fields of an exercise
 * @param exercise_id the id of the exercise
 * @param fields the fields to set
 * @return true if the fields were set successfully
 */
bool setExerciseFields(int exercise_id,const QHash<QString, QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
 * @brief getExercise gets an exercise
 * @param exercise_id the id of the exercise
 * @param fields the fields to get
 * @return a hash of the fields and values of the exercise
 */
QHash<QString, QVariant> getExercise(int exercise_id, const QStringList& fields=QStringList());
/*!
 * @brief getExercises gets exercises
 * @param exercises_ids the ids of the exercises to retrieve
 * @param fields the fields to get
 * @return a hash of exercise ids and hashes of fields and values of the exercises
 */
QHash<int,QHash<QString,QVariant>> getExercises(const QVector<int>& exercises_ids, const QStringList& fields = QStringList());
/*!
 * @brief getExercises gets exercises
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a hash of exercise ids and hashes of fields and values of the exercises
 */
QHash<int,QHash<QString, QVariant>> getExercises(const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields=QStringList());
/*!
 * @brief getExercisesOrdered gets exercises ordered by name
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the exercises
 */
QVector<QHash<QString, QVariant>> getExercisesOrdered(const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(),const QStringList& fields=QStringList());
/*!
 * @brief getExercisesFromPartialName gets exercises with names containing a partial name
 * @param partial_name the partial name to match
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the exercises
 */
QVector<QHash<QString,QVariant>> getExercisesFromPartialName(const QString& partial_name, const QHash<QString,QVariant>& filters=QHash<QString,QVariant>(),const QStringList& fields=QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
 * @brief deleteExercise deletes an exercise based on id
 * @param exercise_id the id of the exercise
 * @return true if the exercise was deleted successfully
 */
bool deleteExercise(int exercise_id);

#endif // DATABASE_MODELS_EXERCISE_H
