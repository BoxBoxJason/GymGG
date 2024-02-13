#include "equipment.h"
#include "general.h"

int createEquipment(const QString& name){
    return createTableRow("Equipments",QHash<QString,QVariant>{{"name",name}});
}


QStringList getEquipments(){
    QStringList equipments;
    QHash<int,QHash<QString,QVariant>> rows = getTableRows("Equipments",QHash<QString, QVariant>(),QStringList{"name"});
    for (auto row : rows){
        equipments.append(row["name"].toString());
    }
    return equipments;
}
