#pragma once
#include <iostream>
#include "String.h"
#include "Vector.hpp"
#include "Hall.h"
#include "Show.h"
#include "Date.h"

class Tickets {
private:
	Vector<Hall> halls;
	Vector<Show> shows;
public:
	Show* findShow(const String& showName, const Date& date);

    void addEvent();
    void freeSeats();
	void book();
    void unbook();
    void buy();
    void bookings();
    void check();
    //void report();

    void run();
	
};