#include "Row.h"

Row::Row()
{
    rowNumber = 0;
}

Row::Row(size_t rowNumber, size_t numberOfSeats)
{
    this->rowNumber = rowNumber;
    for (int i = 0; i < numberOfSeats; i++)
    {
        Seat seat(rowNumber, i);
        seats.pushBack(seat);
    }
}

size_t Row::getSize() const
{
    return seats.getSize();
}

Seat& Row::operator[](size_t index)
{
    return seats[index];
}

const Seat& Row::operator[](size_t index) const
{
    return seats[index];
}