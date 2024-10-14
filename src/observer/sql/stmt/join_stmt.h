#pragma once

#include <memory>
#include <vector>
#include <unordered_map>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

class JoinStmt : public Stmt
{
public:
	JoinStmt() = default;
	~JoinStmt() override;
	StmtType type() const override { return StmtType::JOIN; }
public:
	static RC create(Db* db, std::unordered_map<string, Table*>* table_map, JoinSqlNode& join_sql, Stmt*& stmt);
public:
	const Table* left_table() const { return left_table_; }
	FilterStmt* filter_stmt() const { return filter_stmt_; }
	JoinStmt* right_join_stmt() const { return right_join_stmt_; }
private:
	Table* left_table_ = nullptr;
	JoinStmt* right_join_stmt_ = nullptr;
	FilterStmt* filter_stmt_ = nullptr;
};