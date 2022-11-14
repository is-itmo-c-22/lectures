#include "math.h"
#include <iostream>

int add(int x, int y) {
    return x + y;
}


int increment(int x) {
    return x + 1;
}



void PrintInfo() {

    Exp2 = 2;
    //std::cout << PI << " Address of PI:" << &PI << std::endl;
    //std::cout << Exp << " Address of Exp:" << &Exp << std::endl;
    // std::cout << SomeValue << " Address of Exp:" << &SomeValue << std::endl;
    //std::cout << PI2 << " Address of PI:" << &PI2 << std::endl;
    std::cout << Exp2 << " Address of Exp:" << &Exp2 << std::endl;
}