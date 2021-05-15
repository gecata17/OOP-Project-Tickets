#include "Date.h"

String Date::intToString(size_t n) const 
{
    String result;
    while (n > 10) {
        result.pushBack(n % 10 + '0');
        n /= 10;
    }
    result.pushBack(n + '0');

    return result;
}

size_t Date::reverse(size_t num) const
{
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        return result;
    
}

Date::Date()
{
    this->date = "";
}

Date::Date(const String& date)
{
    this->date = date;
}

 Date::Date(size_t year, size_t month, size_t day)
 {
     if (month < 0 || month > 12) {
         
         std::cout << "Invalid month" << std::endl;
         return;
     }
     if (day < 0 || day > 31) {
         std::cout << "Invalid day" << std::endl;
         return;
     }
     String monthString = intToString(reverse(month));
     String dayString = intToString(reverse(day));

 	//date = intToString(reverse(year)) + "-" + monthString + "-" + dayString;
 }

// bool Date::operator==(const Date &other) const
// {
//     return this->date == other.date;
// }

// // "2000-01-11" < "2018-03-05"
// // "2020-08-07" < "2021-08-07"
// bool Date::operator<(const Date &other) const
// {
//     return this->date < other.date;
// }

// bool Date::operator<=(const Date &other) const
// {
//     return this->date <= other.date;
// }

// bool Date::operator>(const Date &other) const
// {
//     return this->date > other.date;
// }

// bool Date::operator>=(const Date &other) const
// {
//     return this->date >= other.date;
// }

std::istream& operator>>(std::istream& in, Date& other)
{
    in >> other.date;
    return in;
}


std::ostream& operator<<(std::ostream& out, const Date& other)
{
    out << other.date;
    return out;
}
