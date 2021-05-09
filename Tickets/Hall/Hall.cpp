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
    setNumberSeats(numberSeatsPerRows);
}
void Hall::setHallNumber(const size_t hallNumber)
{
    this->hallNumber = hallNumber;
}

void Hall::setNumberRows(const int numberRows)
{
    this->numberRows = numberRows;
}

void Hall::setNumberSeats(const int numberSeatsPerRows){
    this->numberSeatsPerRows = numberSeatsPerRows}

size_t Hall::getHallNumber() const
{
    return this->hallNumber;
}

int Hall::getNumberRows() const
{
    return this->numberRows;
}

int Hall::getNumberSeats() const
{
    return this->numberSeatsPerRows;
}