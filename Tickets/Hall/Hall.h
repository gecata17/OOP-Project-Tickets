#pragma once
#include <iostream>
#include "Show.h"
class Hall{
private:
   char * hallName;
   Show * showNames;
   size_t hallNumber;
   Rows numberRows;
   Seats numberSeats;
public:
    Hall();
    Hall(const Hall &other);
    Hall& operator=(const Hall& other);
    ~Hall();
    
    void setHallName(const char *hallName);
    void setShowNames(const Show * showNames);
    void setHallNumber(const size_t hallNumber);
    void setNumberRows(const Rows numberRows);
    void setNumberSeats(const Seats numberSeats );

    char * getHallName() const;
    Show * getShowNames() const;
    size_t getHallNumber() const;
    Rows getNumberRows() const const;
    Seats getNumberSeats( ) const;
};