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
// Created by Wangyunlai.wyl on 2021/5/18.
//

#include "storage/index/index_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "storage/field/field_meta.h"
#include "storage/table/table_meta.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_FIELD_NAME("field_name_list");

RC IndexMeta::init(const char* name, const vector<const FieldMeta*>& field_list)
{
	if (common::is_blank(name)) {
		LOG_ERROR("Failed to init index, name is empty.");
		return RC::INVALID_ARGUMENT;
	}

	name_ = name;
	for (auto field : field_list) {
		field_list_.push_back(field);
	}
	return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value& json_value) const
{
	auto jsonArray = Json::Value(Json::arrayValue);
	for (auto field : field_list_) {
		Json::Value element;
		field->to_json(element);
		jsonArray.append(element);
	}
	json_value[FIELD_NAME] = name_;
	json_value[FIELD_FIELD_NAME] = jsonArray;
}

RC IndexMeta::from_json(const TableMeta& table, const Json::Value& json_value, IndexMeta& index)
{
	const Json::Value& name_value = json_value[FIELD_NAME];
	const Json::Value& field_list_value = json_value[FIELD_FIELD_NAME];
	if (!name_value.isString()) {
		LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
		return RC::INTERNAL;
	}

	if (!field_list_value.isArray()) {
		LOG_ERROR("Field name of index [%s] is not an array. json value=%s",
			name_value.asCString(), field_list_value.toStyledString().c_str());
		return RC::INTERNAL;
	}
	vector<const FieldMeta*> field_list;
	for (auto fieldMeta : field_list_value) {
		FieldMeta field;
		if (FieldMeta::from_json(fieldMeta, field) != RC::SUCCESS) {
			LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), fieldMeta["name"].asCString());
			return RC::SCHEMA_FIELD_MISSING;
		}
		field_list.push_back(table.field(field.name()));
	}

	return index.init(name_value.asCString(), field_list);
}

const char* IndexMeta::name() const { return name_.c_str(); }

const vector<const FieldMeta*>& IndexMeta::field_list() const { return field_list_; }

void IndexMeta::desc(ostream& os) const
{
	stringstream field_names;
	for (auto field : field_list_) {
		field_names << field->name() << " ";
	}
	os << "index name=" << name_ << ", field=" << field_names.str();
}