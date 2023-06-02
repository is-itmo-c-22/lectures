#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <variant>
#include <memory>

// 1й полупоток

struct A;

struct B {
    B() { std::cout << "B\n";}
    ~B() { std::cout << "~B\n";}
    std::shared_ptr<A> ptr;
};

struct A {
    A() { std::cout << "A\n";}
    ~A() { std::cout << "~A\n";}
    std::weak_ptr<B> ptr;
};

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


template<typename T>
struct Counter {
    static size_t count;

    Counter() {
        ++count;
    }

    Counter(const Counter& cnt) {
        //++count;
    }

    ~Counter() {
        --count;
    }
};

template<typename T>
size_t Counter<T>::count = 0;

struct Boo : public Counter<Boo> {
    // Boo(const Boo&) {

    // }
    //Boo() = default;
};



int main() {

    Boo b;
    std::cout << b.count << std::endl;

    {
        Boo b1 = b;

        std::cout << b.count << std::endl;
    }
    std::cout << b.count << std::endl;


    // for(const auto& v : to_strings(true, 122, 2.234)) {
    //     std::cout << v << std::endl;
    // }

    // std::shared_ptr<A> a1 {new A{}};
    // std::shared_ptr<A> a4 {new A{}};

    // std::cout << a1.use_count() << std::endl; // 1
    // std::cout << a4.use_count() << std::endl; // 1

    // std::shared_ptr<A> a2 = a1;

    // std::cout << a1.use_count() << std::endl; //2

    // {
    //     std::shared_ptr<A> a3 = a1;
    //     std::cout << a3.use_count() << std::endl; //3

    // }

    // a4 = a1;
    // std::cout << a4.use_count() << std::endl; // 3
    // std::cout << a1.use_count() << std::endl; // 3



    // std::shared_ptr<A> a {new A()};
    // std::shared_ptr<B> b {new B()};

    // std::cout << a.use_count() << "    " << b.use_count() << std::endl; // 1 1

    // a->ptr = b;
    // std::cout << a.use_count() << "    " << b.use_count() << std::endl; // 1 2

    // b->ptr = a;

    // std::shared_ptr<B> temp = a->ptr.lock();


    // std::cout << a.use_count() << "    " << b.use_count() << std::endl; // 2 2
}


// 2й полупоток
// struct A;

// struct B {
//     B() { std::cout << "B\n";}
//     ~B() { std::cout << "~B\n";}
//     std::shared_ptr<A> ptr;
// };

// struct A {
//     A() { std::cout << "A\n";}
//     ~A() { std::cout << "~A\n";}
//     std::shared_ptr<B> ptr;
// };

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

// int main(int, char**) {
//     for(const auto& v: to_strings(1, true, 12.3)) {
//         std::cout << v << std::endl;
//     }


//     // std::shared_ptr<A> a {new A{}};
//     // std::shared_ptr<A> a4 {new A{}};

//     // std::cout << a.use_count()  << std::endl;

//     // std::shared_ptr<A> a2 = a;
//     // std::cout << a.use_count() << std::endl;

//     // {
//     //     std::shared_ptr<A> a3 = a;
//     //     std::cout << a.use_count() << std::endl;
//     // }

//     // std::cout << a4.use_count()  << std::endl;
//     // a4 = a;
//     // std::cout << a.use_count() << std::endl;


//     // std::shared_ptr<A> a {new A()};
//     // std::shared_ptr<B> b {new B()};

//     // std::cout << a.use_count() << "    " << b.use_count() << std::endl;  // 1 1

//     // a->ptr = b;
//     // std::cout << a.use_count() << "    " << b.use_count() << std::endl;  // 1 2

//     // b->ptr = a;

//     // std::cout << a.use_count() << "    " << b.use_count() << std::endl;  // 2 2
// }
