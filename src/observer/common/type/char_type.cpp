/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
		 http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "common/lang/comparator.h"
#include "common/log/log.h"
#include "common/type/char_type.h"
#include "common/value.h"

int CharType::compare(const Value& left, const Value& right) const
{
	ASSERT(left.attr_type() == AttrType::CHARS && right.attr_type() == AttrType::CHARS, "invalid type");
	return common::compare_string(
		(void*)left.value_.pointer_value_, left.length_, (void*)right.value_.pointer_value_, right.length_);
}

RC CharType::set_value_from_str(Value& val, const string& data) const
{
	val.set_string(data.c_str());
	return RC::SUCCESS;
}

RC CharType::cast_to(const Value& val, AttrType type, Value& result) const
{
	Value tmp;
	switch (type) {
	case AttrType::CHARS:
		result = val;
		return RC::SUCCESS;
	case AttrType::INTS:
		result = Value(atoi(val.get_string().c_str()));
		return RC::SUCCESS;
	case AttrType::FLOATS:
		result = Value((float)atof(val.get_string().c_str()));
		return RC::SUCCESS;
	case AttrType::DATES:
		if (OB_SUCC(DataType::type_instance(AttrType::DATES)->set_value_from_str(tmp, val.get_string()))) {
			result = tmp;
			return RC::SUCCESS;
		}
		return RC::UNSUPPORTED;
	default: return RC::UNSUPPORTED;
	}
	return RC::SUCCESS;
}

int CharType::cast_cost(AttrType type)
{
	if (type == AttrType::CHARS) {
		return 0;
	}
	if (type == AttrType::INTS) {
		return 1;
	}
	if (type == AttrType::FLOATS) {
		return 2;
	}
	if (type == AttrType::DATES) {
		return 3;
	}
	return INT32_MAX;
}

RC CharType::to_string(const Value& val, string& result) const
{
	stringstream ss;
	ss << val.value_.pointer_value_;
	result = ss.str();
	return RC::SUCCESS;
}