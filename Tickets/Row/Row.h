#pragma once

#include<iostream>
#include "Vector.h"
#include "Seat.h"
class Row{
private:
  int rowNumber;
  Vector<Seat>seats;
public:
  Row();
  Row(int rowNumber,int numberOfSeats);
  int getSize() const;
  Seat& operator[] (int index);
  const Seat& operator[] (int index) const;

};