#pragma once

#include "String.h"
#include <iostream>

class Date
{
private:
	size_t year;
	size_t day;
	size_t month;
	String intToString(size_t n) const;
    size_t reverse(size_t num) const;
	// YYYY-MM-DD

public:
	Date();
	Date(const Date&);
	Date(size_t year, size_t month, size_t day);

	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator>=(const Date& other) const;

	friend std::istream& operator>>(std::istream& in, Date& other);
	friend std::ostream& operator<<(std::ostream& out, const Date& other);
};

