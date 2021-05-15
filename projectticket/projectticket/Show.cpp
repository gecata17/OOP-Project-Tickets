#include "Show.h"

Show::Show()
{
    this->showName = nullptr;
}

Show::Show(const String& showName, int numberRows, int numberColumns, const Date& date)
{
    this->showName = showName;
    this->date = date;

    for (int i = 0; i < numberRows; i++)
    {
        Row newRow(i, numberColumns);
        rows.pushBack(newRow);
    }
}

String Show::getShowName() const
{
    return this->showName;
}

int Show::getNumberOfColumns() const
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

int Show::getAllSeats() const
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

int Show::getBookedSeats() const
{
    int counter = 0;
    for (int i = 0; i < rows.getSize(); i++)
    {
        for (int j = 0; j < rows[i].getSize(); j++)
        {
            if (rows[i][j].isBooked())
            {
                counter++;
            }
        }
    }

    return counter;
}

int Show::getFreeSeats() const
{
    return getAllSeats() - getBookedSeats();
}

int Show::getBookedSeatsWhichAreNotPurchased() const
{
    int counter = 0;
    for (int i = 0; i < rows.getSize(); i++)
    {
        for (int j = 0; j < rows[i].getSize(); j++)
        {
            if (rows[i][j].isBooked() && !rows[i][j].isPurchased())
            {
                counter++;
            }
        }
    }
    return counter;
}

//int Show::getPurchasedSeatsInDateInterval(const Date& dateFrom, const Date& dateTo) const
//{
//    int counter = 0;
//    for (int i = 0; i < rows.getSize(); i++)
//    {
//        for (int j = 0; j < rows[i].getSize(); j++)
//        {
//            if (rows[i][j].isPurchasedInDateInterval(dateFrom, dateTo))
//            {
//                counter++;
//            }
//        }
//    }
//    return counter;
//}

//int Show::getSeatNumber(int serialNumber)
//{
//    for (int i = 0; i < rows.getSize(); i++)
//    {
//        for (int j = 0; j < rows[i].getSize(); j++)
//        {
//            if (rows[i][j].getTicketSerialNumber() == serialNumber)
//            {
//                return j;
//            }
//        }
//    }
//
//    return -1;
//}

Date Show::getDate() const
{
    return this->date;
}

bool Show::isValid(int rowNumber, int seatNumber) const
{
    return 0 <= rowNumber && rowNumber < rows.getSize() && 0 <= seatNumber && seatNumber < getNumberOfColumns();
}

bool Show::isBooked(int rowNumber, int seatNumber) const
{
    return rows[rowNumber][seatNumber].isBooked();
}

bool Show::isPurchased(int rowNumber, int seatNumber) const
{
    return rows[rowNumber][seatNumber].isPurchased();
}

void Show::bookSeat(int rowNumber, int seatNumber, const String& receipt)
{
    if (!isBooked(rowNumber, seatNumber))
    {
        rows[rowNumber][seatNumber].book();
        rows[rowNumber][seatNumber].setReceipt(receipt);
    }
}

void Show::unbookSeat(int rowNumber, int seatNumber)
{
    if (isBooked(rowNumber, seatNumber))
    {
        rows[rowNumber][seatNumber].unbook();
        rows[rowNumber][seatNumber].setReceipt("");
    }
}

void Show::purchaseTicket(int rowNumber, int seatNumber)
{
    if (!isPurchased(rowNumber, seatNumber))
    {
        rows[rowNumber][seatNumber].purchase();
        std::cout << "The ticket is succesfully purchased" << std::endl;
    }

}