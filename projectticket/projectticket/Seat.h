
#pragma once

#include <iostream>
#include "String.h"
#include "Date.h"
#include<ctime>
#include<cstdlib>

class Seat {

private:
	int rowNumber;
	int seatNumber;
	bool isBookedSeat;
	String receipt;
	int ticketSerialNumber;
	Date dateOfPurchase;

	int randomNumber();



public:
	Seat();
	Seat(int rowNumber, int seatNumber);
	bool isBooked() const;
	void book();
	void unbook();
	Date currentDate();

	void setReceipt(const String& receipt);

	String getReceipt() const;
	bool isPurchased() const;
	Date getDateOfPurchase() const;
	//bool isPurchasedInDateInterval(const Date& dateFrom, const Date& dateTo);
	void purchase();

	//int getTicketSerialNumber() const;

};