#pragma once
#include "String.h"
#include "Vector.hpp"
#include "Seat.h"
class Row {
private:
	int rowNumber;
	Vector<Seat>seats;
public:
	Row();
	Row(int rowNumber, int numberOfSeats);
	int getSize() const;
	Seat& operator[] (size_t index);
	const Seat& operator[] (size_t index) const;

};