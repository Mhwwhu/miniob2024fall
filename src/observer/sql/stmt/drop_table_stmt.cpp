#include "common/log/log.h"
#include "common/types.h"
#include "sql/stmt/drop_table_stmt.h"
#include "event/sql_debug.h"
#include "storage/db/db.h"

using namespace common;

RC DropTableStmt::create(Db* db, DropTableSqlNode& drop_table, Stmt*& stmt)
{
	const char* table_name = drop_table.relation_name.c_str();
	if (db == nullptr || table_name == nullptr) {
		LOG_WARN("invalid argument. db is %p, table = %s", db, table_name);
		return RC::INVALID_ARGUMENT;
	}
	//check whether the table exists
	Table* table = db->find_table(table_name);
	if (table == nullptr)
	{
		LOG_WARN("no such table: db = %d, table = %s", db->name(), table_name);
		return RC::SCHEMA_TABLE_NOT_EXIST;
	}
	stmt = new DropTableStmt(table);
	sql_debug("drop table statement: table name is %s", table_name);
	return RC::SUCCESS;
}