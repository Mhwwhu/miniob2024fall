#include "sql/stmt/join_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/parser/expression_binder.h"
#include "sql/stmt/join_stmt.h"

JoinStmt::~JoinStmt()
{
	if (filter_stmt_ != nullptr) {
		delete filter_stmt_;
		filter_stmt_ = nullptr;
	}
	if (right_join_stmt_ != nullptr) {
		delete right_join_stmt_;
		right_join_stmt_ = nullptr;
	}
}
RC JoinStmt::create(Db* db, std::unordered_map<string, Table*>* table_map, JoinSqlNode& join_sql, Stmt*& stmt)
{
	if (nullptr == db) {
		LOG_WARN("invalid argument. db is null");
		return RC::INVALID_ARGUMENT;
	}
	const char* table_name = join_sql.leftTableName.c_str();
	if (table_name == nullptr) {
		LOG_WARN("invalid argument. relation name is null.");
		return RC::INVALID_ARGUMENT;
	}
	Table* table = db->find_table(join_sql.leftTableName.c_str());
	if (table == nullptr) {
		LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
		return RC::SCHEMA_TABLE_NOT_EXIST;
	}

	FilterStmt* filterStmt = nullptr;
	unordered_map<string, Table*> map;
	if (table_map == nullptr) {
		table_map = &map;
	}
	table_map->insert({ join_sql.leftTableName, table });
	RC rc = FilterStmt::create(
		db, nullptr, table_map, join_sql.conditions.data(), join_sql.conditions.size(), filterStmt);
	if (OB_FAIL(rc)) {
		LOG_WARN("cannot construct filter stmt");
		return rc;
	}
	Stmt* rightJoinStmt = nullptr;
	if (join_sql.rightTable != nullptr) {
		rc = JoinStmt::create(db, table_map, *join_sql.rightTable, rightJoinStmt);
		if (OB_FAIL(rc)) {
			LOG_WARN("failed to construct join stmt");
			return rc;
		}
	}
	JoinStmt* joinStmt = new JoinStmt();
	joinStmt->left_table_ = table;
	joinStmt->right_join_stmt_ = static_cast<JoinStmt*>(rightJoinStmt);
	joinStmt->filter_stmt_ = filterStmt;
	stmt = joinStmt;
	return rc;
}