#include "Hall.h"

Hall::Hall()
{
    this->hallNumber = 0;
    this->numberRows = 0;
    this->numberSeatsPerRows = 0;
}

Hall::Hall(int numberRows, int numberSeatsPerRows)
{

    setNumberRows(numberRows);
    setNumberColumns(numberSeatsPerRows);
}
void Hall::setHallNumber(const size_t hallNumber)
{
    this->hallNumber = hallNumber;
}

void Hall::setNumberRows(const int numberRows)
{
    this->numberRows = numberRows;
}

void Hall::setNumberColumns(const int numberSeatsPerRows)
{
    this->numberSeatsPerRows = numberSeatsPerRows;
}

size_t Hall::getHallNumber() const
{
    return this->hallNumber;
}

int Hall::getNumberRows() const
{
    return this->numberRows;
}

int Hall::getNumberColumns() const
{
    return this->numberSeatsPerRows;
}

void Hall::book(const Date& date)
{
    bookedDates.pushBack(date);
}

//bool Hall::isFree(const Date& date) const
//{
//    for (size_t i = 0; i < bookedDates.getSize(); i++)
//    {
//        if (bookedDates[i] == date)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool Hall::isBooked(const Date& date) const
//{
//    return !isFree(date);
//}
