#pragma once


#include "Show.h"
#include "Date.h"
#include "Vector.hpp"
class Hall {
private:

    size_t hallNumber;
    int numberRows;
    int numberSeatsPerRows;
    Vector<Date> bookedDates;
public:
    Hall();
    Hall(int numberRows, int numberSeatsPerRows);

    void setHallNumber(const size_t hallNumber);
    void setNumberRows(const int numberRows);
    void setNumberColumns(const int numberSeatsPerRows);

    size_t getHallNumber() const;
    int getNumberRows() const;
    int getNumberColumns() const;

    void book(const Date& date);
    bool isFree(const Date& date) const;
    bool isBooked(const Date& date) const;


};