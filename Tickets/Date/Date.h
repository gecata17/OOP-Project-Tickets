#pragma once
#include "String.cpp"
#include <iostream>
#include <fstream>
using std::to_string;
class Date
{
private:
  String date;

public:
  Date();
  Date(const String &);
  Date(int year, int month, int day);

  bool operator==(const Date &other) const;
  bool operator<(const Date &other) const;
  bool operator<=(const Date &other) const;
  bool operator>(const Date &other) const;
  bool operator>=(const Date &other) const;

  friend std::istream &operator>>(std::istream &in, Date &input);
  friend std::ostream &operator<<(std::ostream &out, Date &output);
};
std::istream &operator>>(std::istream &in, Date &input)
{
  in >> input.date;
  return in;
}

std::ostream &operator<<(std::ostream &out, const Date &output)
{
  out << output.date;
  return out;
}
