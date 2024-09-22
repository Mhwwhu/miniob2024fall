#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/date_type.h"
#include "common/value.h"
#include <sstream>
#include <iomanip>
#include <iostream>

int DateType::compare(const Value& left, const Value& right) const
{
	ASSERT(left.attr_type() == AttrType::DATES, "left type is not date");
	ASSERT(right.attr_type() == AttrType::DATES, "right type is not date");
	if (left.attr_type() == AttrType::DATES && right.attr_type() == AttrType::DATES)
	{
		return common::compare_int((void*)&left.value_.date_value_, (void*)&right.value_.date_value_);
	}
	return INT32_MAX;
}

RC DateType::subtract(const Value& left, const Value& right, Value& result) const
{
	result.set_date(left.get_int() - right.get_int());
	return RC::SUCCESS;
}

RC DateType::set_value_from_str(Value& val, const string& data) const
{
	int year, month, day;
	sscanf(data.c_str(), "%d-%d-%d", &year, &month, &day);
	if (!checkDateValid(year, month, day)) {
		val.set_date(0);
		LOG_WARN("Failed to convert string to date");
		printf("#\n");
		return RC::SCHEMA_FIELD_TYPE_MISMATCH;
	}
	val.set_date(year << 9 | month << 5 | day);
	return RC::SUCCESS;
}

RC DateType::to_string(const Value& val, string& result) const
{
	stringstream ss;
	int date = val.get_date();
	ss << ((date >> 9) & 0x3fff)
		<< '-'
		<< ((date >> 5) & 0xf)
		<< '-'
		<< (date & 0x1f);
	result = ss.str();
	return RC::SUCCESS;
}

bool DateType::checkDateValid(int year, int month, int day) const
{
	if (year < startYear) return false;
	if (month <= 0 || month > 12) return false;
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day <= 0 || day > (month == 2 ? monthDay[month] + isLeap(year) : monthDay[month])) return false;
	return true;
}

int DateType::countLeapYears(int start, int end) const
{
	return ((end - 1) / 4 - (start - 1) / 4)
		- ((end - 1) / 100 - (start - 1) / 100)
		+ ((end - 1) / 400 - (start - 1) / 400);
}

int DateType::countDaysOffset(bool isLeap, int month, int day) const
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int count = -1;
	for (int i = 1; i < month; i++) {
		count += monthDay[i];
	}
	count += day;
	if (isLeap && month > 2) count++;
	return count;
}

bool DateType::isLeap(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}