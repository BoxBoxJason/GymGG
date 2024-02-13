#ifndef DATABASE_MODELS_GENERAL_H
#define DATABASE_MODELS_GENERAL_H

#include <QString>
#include <QStringList>
#include <QHash>
#include <QVariant>
#include <QVector>

// ===== POST FUNCTIONS ===== //
/*!
    * \brief createTableRow Inserts a new row into a database table
    * \param table_name Name of the database table to insert the row into
    * \param fields A hash of field names and values to insert into the row
    * \return True if the row was inserted successfully, false otherwise
*/
int createTableRow(const QString& table_name, const QHash<QString,QVariant>& fields);

// ===== PUT FUNCTIONS ===== //
/*!
    * \brief setTableRowFields Updates the fields of a row in a database table
    * \param table_name Name of the database table to update the row in
    * \param row_id The id of the row to update
    * \param fields A hash of field names and values to update in the row
    * \return True if the row was updated successfully, false otherwise
*/
bool setTableRowFields(const QString& table_name, int row_id, const QHash<QString,QVariant>& fields);

// ===== GET FUNCTIONS ===== //
/*!
    * \brief getTableRow Retrieves a row given its id from a database table
    * \param table_name Name of the database table to retrieve the row from
    * \param row_id The id of the row to retrieve
    * \param fields A list of field names to retrieve from the row. If empty, all fields will be retrieved
    * \return A hash of field names and values from the row
*/
QHash<QString,QVariant> getTableRow(const QString& table_name, int row_id, const QStringList& fields = QStringList());
/*!
    * \brief getTableRow Retrieves a row given filters from a database table
    * \param table_name Name of the database table to retrieve the row from
    * \param filters A hash of field names and values to filter the row by
    * \param fields A list of field names to retrieve from the row. If empty, all fields will be retrieved
    * \return A hash of field names and values from the row
*/
QHash<QString,QVariant> getTableRow(const QString& table_name, const QHash<QString,QVariant>& filters, const QStringList& fields = QStringList());
/*!
    \brief getTableRows Retrieves rows given their id from a database table
    \param table_name Name of the database table to retrieve the rows from
    \param row_ids List of ids of rows to retrieve
    \param fields A list of field names to retrieve from the rows. If empty, all fields will be retrieved
    \return A hash of row ids and hashes of field names and values from the rows
*/
QHash<int,QHash<QString,QVariant>> getTableRows(const QString& table_name, const QVector<int>& row_ids, const QStringList& fields = QStringList());
/*!
    * \brief getTableRows Retrieves rows given filters to match from a database table
    * \param table_name Name of the database table to retrieve the rows from
    * \param filters A hash of field names and values to filter the rows by
    * \param fields A list of field names to retrieve from the rows. If empty, all fields will be retrieved
    * \return A hash of row ids and hashes of field names and values from the rows
*/
QHash<int,QHash<QString,QVariant>> getTableRows(const QString& table_name,const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields = QStringList());
/*!
    * \brief getTableOrderedRows Retrieves rows given filters to match from a database table and orders them by a field
    * \param table_name Name of the database table to retrieve the rows from
    * \param order_by Name of the field to order the rows by
    * \param filters A hash of field names and values to filter the rows by
    * \param fields A list of field names to retrieve from the rows. If empty, all fields will be retrieved
    * \param order Order of the rows. Can be "ASC" or "DESC"
    * \return A hash of row ids and hashes of field names and values from the rows
*/
QVector<QHash<QString,QVariant>> getTableOrderedRows(const QString& table_name, const QString& order_by, const QHash<QString,QVariant>& filters = QHash<QString,QVariant>(), const QStringList& fields = QStringList(),const QString& order = "ASC");
/*!
    * \brief getTableRowsPartialFilter Retrieves rows given a partial text filter to match from a database table
    * \param table_name Name of the database table to retrieve the rows from
    * \param filter_name Name of the field to filter the rows by
    * \param value Value to filter the rows by
    * \param fields A list of field names to retrieve from the rows. If empty, all fields will be retrieved
    * \return A hash of row ids and hashes of field names and values from the rows
*/
QHash<int,QHash<QString,QVariant>> getTableRowsPartialFilter(const QString& table_name, const QString& filter_name, const QString& value, const QStringList& fields = QStringList());

// ===== DELETE FUNCTIONS ===== //
/*!
    * \brief deleteTableRow Deletes a row given its id from a database table
    * \param table_name Name of the database table to delete the row from
    * \param row_id The id of the row to delete
    * \return True if the row was deleted successfully, false otherwise
*/
bool deleteTableRow(const QString& table_name, int row_id);
/*!
    * \brief deleteTableRows Deletes rows given filters to match from a database table
    * \param table_name Name of the database table to delete the rows from
    * \param filters A hash of field names and values to filter the rows by
    * \return True if the rows were deleted successfully, false otherwise
*/
bool deleteTableRows(const QString& table_name, const QHash<QString,QVariant>& filters);

#endif // DATABASE_MODELS_GENERAL_H
