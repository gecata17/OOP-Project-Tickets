#pragma once

#include <iostream>
#include "Vector.cpp"
#include "String.cpp"
#include "Date.cpp"
#include "Seat.cpp"
#include "Row.cpp"
class Show{
private:
   String showName;
   Date date;
   Vector<Row> rows;
   int hallIndex;
public:
  Show();
  ~Show();
  
  void setName(const char* name);

  char* getName() const;
};