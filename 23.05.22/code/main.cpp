#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <variant>
#include <memory>

// 1й полупоток

template<typename T>
std::string to_string( const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template<typename... TArgs>
std::vector<std::string> to_strings(const TArgs&... args);


std::vector<std::string> to_strings() {
    return {} ;
}

template<typename T, typename... TArgs>
std::vector<std::string> to_strings(const T& value, const TArgs&... args) {
    std::vector<std::string> result;
    result.push_back(to_string(value));

    std::vector<std::string> other = to_strings(args...);
    result.insert(result.end(), other.begin(), other.end());
    return result;
}


/*
  сделать буффер через RAII, размер в конструктор, элементы через оператор []

*/

class Buffer {
public:
    Buffer(size_t size)
        : size_(size)
        , data_(new uint8_t[size])
    {}

    ~Buffer() {
        delete[] data_;
    }

    Buffer(const Buffer& other)
        : size_(other.size_)
        ,data_(new uint8_t[other.size_])
    {
        std::copy(other.data_, other.data_ + other.size_, data_);

        //std::memcpy(data_, other.data_, other.size_ * sizeof(uint8_t));
    }

    Buffer& operator=(const Buffer& other) {

        if(this == &other) {
            return *this;
        }

        // copy and swap idiom
        Buffer tmp{other};

        std::swap(tmp.data_, data_);
        std::swap(tmp.size_, size_);

        return *this;
    }

    uint8_t& operator[](size_t idx) {
        return data_[idx];
    }

private:
    uint8_t* data_;
    size_t size_;
};




void func(int value) {
   throw std::runtime_error("some error");
   //throw 10;
}

template<typename TFunc, typename T>
void safety_caller(TFunc func, const T& value) {
    try {
        func(value);
    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    } catch(...) {
        std::cerr << "Unknown error\n";
    }
}


template<typename ...TArgs>
auto divide(TArgs... args) {
    return (args / ... );
}

template<typename ...TArgs>
auto divide2(TArgs... args) {
    return ( ... / args );
}


/*
Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
Unary left fold (... op E) becomes (((E1 op E2) op ...) op EN)
*/


template<typename T>
void print_me(const T& value) {
    std::cout << value << std::endl;
}

#include <array>



struct Less5 {
    bool operator()(int i) {
        return i < 5;
    }
};

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }

    ~Foo() {
        std::cout << "~Foo()\n";
    }
    Foo(const Foo&) {
        std::cout << "Foo(const Foo&)\n";
    }
    Foo& operator=(const Foo&) {
        std::cout << "operator=\n" ; return *this;
    }
};


Foo foo1() {
    return Foo();
}

Foo foo2() {
    Foo result;
    return result;
}

Foo foo3(int i) {
    Foo odd;
    Foo even;
    return i % 2 == 0 ? odd : even;
}


int main() {
    Foo f = foo1();

    // std::vector v = {1,2,3,4,5,6,7};
    // std::cout << std::count_if(v.begin(), v.end(),Less5{}) << std::endl;
    // std::cout << std::count_if(v.begin(), v.end(), [](int i){ return i < 5;}) << std::endl;

//    int i = 10;



    return 0;

    print_me(10);

    std::array<int, 5> arr = {1,2,3,4,5};
    std::vector v{arr.begin(), arr.end()};


    return 0;
    std::cout << divide(10) << std::endl; // (E1 op (... op (EN-1 op EN))) -> 10 / (5.0/ 2.0)
    std::cout << divide2(10) << std::endl; // (((E1 op E2) op ...) op EN)  -> (10/5.0)/2.0


    return 0;
    safety_caller(func, 10);


    return 0;
    Buffer b1{10};
    Buffer b2{4};
    b2 = b1;


    // for(const auto& v : to_strings(true, 122, 2.234)) {
    //     std::cout << v << std::endl;
    // }

}


// 2й полупоток

// template<typename T>
// std::string to_string( const T& value) {
//     std::stringstream ss;
//     ss << value;
//     return ss.str();
// }

// template<typename... TArgs>
// std::vector<std::string> to_strings(const TArgs&... args);


// std::vector<std::string> to_strings() {
//     return {} ;
// }

// template<typename T, typename... TArgs>
// std::vector<std::string> to_strings(const T& value, const TArgs&... args) {
//     std::vector<std::string> result;
//     result.push_back(to_string(value));

//     std::vector<std::string> other = to_strings(args...);
//     result.insert(result.end(), other.begin(), other.end());
//     return result;
// }


// class CBuffer {
// public:
//     CBuffer(size_t size)
//         : size_(size)
//         , data_(new uint8_t[size])

//     {}

//     ~CBuffer() {
//         if(data_) {
//             delete[] data_;
//         }
//     }

//     CBuffer(const CBuffer& other)
//         : size_(other.size_)
//         , data_(new uint8_t[other.size_])
//     {
//         //data_ = new uint8_t[size_];
//         std::copy(other.data_, other.data_ + size_, data_);
//     }

//     CBuffer& operator=(const CBuffer& other) {
//         if(this == &other) {
//             return *this;
//         }
//         // copy and swap idiom
//         CBuffer tmp{other};

//         std::swap(tmp.data_, data_);
//         std::swap(tmp.size_, size_);

//         return *this;
//     }

//     uint8_t& operator[](size_t idx) {
//         return data_[idx];
//     }

// private:
//     uint8_t* data_;
//     size_t size_;
// };


// #include <algorithm>

// template<typename T, typename TFunc>
// void safety_caller(TFunc fun, const T& value) {
//     try {
//         fun(value);
//     } catch(const std::exception& ex) {
//         std::cerr << ex.what() << std::endl;
//     } catch(...) {
//         std::cerr << "Unknown exception\n";
//     }
// }

// void func(int value) {
//     throw std::runtime_error("some error");
// }

// template<typename ...TArgs>
// auto divide(const TArgs&... args) {
//     return (args / ... );
// }

// template<typename ...TArgs>
// auto divide2(const TArgs&... args) {
//     return ( ... / args );
// }

// /*
// Unary right fold (E op ...) becomes (E1 op (... op (EN-1 op EN)))
// Unary left fold (... op E) becomes (((E1 op E2) op ...) op EN)
// */



// template<typename T>
// void print_me(const T& value) {
//     std::cout << value << std::endl;
// }


// struct Less5 {
//     bool operator()(int i) {
//         return i < 5;
//     }
// };



// #include <array>
// int main(int, char**) {

//     std::vector v = {1,2,3,4,5,6,7};

//     std::cout << std::count_if(v.begin(), v.end(), Less5{}) << std::endl;
//     std::cout << std::count_if(v.begin(), v.end(), [](int i){ return i < 5;}) << std::endl;

//     int max_value = 4;
//     std::cout << std::count_if(v.begin(), v.end(), [max_value](int i){ return i < max_value;}) << std::endl;
//     return 0;



//     //print_me(10);

//     //std::vector v = {1,2,3,4, 5};

//     // std::array<int, 5> arr = { 1,2,3,4,5};
//     // std::vector v(arr.begin(), arr.end());

//     // std::sort(v.begin(), v.end(),


//     return 0;
//     //safety_caller(func, 10);

//     std::cout << divide(10, 5.0, 2.0) << std::endl; // (E1 op (... op (EN-1 op EN))) 10 / (5.0/2.0)
//     std::cout << divide2(10, 5.0, 2.0) << std::endl; //   (((E1 op E2) op ...) op EN) (10/5)/2

//     return 0;
//     CBuffer b1{10};
//     CBuffer b2{4};

//     b2 = b1;

//     // for(const auto& v: to_strings(1, true, 12.3)) {
//     //     std::cout << v << std::endl;
//     // }


//     return 0;
// }
