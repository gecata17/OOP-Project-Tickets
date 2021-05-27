
#pragma once

#include <iostream>
#include "String.h"
#include "Date.h"
#include<ctime>
#include<cstdlib>

class Seat {

private:
	size_t rowNumber;
	size_t seatNumber;
	bool isBookedSeat;
	String receipt;
	size_t ticketSerialNumber;
	Date dateOfPurchase;

	int randomNumber();



public:
	Seat();
	Seat(size_t rowNumber, size_t seatNumber);
	bool isBooked() const;
	void book();
	void unbook();
	Date currentDate();

	void setReceipt(const String& receipt);

	String getReceipt() const;
	bool isPurchased() const;
	Date getDateOfPurchase() const;
	bool isPurchasedInDateInterval(const Date& dateFrom, const Date& dateTo) const;
	void purchase();

	size_t getTicketSerialNumber() const;

};