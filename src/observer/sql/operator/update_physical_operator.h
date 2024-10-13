#pragma once

#include "sql/operator/physical_operator.h"
#include "sql/parser/parse.h"

class UpdateStmt;

/**
 * @brief 更新物理算子
 * @ingroup PhysicalOperator
 */
class UpdatePhysicalOperator : public PhysicalOperator
{
public:
	UpdatePhysicalOperator(Table* table, string attr_name, Value value)
		: table_(table), attr_name_(attr_name), value_(value) {}
	virtual ~UpdatePhysicalOperator() = default;
	PhysicalOperatorType type() const override { return PhysicalOperatorType::UPDATE; }

	RC open(Trx* trx) override;
	RC next() override;
	RC close() override;

private:
	Table* table_ = nullptr;
	string attr_name_;
	Value value_;
	Trx* trx_;
	vector<Record> records_;
};