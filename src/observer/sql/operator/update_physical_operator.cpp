#include "sql/operator/update_physical_operator.h"
#include "sql/stmt/update_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

RC UpdatePhysicalOperator::open(Trx* trx)
{
	if (children_.empty()) {
		return RC::SUCCESS;
	}

	std::unique_ptr<PhysicalOperator>& child = children_[0];

	RC rc = child->open(trx);
	if (rc != RC::SUCCESS) {
		LOG_WARN("failed to open child operator: %s", strrc(rc));
		return rc;
	}

	trx_ = trx;

	while (OB_SUCC(rc = child->next())) {
		Tuple* tuple = child->current_tuple();
		if (nullptr == tuple) {
			LOG_WARN("failed to get current record: %s", strrc(rc));
			return rc;
		}

		RowTuple* row_tuple = static_cast<RowTuple*>(tuple);
		Record& record = row_tuple->record();
		records_.emplace_back(std::move(record));
	}
	child->close();
	const FieldMeta* fieldMeta = table_->table_meta().field(attr_name_.c_str());
	if (fieldMeta == nullptr) {
		LOG_WARN("unknown field: %s", attr_name_);
		return RC::NOT_EXIST;
	}
	int offset = fieldMeta->offset();
	int len = std::min(fieldMeta->len(), value_.length());
	for (Record& record : records_) {
		Record newRecord = record;
		memset(newRecord.data() + offset, 0, fieldMeta->len());
		memcpy(newRecord.data() + offset, value_.data(), len);
		rc = trx_->update_record(table_, record, newRecord);
		if (rc != RC::SUCCESS) {
			LOG_WARN("failed to update record: %s", strrc(rc));
			return rc;
		}
	}

	return RC::SUCCESS;
}

RC UpdatePhysicalOperator::next()
{
	return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close()
{
	return RC::SUCCESS;
}