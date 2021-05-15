#pragma once

#include <iostream>
#include "String.cpp"
#include "Date.h"
#include<ctime>
#include<cstdlib>

class Seat{

private:
   int rowNumber;
   int seatNumber;
   bool isBookedSeat;
   String receipt;
   int ticketSerialNumber;
   Date dateOfPurchase;

   int randomNumber();
   
   Date currentDate(); 

public:
   Seat();
   Seat(int rowNumber,int seatNumber);
   bool isBooked() const;
   void book() ; 
   void unbook();

   void setReceipt(const String & receipt);

   String getReceipt() const;
   bool isPurchased() const;
   bool isPurchasedInDateInterval(const Date& dateFrom, const Date& dateTo);
   void purchase();
   
   int getTicketSerialNumber() const;

};