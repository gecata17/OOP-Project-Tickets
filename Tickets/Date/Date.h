#pragma once
#include "String.cpp"
#include <iostream>
#include <fstream>
using std::to_string;
class Date
{
private:
  String date;   

  // YYYY-MM-DD

public:
  Date();
  Date(const String &);
  Date(int year, int month, int day);

  bool operator==(const Date &other) const;
  bool operator<(const Date &other) const;
  bool operator<=(const Date &other) const;
  bool operator>(const Date &other) const;
  bool operator>=(const Date &other) const;

  friend std::istream &operator>>(std::istream &in, Date &other);
  friend std::ostream &operator<<(std::ostream &out,const Date &other);
};

