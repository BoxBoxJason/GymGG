#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QStringList>
#include "general.h"

bool createTableRow(const QString& table_name, const QHash<QString,QVariant>& fields) {
    QSqlQuery query;
    QStringList field_names;
    for (auto it = fields.begin(); it != fields.end(); ++it) {
        field_names << it.key();
    }
    query.prepare("INSERT INTO " + table_name + " (" + field_names.join(", ") + ") VALUES (:" + field_names.join(", :") + ")");
    for (auto it = fields.begin(); it != fields.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }
    return query.exec();
}


bool setTableRowFields(const QString& table_name, const QString& row_id, const QHash<QString,QVariant>& fields) {
    QSqlQuery query;
    QStringList field_names;
    for (auto it = fields.begin(); it != fields.end(); ++it) {
        field_names << it.key() + " = :" + it.key();
    }
    query.prepare("UPDATE " + table_name + " SET " + field_names.join(", ") + " WHERE id = :id");
    for (auto it = fields.begin(); it != fields.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }
    query.bindValue(":id", row_id);
    return query.exec();
}


QHash<QString,QVariant> getTableRow(const QString& table_name, const QString& row_id, const QStringList& fields) {
    QSqlQuery query;
    QStringList field_names;
    if (fields.isEmpty()) {
        field_names << "*";
    } else {
        field_names = fields;
    }

    query.prepare("SELECT " + field_names.join(", ") + " FROM " + table_name + " WHERE id = :id");
    query.bindValue(":id", row_id);
    QHash<QString,QVariant> row;

    if(query.exec()){
        if (!fields.isEmpty()){
            for (auto it = field_names.begin(); it != field_names.end(); ++it) {
                row[*it] = query.value(*it);
            }
        } else {
            for (int i = 0; i < query.record().count(); ++i) {
                row[query.record().fieldName(i)] = query.value(i);
            }
        }
    } else {
        row["error"] = query.lastError().text();
    }
    return row;
}


QHash<QString,QHash<QString,QVariant>> getTableRows(const QString& table_name,const QHash<QString,QVariant>& filters, const QStringList& fields) {
    QSqlQuery query;
    QStringList field_names;
    if (fields.isEmpty()) {
        field_names << "*";
    } else {
        field_names = fields;
    }

    QStringList filter_names;
    for (auto it = filters.begin(); it != filters.end(); ++it) {
        filter_names << it.key() + " = :" + it.key();
    }

    query.prepare("SELECT " + field_names.join(", ") + " FROM " + table_name + " WHERE " + filter_names.join(" AND "));
    for (auto it = filters.begin(); it != filters.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    QHash<QString,QHash<QString,QVariant>> rows;
    if(query.exec()){
        while (query.next()) {
            QHash<QString,QVariant> row;
            if (!fields.isEmpty()){
                for (auto it = field_names.begin(); it != field_names.end(); ++it) {
                    row[*it] = query.value(*it);
                }
            } else {
                for (int i = 0; i < query.record().count(); ++i) {
                    row[query.record().fieldName(i)] = query.value(i);
                }
            }
            rows[query.value("id").toString()] = row;
        }
    } else {
        QHash<QString,QVariant> row;
        row["error"] = query.lastError().text();
        rows["error"] = row;
    }
    return rows;
}


bool deleteTableRow(const QString& table_name, const QString& row_id) {
    QSqlQuery query;
    query.prepare("DELETE FROM " + table_name + " WHERE id = :id");
    query.bindValue(":id", row_id);
    return query.exec();
}


bool deleteTableRows(const QString& table_name, const QHash<QString,QVariant>& filters) {
    QSqlQuery query;
    QStringList filter_names;
    for (auto it = filters.begin(); it != filters.end(); ++it) {
        filter_names << it.key() + " = :" + it.key();
    }
    query.prepare("DELETE FROM " + table_name + " WHERE " + filter_names.join(" AND "));
    for (auto it = filters.begin(); it != filters.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }
    return query.exec();
}
