#ifndef DATABASE_MODELS_GENERAL_H
#define DATABASE_MODELS_GENERAL_H

#include <QString>
#include <QStringList>
#include <QHash>
#include <QVariant>

bool createTableRow(const QString& table_name, const QHash<QString,QVariant>& fields);

bool setTableRowFields(const QString& table_name, const QString& row_id, const QHash<QString,QVariant>& fields);

QHash<QString,QVariant> getTableRow(const QString& table_name, const QString& row_id, const QStringList& fields = QStringList());
QHash<QString,QHash<QString,QVariant>> getTableRows(const QString& table_name,const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields = QStringList());

bool deleteTableRow(const QString& table_name, const QString& row_id);
bool deleteTableRows(const QString& table_name, const QHash<QString,QVariant>& filters);

#endif // DATABASE_MODELS_GENERAL_H
