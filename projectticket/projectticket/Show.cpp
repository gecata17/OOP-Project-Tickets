#include "Show.h"

Show::Show()
{
    this->showName = nullptr;
}

Show::Show(const String& showName, size_t numberRows, size_t numberColumns, const Date& date)
{
    this->showName = showName;
    this->date = date;

    for (size_t i = 0; i < numberRows; i++)
    {
        Row newRow(i, numberColumns);
        rows.pushBack(newRow);
    }
}

String Show::getShowName() const
{
    return this->showName;
}

size_t Show::getNumberOfColumns() const
{
    if (rows.empty())
    {
        return 0;
    }
    else
    {
        return rows[0].getSize();
    }
}

size_t Show::getAllSeats() const
{
    if (rows.empty())
    {
        return 0;
    }
    else
    {
        return rows.getSize() * getNumberOfColumns();
    }
}

size_t Show::getBookedSeats() const
{
    int counter = 0;
    for (size_t i = 0; i < rows.getSize(); i++)
    {
        for (size_t j = 0; j < rows[i].getSize(); j++)
        {
            if (rows[i][j].isBooked())
            {
                counter++;
            }
        }
    }

    return counter;
}

size_t Show::getFreeSeats() const
{
    return getAllSeats() - getBookedSeats();
}

size_t Show::getBookedSeatsWhichAreNotPurchased() const
{
    int counter = 0;
    for (size_t i = 0; i < rows.getSize(); i++)
    {
        for (size_t j = 0; j < rows[i].getSize(); j++)
        {
            if (rows[i][j].isBooked() && !rows[i][j].isPurchased())
            {
                counter++;
            }
        }
    }
    return counter;
}

size_t Show::getPurchasedSeatsInDateInterval(const Date& dateFrom, const Date& dateTo) const
{
    int counter = 0;
    for (size_t i = 0; i < rows.getSize(); i++)
    {
        for (size_t j = 0; j < rows[i].getSize(); j++)
        {
            if (rows[i][j].isPurchasedInDateInterval(dateFrom, dateTo))
            { 
                counter++;
            }
        }
    }
    return counter;
}

size_t Show::getSeatNumber(size_t serialNumber) const
{
    for (size_t i = 0; i < rows.getSize(); i++)
    {
        for (size_t j = 0; j < rows[i].getSize(); j++)
        {
            if (rows[i][j].getTicketSerialNumber() == serialNumber)
            {
                return j;
            }
        }
    }

    throw "Invalid serial number";
}

Date Show::getDate() const
{
    return this->date;
}

bool Show::isValid(size_t rowNumber, size_t seatNumber) const
{
    return 0 <= rowNumber && rowNumber < rows.getSize() && 0 <= seatNumber && seatNumber < getNumberOfColumns();
}

bool Show::isBooked(size_t rowNumber, size_t seatNumber) const
{
    return rows[rowNumber][seatNumber].isBooked();
}

bool Show::isPurchased(size_t rowNumber, size_t seatNumber) const
{
    return rows[rowNumber][seatNumber].isPurchased();
}

void Show::bookSeat(size_t rowNumber, size_t seatNumber, const String& receipt)
{
    if (!isBooked(rowNumber, seatNumber))
    {
        rows[rowNumber][seatNumber].book();
        rows[rowNumber][seatNumber].setReceipt(receipt);
    }
}

void Show::unbookSeat(size_t rowNumber, size_t seatNumber)
{
    if (isBooked(rowNumber, seatNumber))
    {
        rows[rowNumber][seatNumber].unbook();
        rows[rowNumber][seatNumber].setReceipt("");
    }
}

void Show::purchaseTicket(size_t rowNumber, size_t seatNumber)
{
    if (!isPurchased(rowNumber, seatNumber))
    {
        rows[rowNumber][seatNumber].purchase();
        std::cout << "The ticket is succesfully purchased" << std::endl;
    }

}