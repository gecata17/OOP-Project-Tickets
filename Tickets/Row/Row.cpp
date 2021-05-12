#include "Row.h"

Row::Row()
{
    rowNumber = 0;
}

Row::Row(int rowNumber, int numberOfSeats)
{
    this->rowNumber = rowNumber;
    for (size_t i = 0; i < numberOfSeats; i++)
    {
        Seat seat(rowNumber, i);
        seats.pushBack(seat);
    }
}

int Row::getSize() const
{
    return seats.getSize();
}

Seat &Row::operator[](int index)
{
    return seats[index];
}

const Seat &Row::operator[](int index) const
{
    return seats[index];
}