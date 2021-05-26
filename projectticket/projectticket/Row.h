#pragma once
#include "String.h"
#include "Vector.hpp"
#include "Seat.h"
class Row {
private:
	size_t rowNumber;
	Vector<Seat>seats;
public:
	Row();
	Row(size_t rowNumber, size_t numberOfSeats);
	size_t getSize() const;
	Seat& operator[] (size_t index);
	const Seat& operator[] (size_t index) const;

};