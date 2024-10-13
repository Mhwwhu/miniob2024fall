/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
		 http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

UpdateStmt::UpdateStmt(Table* table, const char* attr_name, Value value, FilterStmt* filter_stmt)
	: table_(table), attr_name_(attr_name), value_(value), filter_stmt_(filter_stmt)
{}
UpdateStmt::~UpdateStmt()
{
	if (nullptr != filter_stmt_) {
		delete filter_stmt_;
		filter_stmt_ = nullptr;
	}
}

RC UpdateStmt::create(Db* db, const UpdateSqlNode& update, Stmt*& stmt)
{
	if (nullptr == db) {
		LOG_WARN("invalid argument. db is null");
		return RC::INVALID_ARGUMENT;
	}

	const char* table_name = update.relation_name.c_str();
	if (table_name == nullptr) {
		LOG_WARN("invalid argument. table is null");
	}

	Table* table = db->find_table(table_name);
	if (table == nullptr) {
		LOG_WARN("no such table: %s", update.relation_name);
		return RC::SCHEMA_TABLE_NOT_EXIST;
	}

	std::unordered_map<std::string, Table*> table_map;
	table_map.insert(std::pair<std::string, Table*>(std::string(table_name), table));

	FilterStmt* filter_stmt = nullptr;
	RC rc = FilterStmt::create(
		db, table, &table_map, update.conditions.data(), static_cast<int>(update.conditions.size()), filter_stmt);
	if (rc != RC::SUCCESS) {
		LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
		return rc;
	}

	const char* attr_name = update.attribute_name.c_str();
	Value value = Value(std::move(update.value));
	stmt = new UpdateStmt(table, attr_name, value, filter_stmt);

	return rc;
}
