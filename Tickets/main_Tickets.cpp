#include <iostream>
#include "String.h"

String intToString(int n )
{
  String result;
  while(n>10){
      result.pushBack(n%10 +'0');
      n/=10;
  }
  result.pushBack(n + '0');
  
  return result;
}

int main()


{
    // TicketsApp ticketsTest;
    // ticketsTest.run();

    int n = 16;
    std::cout<<intToString(n);
    return 0;
}