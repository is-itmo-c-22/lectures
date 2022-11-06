#include <iostream>
#include <assert.h>
#include <stack>

std::stack<int> a;
struct SomeStruct {
    int arr[10050];
};


void func(SomeStruct* s) {

}

void swap(int* a, int* b) {
   // assert(a != nullptr);
   // assert(b != nullptr);

    if(a == nullptr || b == nullptr) {
        std::cerr << "Error!";
        throw "Error";
    }

    int t = *a;
    *a = *b;
    *b = t;
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int YEAR = 2022;


void f(const SomeStruct& s) {

}
void f(SomeStruct& s) {

}

void f(SomeStruct* s) {

}


void f(int a) {

}

int& func(int& value) {
    value++;
    return value;
}





int test(int x = 0, int y = 0) {
    return 1;
}


int func();


int main() {

    int f();

    std::cout << f << std::endl;


    return  0;
    // int i = 1;
    // int& result = func(i);

    // std::cout << &i << " " << &result << std::endl;

    // int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    // std::cout << result << std::endl;

    // int i = 10;
    // int& j = i;
    // //sint& k; // error: ‘k’ declared as reference but not initialized
    // j = 20;
    // std::cout << i << std::endl;
    // std::cout << &i << "  " << &j << std::endl;

    // int a = 1;
    // int b = 2;
    // swap(a, b);

    // const int& r = i;
    // std::cout << &i << "  " << &j <<  " " << &r << std::endl;
    // // r = 21; // error assignment of read-only reference ‘r’
    return 0;
}



/// 2 полупоток


// void swap(int* a, int* b) {
//     if(a != nullptr && b != nullptr) {
//         int t = *a;
//         *a = *b;
//         *b = t;
//     } else {
//         throw "null ptr";
//     }
// }


// void swap(int& a, int& b) {
//     int t = a;
//     a = b;
//     b = t;
// }


// int YEAR = 2022;

// int& func(int& value) {
//     value++;
//     return value;
// }


// struct SomeStruct {
//     int arr[10050];
// };

// void f(int a) {
//      /// делаем что то с а
// }

// void func(const SomeStruct& s) {
// //void func(SomeStruct* s) {
//     // Делаем что то с s
// }


// struct Point
// {
//     int x = 0;
//     int y = 0;
// };

// int func();

// int main() {

//     int f();


//     std::cout << i  << std::endl;














//     //int& result = func(i);
//     //int arr[] = {1,2,3,4,5,6,7, 8, 9 ,10 ,11, 12, 13};

//     // std::cout << result << " " << i << std::endl;
//     // std::cout << &result << " " << &i << std::endl;


//     // int i = 1;
//     // int j = 2;


//     // std::cout << "i = " << i << " j = " << j << std::endl;
//     // swap(i,j);
//     // std::cout << "i = " << i << " j = " << j << std::endl;

//     // int i = 10;
//     // int h = 2;
//     // int& j = i;
//     // int& k = j;
//     // //int& k;   // error: ‘k’ declared as reference but not initialized


//     // j = 20;
//     // std::cout << i << std::endl;
//     // std::cout << &i << " " << &j << " " << &k << std::endl;
//     // const int& r = i;

//     // std::cout << &i << " " << &j << " " << &k  << " " << &r << std::endl;
//     // //r = 21; // error assignment of read-only reference ‘r’
//     return 0;
// }


// // int main(int, char**) {
// //     int i = 1;
// //     int j = 2;

// //     try {
// //         swap(nullptr,&j);
// //     }
// //     catch(...) {
// //         //.....
// //     }
// //     std::cout << "Hello, world!\n";
// // }
// /*