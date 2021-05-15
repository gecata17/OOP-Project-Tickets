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

    this->year = 0;
    this->month = 0;
    this->day = 0;
}

Date::Date(const Date& other)
{
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
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

     this->year=year;
     this->month = month;
     this->day = day;

    

 	
 }

 bool Date::operator==(const Date &other) const
 {
     return year == other.year && month == other.month && day == other.day;
 }

 bool Date::operator!=(const Date& other) const
 {
     return !(*this == other);
 }

// // "2000-01-11" < "2018-03-05"
// // "2020-08-07" < "2021-08-07"
 bool Date::operator<(const Date &other) const
 {
     return year < other.year && month < other.month && day <other.day;
 }

 bool Date::operator<=(const Date &other) const
 {
     return *this == other || *this < other;
 }

 bool Date::operator>(const Date &other) const
 {
     return !(*this <= other);
 }

 bool Date::operator>=(const Date &other) const
 {
     return !(*this < other);
 }

std::istream& operator>>(std::istream& in, Date& other)
{
    return in >> other.year>>other. month>>other.day;
    
}


std::ostream& operator<<(std::ostream& out, const Date& other)
{
    return out<<other.intToString(other.reverse(other.year)) <<"-"<< other.intToString(other.reverse(other.month))<< "-" << other.intToString(other.reverse(other.day));
    
}
