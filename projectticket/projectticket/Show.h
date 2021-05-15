
#pragma once

#include <iostream>
#include "Vector.hpp"
#include "String.h"
#include "Date.h"
#include "Seat.h"
#include "Row.h"
class Show {
private:
	String showName;
	Date date;
	Vector<Row> rows;

public:
	Show();
	Show(const String& showName, int numberRows, int numberColumns, const Date& date);

	

	String getShowName() const;
	int getNumberOfColumns() const;
	int getAllSeats() const;
	int getBookedSeats() const;
	int getFreeSeats() const;
	int getBookedSeatsWhichAreNotPurchased() const;
	//int getPurchasedSeatsInDateInterval(const Date& dateFrom, const Date& dateTo) const;
	//int getSeatNumber(int serialNumber);

	Date getDate() const;

	bool isValid(int rowNumber, int seatNumber) const;
	bool isBooked(int rowNumber, int seatNumber) const;
	bool isPurchased(int rowNumber, int seatNumber) const;
	void bookSeat(int rowNumber, int seatNumber, const String& receipt);
	void unbookSeat(int rowNumber, int seatNumber);
	void purchaseTicket(int rowNumber, int seatNumber);
};