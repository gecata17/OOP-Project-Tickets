#pragma once

#include <iostream>
#include "Vector.h"
#include "String.cpp"
#include "Date.h"
#include "Seat.h"
#include "Row.h"
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