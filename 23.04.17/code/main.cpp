#include <iostream>
#include <vector>
#include <string>

#include <iomanip>

//
struct Foo {
    Foo(float f) {};
};

struct Boo {
    Boo(const std::string&) {}

    operator int() {
        return 2;
    }
};


struct Base {
    int i = 10;

    // void func() {
    //     std::cout << i << " Base\n";
    // }

    //virtual ~Base() = default;
};

struct Derrived : public Base {
    int j = 20;
    void func() {
        std::cout << j << " Derrived\n";
    }
};

int main(int, char**) {

    Base b;
    Derrived& d = dynamic_cast <Derrived&>(b);
    //std::cout << d << std:: endl;

    d.func();
    return 0;
    //Derrived d;
    //Base& b = d;
    // Base b;

    // b.func();
    // Derrived& d1 = static_cast<Derrived&>(b);
    // d1.func();


    // void* t = new Derrived();
    // static_cast<Derrived*>(t)->func();


    // Boo b("12345");
    // // int i = b;
    // // Foo f((float)i);

    // Foo f = static_cast<Foo>(b);


    // const int i = 0;
    // const int* cpi = &i;

    // int* pi = const_cast<int*>(cpi);
    // *pi = 100500;

    // std::cout << i << std::endl;


    // const char* str = "Hello world!";
    // char* s = const_cast<char*>(str);
    // s[0] = 'A'; // Undefined behaviour !!

    // Boo b;
    // Foo f;

    // std::cout << &b << " " << &f << std::endl;
    // func(&b);
    // func((Boo*)&f);


    //cout << *(double*)&i << std::endl;  // ~1.0 | 0.00000000001 | 1 | random

    // std::vector<bool> v(2147483655, 0);
    // size_t cnt = 0;


    // int i = 2147483647;
    // ++i;

    // std::cout << (i < v.size()) << std::endl;;
    // return 0;



    // for(size_t i = 0; i < v.size(); ++i) {
    //     if(v[i] == 0)
    //         ++cnt;
    //     if(cnt % 1000000000 == 0)
    //         std::cout << cnt << std::endl;
    // }

    //std::cout << cnt << std::endl;  // +-2 | 2147483647 | 0

    return 0;
    // double d = -12.3456789 ;
    // std::cout << std::setprecision(10) <<  d << std:: endl; // ~ -12.3456789
    // float f = d;
    // std::cout << f << std:: endl;  // ~ -12.3456789
    // int i = d;
    // std::cout << i << std:: endl; // -12
    // uint32_t ui = d;
    // std::cout << ui << std:: endl; // 2^32 - 12 - 1 |  213122313
    // char ch = d;
    // std::cout << ch << std:: endl; // -12 | ascii(-12) | 244 | ascii(244)
    return 0;
}


// 2й полупоток
// // struct Foo {
// //     int i = 64;
// //     int j = 20;
// // };

// // struct Boo {
// //     std::string str = "abc";
// // };

// // void func(Boo* b) {
// //     std::cout << b->str << std::endl;
// // }

// // class Foo {
// // public:
// //     int value() const {
// //         const_cast <Foo*>(this)->counter_++;
// //         return value_;
// //     }
// // private:
// //     int value_ = 0;
// //     int counter_ = 0;
// // };


// struct Foo {
//     Foo(float f) {};
// };

// struct Boo {
//     Boo(const std::string&) {}
//     operator int() {
//         return 2;
//     }
// };


// struct Base {
//     int i = 10;

//     // void func() {
//     //     std::cout <<  i <<  " Base\n";
//     // }

//     virtual ~Base() {};
// };

// struct Derrived : public Base {
//     int j = 20;
//     void func() {
//         std::cout << j << " Derrived\n";
//     }
// };

// int main(int, char**) {
//     Base b;
//     Derrived & d = dynamic_cast <Derrived &>(b);

//     d.func();


//     // //Derrived d;
//     // //Base& b = d;
//     // Base b;

//     // b.func();
//     // Derrived& d1 = static_cast<Derrived&>(b);
//     // d1.func();

//     //void* t = new Derrived();
//     //static_cast<Derrived*>(t)->func();


//     //Boo b("12345");
//     //int i = b;
//     //Foo f((float)i);

//     //Foo f = static_cast<Foo>(b);
//     return 0;
// }

// // int main () {

// //     Foo f;
// //     f.value();

// //     const int i = 0;
// //     const int* cpi = &i;

// //     int* pi = const_cast<int*>(cpi);
// //     *pi = 100500;

// //     std::cout << i << std::endl;



// //     // const char* str = "Hello world!";
// //     // char* s = const_cast<char*>(str);
// //     // // s[0] = 'A'; // Undefined behaviour !!
// // }

// // int main(int, char**) {
// //     Boo b;
// //     Foo f;

// //     //char ch = 64;
// //     //std::cout << sizeof(Boo) << std::endl;
// //     func(&b);
// //     func((Boo*)&f);

// //     // int i = 1;
// //     // // uint8_t* arr;
// //     // // arr = (uint8_t*)&i;
// //     // // for(int i = 0; i < 4; ++i) {
// //     // //     std::cout << (uint32_t)arr[i] << " ";
// //     // // }
// //     // std::cout << *((double*)&i) << std::endl;
// // }
