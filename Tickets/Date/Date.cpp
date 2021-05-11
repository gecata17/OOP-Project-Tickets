#include "Date.h"

Date::Date()
{
    this->date = "";
}

Date::Date(const String &date)
{
    this->date = date;
}

// Date::Date(int year, int month, int day)
// {
//     String monthString = to_string(month);
//     String dayString = to_string(day);

// 		if (month < 10) {
// 			monthString= "0" + monthString;
// 		}
// 		if (day < 10) {
// 			dayString = "0" + dayString;
// 		}

// 		date = to_string(year) + "-" + monthString + "-" + dayString;
// }

bool Date::operator==(const Date &other) const
{
    return this->date == other.date;
}

// "2000-01-11" < "2018-03-05"
// "2020-08-07" < "2021-08-07"
bool Date::operator<(const Date &other) const
{
    return this->date < other.date;
}

bool Date::operator<=(const Date &other) const
{
    return this->date <= other.date;
}

bool Date::operator>(const Date &other) const
{
    return this->date > other.date;
}

bool Date::operator>=(const Date &other) const
{
    return this->date >= other.date;
}

std::istream &operator>>(std::istream &in, Date &other)
{
  in >> other.date;
  return in;
}


std::ostream &operator<<(std::ostream &out, const Date &other)
{
  out << other.date;
  return out;
}
