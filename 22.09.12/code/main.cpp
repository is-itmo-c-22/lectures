#include <iostream>
#include <cstdint>

enum Month {
    JAN = 100,
    FEB,
    MAR,
    SEP

};

int main(int argc, char** argv) {
    for(int i = 0; i < argc; ++i)
        std::cout << argv[i] << " ";

    int a = 5;
    int b = 2;
    std::cout << (float)a / b << std::endl;

    Month month = Month::FEB;

    // long unsigned int
    size_t s = sizeof(b);

    return 0;
}
