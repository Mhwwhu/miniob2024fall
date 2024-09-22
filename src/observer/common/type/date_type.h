
#pragma once

#include "common/type/data_type.h"

/**
 * @brief 日期类型
 * @ingroup DataType
 */

class DateType : public DataType
{
public:
	DateType() : DataType(AttrType::DATES) {}
	virtual ~DateType() {}

	int compare(const Value& left, const Value& right) const override;

	RC subtract(const Value& left, const Value& right, Value& result) const override;

	RC set_value_from_str(Value& val, const string& data) const override;

	RC to_string(const Value& val, string& result) const override;
private:
	const int startYear = 1000;
	bool checkDateValid(int year, int month, int day) const;
	int countLeapYears(int start, int end) const;
	int countDaysOffset(bool isLeap, int month, int day) const;
	bool isLeap(int year) const;
};