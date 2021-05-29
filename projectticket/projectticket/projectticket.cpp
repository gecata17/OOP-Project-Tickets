#include <iostream>
#include "String.h"
#include "Vector.hpp"
#include "Seat.h"
int main()

{
    
    Date date1(2014, 5, 17);
    Date date2(2014, 5, 17);
    Date date3(2024, 5, 17);
    std::cout << (date1 == date2) << std::endl;
    std::cout << (date1 != date3) << std::endl;


    Date date5(2014, 5, 17);
    Date date6(2015, 6, 18);
    Date date7(2016, 7, 19);
    std::cout << (date5 < date6) << std::endl;
    std::cout << (date7 >= date6) << std::endl;
    std::cout << (date5 <= date6) << std::endl;
    std::cout << (date7 > date6) << std::endl;
    std::cout << date5<<std::endl;
    
    std::cout << "///////" << std::endl;
    Vector<Seat> seats;
    seats.pushBack(Seat(4, 5));
    std::cout << seats[0].currentDate();
  /* 
    String receipt ();
    receipt.append("s")*/
    return 0;
}
