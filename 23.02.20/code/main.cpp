#include <iostream>
#include <vector>
// 1 полупоток
class Foo {

};

template<typename T>
const T& max(const  T& a, const T& b) {
    return a > b ? a : b;
}




template<typename T>
void printMe(const T& value) {
    std::cout << value;
}


template<typename T, size_t SIZE>
class CArray1 {
private:
    T arr_[SIZE];
};


template<typename T>
class CArray2 {
public:
    CArray2(size_t size)
        : arr_( new T[size])
    {}

    ~CArray2() {
        delete[] arr_;
    }
private:
    T* arr_;
};

int main(int, char**) {
    std::cout << max(10, 20) << std::endl;
    std::cout << max(10.1,20.2) << std::endl;

    std::cout << max<std::string>("zzzzz", "aaaaa") << std::endl;
    std::cout << max<std::string>("aaaaa","zzzzz") << std::endl;


    std::vector v = {"aaa", "bbb", "cccc"};

    // Foo a;
    // Foo b;
    // std::cout << max(a, b) << std::endl;
}


// 2й полупоток
// class Foo {

// };

// template<typename T>
// const T& max(const  T& a, const T& b) {
//     return a > b ? a : b;
// }


// template<typename T>
// void printMe(const T& value) {
//     std::cout << value;
// }


// template<typename T, size_t SIZE>
// class CArray1 {
// private:
//     T arr_[SIZE];
// };


// class CArray1_int_20 {
// private:
//     int arr_[20];
// };


// template<typename T>
// class CArray2 {
// public:
//     CArray2(size_t size)
//         : arr_( new T[size])
//     {}

//     ~CArray2() {
//         delete[] arr_;
//     }
// private:
//     T* arr_;
// };


// struct Boo {
//     int* p;
//     int  i;
// };


// int main(int, char**) {
//     CArray1<int, 20> arr1;

//     CArray2<int> arr2(20);

//     Boo b;

//     b.p = new int[100];

//     std::cout << max(10, 20) << std::endl;
//     std::cout << max(30, 10) << std::endl;
//     std::cout << max(10.1, 20.2) << std::endl;



//     std::cout << max<std::string>("zzzzz", "aaaaa") << std::endl;
//     std::cout << max<std::string>("aaaaa","zzzzz") << std::endl;

//     // Foo a;
//     // Foo b;
//     // std::cout << max(a, b) << std::endl;

//     std::vector<std::string> v = {"aaa", "bbb", "ccc"};
// }
