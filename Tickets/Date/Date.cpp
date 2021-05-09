#include "Date.h"

Date::Date()
{
    this->date = "";
}

Date::Date(const String &date)
{
    this->date = date;
}

Date::Date(int year, int month, int day)
{
    String monthString = to_string(month);
}

bool Date::operator==(const Date &other) const
{
    return this->date == other.date;
}

bool Date ::operator<(const Date &other) const
{
    return this->date < other.date;
}
