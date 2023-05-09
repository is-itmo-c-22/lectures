#include <iostream>
#include <vector>


// 1й полупоток

template<typename T>
class Base {
public:

    void func() {
        T* t = static_cast<T*>(this);
    }
};

class Derrived : public Base<Derrived> {

};


template<typename T>
class Clonable {
public:
    T clone() const {
        return T(static_cast<const T&>(*this));
    }
};

template<typename T>
class Counter {
public:
    static size_t counter;

    Counter() {
        ++counter;
    }

    ~Counter() {
        --counter;
    }
};

template<typename T>
size_t Counter<T>::counter = 0;

class Derrived1 : public Counter<Derrived1>, public Clonable<Derrived1> {

};


class Derrived2 : public Counter<Derrived2> {

};

template<class ConcreateAnimal>
class Animal {
public:
    std::string who() const {
        return static_cast<const ConcreateAnimal*>(this)->who();
    }
};

template<class T>
void who_am_i(Animal<T>& animal) {
    std::cout << animal.who() << std::endl;
}

class Dog : public Animal<Dog> {
public:
    std::string who() const {
        return "dog";
    }
};

class Cat : public Animal<Cat> {
public:
    std::string who() const {
        return "cat";
    }
};


template <class T>
struct Boo {
    void foo() {
        std::cout << "foo" << std::endl;
    }

    void func() {

    }
};

template <>
struct Boo<int> {
    void foo() {
        std::cout << "foo(int)" << std::endl;
    }
};

template <class T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename U>
void swap(std::vector<U>& a, std::vector<U>& b) {
   a.swap(b);
}


struct SomeStruct {};

//template<>
void swap(SomeStruct& a, SomeStruct& b) {
    //...

    std::cout << "swap<SomeStruct>()\n";
}


template<class T>
class auto_ptr {
public:
    auto_ptr(T* ptr = nullptr)
        :ptr_(ptr)
    {}

    ~auto_ptr() {
        delete ptr_;
    }


    auto_ptr(auto_ptr& other) = delete;
    //     : ptr_(other.release()){
    // }

    auto_ptr& operator=(auto_ptr& other) = delete 
    //     if(ptr_ != other.ptr_) {
    //         delete ptr_;
    //         ptr_ = other.release();
    //     }
    // }

    T* operator->() const {
        return ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* release() {
        T* tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    }
private:
    T* ptr_;
};

int main(int, char**) {
    std::vector<int> a(100000, 0);
    std::vector<int> b(100000, 1);


    //SomeStruct a, b;
    swap(a, b);

    // Boo<float> bf;
    // Boo<int>   bi;

    // bf.func();
    // bi.func();


    // Derrived1 d;
    // Derrived1 d2 = d.clone();


    // Cat cat;
    // Dog dog;

    // who_am_i(cat);
    // who_am_i(dog);


    // Derrived1 a, b;
    // Derrived2 c;

    // std::cout << Derrived1::counter << std::endl;
    // std::cout << Derrived2::counter << std::endl;

    return 0;
}


// 2й полупоток

// template<typename T>
// class Counter {
// public:
//     static size_t counter;

//     Counter() {
//         ++counter;
//     }

//     ~Counter() {
//         --counter;
//     }

// };

// template<typename T>
// size_t Counter<T>::counter = 0;

// class Derrived : public Counter<Derrived> {

// };

// class Derrived2 : public Counter<Derrived2> {

// };


// template<typename T>
// class Clonable {
// public:
//     T clone() const {
//         return T(static_cast<const T&>(*this));
//     }
// };



// class Derrived3 : public Clonable<Derrived3> {
// };


// template<class ConcreateAnimal>
// class Animal {
// public:
//     std::string who() const {
//         return static_cast<const ConcreateAnimal*>(this)->who();
//     }

// };

// template<class T>
// void who_am_i(Animal<T>& animal) {
//     std::cout << animal.who() << std::endl;
// }

// class Dog : public Animal<Dog> {
// public:
//     std::string who() const {
//         return "dog";
//     }
// };

// class Cat : public Animal<Cat> {
// public:
//     std::string who() const {
//         return "cat";
//     }
// };

// template<class T>
// struct Boo {
//     void foo() {
//         std::cout << "foo" << std::endl;
//     }

//     void func () {};
// };

// template<>
// struct Boo<int> {
//     void foo() {
//         std::cout << "foo(int)" << std::endl;
//     }
// };


// #include <vector>

// template<typename T>
// void swap(T& a, T& b) {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// template<typename T>
// void swap(std::vector<T>& a, std::vector<T>& b) {
//     a.swap(b);
// }

// struct SomeStruct {

// };

// //template<>
// void swap(SomeStruct& a, SomeStruct& b) {
//    std::cout << "Some struct\n";
// }



// int main(int, char**) {
//     // std::vector<int> v1{100000,0};
//     // std::vector<int> v2{100000,0};

//     // swap(v1, v2);

//     int a = 1;
//     int b = 2;

//     swap(a, b);

//     SomeStruct s1, s2;
//     swap(s1,s2);

//     // Derrived d1;
//     // Derrived d2;

//     // Derrived2 d3;
//     // std::cout << Derrived::counter << std::endl;
//     // std::cout << Derrived2::counter << std::endl;
//     // Derrived3 d4;

//     // d4.clone();

//     // Cat cat;
//     // Dog dog;

//     // who_am_i(cat);
//     // who_am_i(dog);

//     // Boo<float> bf;
//     // Boo<int> bi;

//     // bf.foo();
//     // bi.foo();

//     // bi.func();


// }
