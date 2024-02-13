#ifndef DATABASE_MODELS_WORKOUTTEMPLATE_H
#define DATABASE_MODELS_WORKOUTTEMPLATE_H

#include <QString>
#include <QHash>

// ===== POST FUNCTIONS ===== //
/*!
 * @brief createWorkoutTemplate creates a new workout template
 * @param name the name of the workout template
 * @param description the description of the workout template
 * @param type the type of the workout template
 * @param notes the notes of the workout template
 * @param icon the icon of the workout template
 * @param exercises the exercises of the workout template
 * @param user_id the id of the user who created the workout template
 * @return the id of the new workout template
 */
int createWorkoutTemplate(const QString& name, const QString& description, const QString& type, const QString& notes, const QString& icon, const QString& exercises,int user_id=-1);

// ===== PUT FUNCTIONS ===== //
/*!
 * @brief setWorkoutTemplateFields sets the fields of a workout template
 * @param workout_template_id the id of the workout template
 * @param fields the fields to set
 * @return true if the fields were set successfully
 */
bool setWorkoutTemplateFields(int workout_template_id, const QHash<QString,QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
 * @brief getWorkoutTemplate gets a workout template
 * @param workout_template_id the id of the workout template
 * @param fields the fields to get
 * @return a hash of the fields and values of the workout template
 */
QHash<QString,QVariant> getWorkoutTemplate(int workout_template_id,const QStringList& fields = QStringList());
/*!
 * @brief getWorkoutTemplates gets workout templates
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a hash of workout template ids and hashes of fields and values of the workout templates
 */
QHash<int,QHash<QString,QVariant>> getWorkoutTemplates(const QHash<QString,QVariant>& filters=QHash<QString,QVariant>(),const QStringList& fields = QStringList());
/*!
 * @brief getWorkoutTemplatesOrdered gets workout templates ordered by name
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the workout templates
 */
QHash<int,QHash<QString,QVariant>> getWorkoutTemplatesFromPartialName(const QString& partial_name,const QStringList& fields = QStringList());
/*!
 * @brief getWorkoutTemplatesWithExercise gets workout templates with a specific exercise
 * @param exercise_id the id of the exercise
 * @param fields the fields to get
 * @return a hash of workout template ids and hashes of fields and values of the workout templates
 */
QHash<int,QHash<QString,QVariant>> getWorkoutTemplatesWithExercise(int exercise_id,const QStringList& fields = QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
 * @brief deleteWorkoutTemplate deletes a workout template based on id
 * @param workout_template_id the id of the workout template
 * @return true if the workout template was deleted successfully
 */
bool deleteWorkoutTemplate(int workout_template_id);
/*!
 * @brief deleteWorkoutTemplates deletes workout templates based on filters
 * @param filters the filters to match
 * @return true if the workout templates were deleted successfully
 */
bool deleteWorkoutTemplates(const QHash<QString,QVariant>& filters);

#endif // DATABASE_MODELS_WORKOUTTEMPLATE_H
