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
   
public:
  Show();
  Show(const String& showName,int numberRows,int numberColumns, const Date& date);
  
  void setName(const char* showName);

  String getName() const;
};