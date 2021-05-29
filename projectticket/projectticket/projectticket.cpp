#include <iostream>
#include "String.h"
#include "Vector.hpp"
#include "Seat.h"
#include <cstring>
int main()

{
    
  //  Date date1(2014, 5, 17);
  //  Date date2(2014, 5, 17);
  //  Date date3(2024, 5, 17);
  //  std::cout << (date1 == date2) << std::endl;
  //  std::cout << (date1 != date3) << std::endl;


  //  Date date5(2014, 5, 17);
  //  Date date6(2015, 6, 18);
  //  Date date7(2016, 7, 19);
  //  std::cout << (date5 < date6) << std::endl;
  //  std::cout << (date7 >= date6) << std::endl;
  //  std::cout << (date5 <= date6) << std::endl;
  //  std::cout << (date7 > date6) << std::endl;
  //  std::cout << date5<<std::endl;
  //  
  //  std::cout << "///////" << std::endl;
  //  Vector<Seat> seats;
  //  seats.pushBack(Seat(4, 5));
  //  std::cout << seats[0].currentDate();
  ///* 
   /* String receipt ();
    receipt.append("s")*/


    char buffer[1024] = {'\0'};
    char command[128] = {'\0'};

    char buffer2[512] = {'\0'};

    std::cout << "> ";
    std::cin.getline(buffer,1024);

    for (size_t i = 0; i < 1024; i++)
    {
        if (buffer[i] == ' ') {
            for (size_t j = i+1; buffer[j]!='\0'; j++)
            {
                buffer2[j - i - 1] = buffer[j];
            }
            break;
        }
        
        command[i] = buffer[i];
        
    }
    if (strcmp(command,"open") == 0) {

        std::cout << "here";
        std::cout << buffer2<<std::endl;
    }
    else if (strcmp(command, "close") == 0) {
        std::cout << "here";
    }
    else if (strcmp(command, "save") == 0) {
        std::cout << "here";
    }
    else if (strcmp(command, "saveas") == 0) {
        std::cout << "now";
    }
    else if (strcmp(command, "help") == 0) {
        std::cout << "The following commands are supported : \n" <<
            "open <file> opens <file > \n " << 
            "close closes currently opened file \n " <<
            "save saves the currently open file \n " <<
           " saveas <file> saves the currently open file in <file> \n " <<
           " help prints this information \n " <<
            "exit exists the program \n ";

    }
    else if (strcmp(command, "exit") == 0) {
        
        std::cout << " \n Exiting the program... \n";
        return 0;
    }
    else {
        std::cout<<"Try again.There are no such available commands" << std::endl;
    }
    return 0;
}
