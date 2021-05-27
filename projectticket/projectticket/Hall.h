#pragma once


#include "Show.h"
#include "Date.h"
#include "Vector.hpp"
class Hall {
private:

    size_t hallNumber;
    size_t numberRows;
    size_t numberSeatsPerRows;
    Vector<Date> bookedDates;
public:
    Hall();
    Hall(size_t numberRows, size_t numberSeatsPerRows);

    void setHallNumber(const size_t hallNumber);
    void setNumberRows(const size_t numberRows);
    void setNumberColumns(const size_t numberSeatsPerRows);

    size_t getHallNumber() const;
    size_t getNumberRows() const;
    size_t getNumberColumns() const;

    void book(const Date& date);
    bool isFree(const Date& date) const;
    bool isBooked(const Date& date) const;


};