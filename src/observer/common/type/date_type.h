
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

	static bool str_to_date(const char* str, int& date_i);
private:
	static const int startYear = 1000;
	static bool checkDateValid(int year, int month, int day);
	static int countLeapYears(int start, int end);
	static int countDaysOffset(bool isLeap, int month, int day);
	static bool isLeap(int year);
};