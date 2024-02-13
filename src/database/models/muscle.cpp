#include "muscle.h"
#include "general.h"

int createMuscle(const QString& name){
    return createTableRow("Muscles",QHash<QString,QVariant>{{"name",name}});
}


QStringList getMuscles(){
    QStringList muscles;
    QHash<int,QHash<QString,QVariant>> rows = getTableRows("Muscles",QHash<QString,QVariant>(),QStringList{"name"});
    for (auto row : rows){
        muscles.append(row["name"].toString());
    }
    return muscles;
}
