#pragma once

#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

class UpdateLogicalOperator : public LogicalOperator
{
public:
	UpdateLogicalOperator(Table* table, string attr_name, Value value);
	virtual ~UpdateLogicalOperator() = default;

	LogicalOperatorType type() const override { return LogicalOperatorType::UPDATE; }

	Table* table() const { return table_; }
	string attr_name() const { return attr_name_; }
	Value value() const { return value_; }
private:
	Table* table_ = nullptr;
	string attr_name_;
	Value value_;
};