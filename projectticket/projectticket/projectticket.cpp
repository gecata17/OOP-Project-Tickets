#include <iostream>
#include "String.h"
#include "Vector.hpp"

int main()

{
    String test;
    test.pushBack('1');
    test.pushBack('6');
   

    String test2;
    test2.pushBack('|');

    Vector<char> tester;
    tester.pushBack('5');
    /*std::cout << tester[10];*/
    try {
        std::cout << tester[10]<<std::endl;

    }
    catch (const char* e) {
        std::cout << e;
    }
    std::cout<<"hello world"<<std::endl;
    

    return 0;
}
