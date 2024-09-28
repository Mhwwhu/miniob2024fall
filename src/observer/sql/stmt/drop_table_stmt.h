#pragma once

#include <string>
#include <vector>

#include "sql/stmt/stmt.h"

class Db;
class Table;

/**
 * @brief 表示删除表的语句
 * @ingroup Statement
 * @details 虽然解析成了stmt，但是与原始的SQL解析后的数据也差不多
 */
class DropTableStmt : public Stmt
{
public:
	DropTableStmt(Table* table) : _table(table) {}
	virtual ~DropTableStmt() = default;
	Table* GetTable() const { return _table; }
	StmtType type() const { return StmtType::DROP_TABLE; }
	static RC create(Db* db, DropTableSqlNode& drop_table, Stmt*& stmt);
private:
	Table* _table;
};