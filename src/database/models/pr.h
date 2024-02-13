#ifndef DATABASE_MODELS_PR_H
#define DATABASE_MODELS_PR_H

#include <QString>
#include <QDateTime>
#include <QHash>
#include <QVector>

// ===== POST FUNCTIONS ===== //
/*!
 * @brief createPR creates a new PR
 * @param user_id the id of the user
 * @param workout_id the id of the workout
 * @param exercise_id the id of the exercise
 * @param exercise_workout_id the id of the exercise workout
 * @param set_id the id of the set
 * @param datetime the date and time of the PR
 * @param type the type of the PR
 * @param value the value of the PR
 * @return the id of the new PR
 */
int createPR(int user_id, int workout_id, int exercise_id, int exercise_workout_id, int set_id,const QDateTime& datetime,const QString& type, float value);

// ===== PUT FUNCTIONS ===== //
/*!
 * @brief setPRFields sets the fields of a PR
 * @param pr_id the id of the PR
 * @param fields the fields to set
 * @return true if the fields were set successfully
 */
bool setPRFields(int pr_id, const QHash<QString, QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
 * @brief getPR gets a PR
 * @param pr_id the id of the PR
 * @param fields the fields to get
 * @return a hash of the fields and values of the PR
 */
QHash<QString, QVariant> getPR(int pr_id, const QStringList& fields=QStringList());
/*!
 * @brief getPRs gets PRs
 * @param prs_ids the ids of the PRs to retrieve
 * @param fields the fields to get
 * @return a hash of PR ids and hashes of fields and values of the PRs
 */
QHash<int,QHash<QString,QVariant>> getPRs(const QVector<int>& prs_ids, const QStringList& fields = QStringList());
/*!
 * @brief getPRs gets PRs
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a hash of PR ids and hashes of fields and values of the PRs
 */
QHash<int,QHash<QString, QVariant>> getPRs(const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields=QStringList());
/*!
 * @brief getPRsOrdered gets PRs ordered by date
 * @param filters the filters to match
 * @param fields the fields to get
 * @return a list of hashes of fields and values of the PRs
 */
QVector<QHash<QString, QVariant>> getPRsOrdered(const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields=QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
 * @brief deletePR deletes a PR
 * @param pr_id the id of the PR
 * @return true if the PR was deleted successfully
 */
bool deletePR(int pr_id);

#endif // DATABASE_MODELS_PR_H
