#ifndef DATABASE_MODELS_MUSCLES_H
#define DATABASE_MODELS_MUSCLES_H

#include <QString>
#include <QStringList>

// ===== POST FUNCTIONS ===== //
/*!
    * \brief createMuscle Creates a new muscle
    * \param name The name of the muscle
    * \return The id of the new muscle
*/
int createMuscle(const QString& name);

// ===== GET FUNCTIONS ===== //
/*!
    * \brief getMuscles Retrieves all muscles
    * \return A list of all muscle names
*/
QStringList getMuscles();

#endif // DATABASE_MODELS_MUSCLES_H
