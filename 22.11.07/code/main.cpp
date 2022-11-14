#include "math.h"
#include "math.h"
#include "math.h"
#include "math.h"
#include "math.h"
#include "math.h"

#include <iostream>



// #define MAX(x, y) (x > y ? x : y)

// int func(int x) {
//     return x + 1;
// }

// #ifdef __DEBUG__
// #define error_log(format, ...) printf("[ERROR] (%s:%d) " format "\n", __FILE__,
// __LINE__, ##__VA_ARGS__)
// #else
// #define error_log(format, ...)
// #endif

// #define __DEBUG__

// #ifdef __DEBUG__
//     #define ERROR_LOG(formattt, ...) printf("[ERROR] (%s:%d)" formattt "\n",__FILE__, __LINE__, ##__VA_ARGS__)
// #else
//     #define ERROR_LOG(text, ...)
// #endif

#pragma pack (1)
struct SomeStruct {
    char ch;
    int i;
    char ch2;
};

#pragma pop()

const float Exp = 2.72f;
float Exp2 = 2.72f;

void func() {
    static int count =  0;
    //int count =  0;
    ++count;
    std::cout << &count << std::endl;
}

int main() {
    //ERROR_LOG("Smth going wrong code %d", 239);


    int x = 1;
    int y = 2;
    int z = add(x, y);
    increment(z);


    //std::cout << sizeof(SomeStruct) << std::endl;



    // PI2 = 3;



    // //std::cout << PI << " Address of PI:" << &PI << std::endl;
    // //std::cout << Exp << " Address of Exp:" << &Exp << std::endl;
    // //std::cout << SomeValue << " Address of Exp:" << &SomeValue << std::endl;
    // //std::cout << PI2 << " Address of PI:" << &PI2 << std::endl;
    // std::cout << Exp2 << " Address of Exp:" << &Exp2 << std::endl;
    // std::cout << "----Math-----\n" ;


    // PrintInfo();
    // std::cout << "----Main-----\n" ;
    // std::cout << Exp2 << " Address of Exp:" << &Exp2 << std::endl;

    func();
    func();

    return 0;
}
