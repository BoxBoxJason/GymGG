#ifndef DATABASE_MODELS_EQUIPMENTS_H
#define DATABASE_MODELS_EQUIPMENTS_H

#include <QString>
#include <QStringList>

// ===== POST FUNCTIONS ===== //
/*!
    * \brief createEquipment Creates a new equipment
    * \param name The name of the equipment
    * \return The id of the new equipment
*/
int createEquipment(const QString& name);

// ===== GET FUNCTIONS ===== //
/*!
    * \brief getEquipments Retrieves all equipments
    * \return A list of all equipment names
*/
QStringList getEquipments();

#endif // DATABASE_MODELS_EQUIPMENTS_H
