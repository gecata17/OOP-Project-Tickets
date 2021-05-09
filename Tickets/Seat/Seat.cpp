#include "Seat.h"

// Credits: https://en.cppreference.com/w/cpp/numeric/random/srand
int Seat::randomNumber()
{
    srand(time(nullptr));  // srand makes rand really generate random number
                           // time(nullptr) is the number of seconds since 1970
    return rand() % 10000; // + 1 so that it's not 0
}

// Credits: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
Date Seat::currentDate()
{
    time_t now = time(0);
    tm *local_time = localtime(&now);
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    int day = local_time->tm_mday;
    Date date(year, month, day);
}

Seat::Seat()
{
    this->rowNumber = 0;
    this->receipt = 0;
    isBookedSeat = false;
    this->seatNumber = 0;
    this->receipt = "";
    this->ticketSerialNumber = 0;
}
Seat::Seat(int rowNumber, int seatNumber)
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

void Seat::setReceipt(const String& receipt){
    this->receipt=receipt;
}

String Seat:: getReceipt() const{
    return this->receipt;
}

bool Seat::isPurchased() const{
    return ticketSerialNumber != 0 ;
}

void Seat:: purchase() {
    if(!isPurchased()){
        book();
        ticketSerialNumber = (rowNumber* 100 + seatNumber) * 10000 + randomNumber();
        dateOfPurchase = currentDate(); 
    }
}