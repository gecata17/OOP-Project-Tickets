#pragma once
#include <iostream>
#include "Show.cpp"
class Hall{
private:
   
   size_t hallNumber;
   int numberRows;
   int numberSeatsPerRows;
public:
    Hall();
    Hall(int numberRows,int numberSeatsPErRows);
    
    void setHallNumber(const size_t hallNumber);
    void setNumberRows(const int numberRows);
    void setNumberSeats(const int numberSeatsPerRows );

    size_t getHallNumber() const;
    int getNumberRows() const const;
    int getNumberSeats( ) const;
};