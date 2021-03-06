#include "Seat.h"

// Credits: https://en.cppreference.com/w/cpp/numeric/random/srand
int Seat::randomNumber()
{
    srand(time(nullptr)); // srand makes rand really generate random number
                          // time(nullptr) is the number of seconds since 1970
    return rand() % 10000;
}

// Credits: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
Date Seat::currentDate()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    int year = 1900 + newtime.tm_year;
    int month = 1 + newtime.tm_mon;
    int day = newtime.tm_mday;
    Date date(year, month, day);

    return date;
}

Seat::Seat()
{
    this->rowNumber = 0;
    isBookedSeat = false;
    this->seatNumber = 0;
    this->receipt = "";
    this->ticketSerialNumber = 0;
}
Seat::Seat(size_t rowNumber, size_t seatNumber)
{
    this->rowNumber = rowNumber;
    this->seatNumber = seatNumber;
    isBookedSeat = false;
    this->receipt = "";
    this->ticketSerialNumber = 0;
}

bool Seat::isBooked() const
{
    return isBookedSeat;
}

void Seat::book()
{
    isBookedSeat = true;
}

void Seat::unbook()
{
    isBookedSeat = false;
}

void Seat::setReceipt(const String& receipt)
{
    this->receipt = receipt;
}

String Seat::getReceipt() const
{
    return this->receipt;
}

bool Seat::isPurchased() const
{
    return ticketSerialNumber != 0;
}

Date Seat::getDateOfPurchase() const
{
    return this->dateOfPurchase;
}

bool Seat::isPurchasedInDateInterval(const Date& dateFrom, const Date& dateTo) const
{
    return dateOfPurchase >= dateFrom && dateOfPurchase <= dateTo;
}

void Seat::purchase()
{
    if (!isPurchased())
    {
        book();
        ticketSerialNumber = (rowNumber * 100 + seatNumber) * 10000 + randomNumber();
        dateOfPurchase = currentDate();
    }
    if (isPurchased()) {
        std::cout << "This seat has already been purchased" << std::endl;
    }
}

size_t Seat::getTicketSerialNumber() const
{
    return ticketSerialNumber;
}

