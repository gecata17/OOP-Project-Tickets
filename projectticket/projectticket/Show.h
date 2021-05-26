
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
	size_t getNumberOfColumns() const;
	size_t getAllSeats() const;
	size_t getBookedSeats() const;
	size_t getFreeSeats() const;
	size_t getBookedSeatsWhichAreNotPurchased() const;
	size_t getPurchasedSeatsInDateInterval(const Date& dateFrom, const Date& dateTo) const;
	size_t getSeatNumber(size_t serialNumber) const;

	Date getDate() const;

	bool isValid(size_t rowNumber, size_t seatNumber) const;
	bool isBooked(size_t rowNumber, size_t seatNumber) const;
	bool isPurchased(size_t rowNumber, size_t seatNumber) const;
	void bookSeat(size_t rowNumber, size_t seatNumber, const String& receipt);
	void unbookSeat(size_t rowNumber, size_t seatNumber);
	void purchaseTicket(size_t rowNumber, size_t seatNumber);
};