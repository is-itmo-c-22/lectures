#include <iostream>


int foo() {
    std::cout << "begin foo\n";
    throw std::runtime_error( "error");
    std::cout << "end foo\n";
}

void boo() {
    throw 2;
}

void coo() {
    throw std::string("Hello world");

}






// class Foo {
// public:
//     Foo() {
//         std::cout << "Foo()\n";
//     }

//     ~Foo() {
//         //boo();
//         std::cout << "~Foo()\n";
//     }
// };




void func() noexcept {
    //Foo f;
    int* pi = new int(10);
    foo();
    delete pi;
}

struct Foo {
    int value;

    Foo(int v)
        : value(v)
    {}

    Foo(const Foo& other) {
        value = other.value;
        throw std::runtime_error("KEKW");
    }
};


class Boo {
private:
    Foo* foo_ = nullptr;
    Foo* foo2_ = nullptr;
    int value_ = 0;

public:
    Boo(int value = 0)
        : value_(value)
    {}

    Boo(int value, int foo_value)
        : foo_(new Foo{foo_value})
        , value_(value)
    {}

    ~Boo() {
         delete foo_;
    }

    Boo(const Boo& other)
        : value_(other.value_)
        , foo_(new Foo(*other.foo_))
    {
    }

    Boo& operator=(const Boo& other) {

        if(this == &other)
            return *this;

        Boo tmp(other);

        *this = std::move(tmp);

        return *this;
    }

    friend std::ostream& operator<< (std::ostream& stream, const Boo& value);
};

 std::ostream& operator<< (std::ostream& stream, const Boo& value) {
    stream << "Value: " << value.value_
           << "Foo value: " << (value.foo_ ? value.foo_->value : -1);

    return stream;
 }

#include <vector>

int main(int, char**) {
    std::numeric_limits<char>
    try {
        Boo b1(1, 1);
        Boo b2(2, 2);
        b1 = b2;
    }
    catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
    try{
        std::cout << "try block\n";
        func();

        std::cout << "smth going wong blok\n";

        boo();
        coo();
    }
    catch(const std::exception& e) {
        std::cout << "execption: " << e.what() << std::endl;
    }
    catch(const std::runtime_error& e) {
        std::cout << "runtime_error: " << e.what() << std::endl;
    }
    catch(const std::string& e) {
        std::cout << "string exception: " << e << std::endl;
    }
    catch(int e) {
        std::cout << "int exception " << e << std::endl;
    }
    catch(...) {
        std::cout << "catch block\n";
    }


}

// int main() {
//     std::cout << "Hello world\n";
//     return 0;
// }


// 2 полутоток
// void boo() {
//     throw 2;
// }

// // class Foo {
// // public:
// //     Foo() {
// //         std::cout << "Foo()\n";
// //     }

// //     ~Foo() {
// //         std::cout << "~Foo()\n";
// //         //boo();
// //     }
// // };

// struct Foo {
//     int value;

//     Foo(int v)
//         : value(v)
//     {}

//     Foo(const Foo& other) {
//         value = other.value;
//         throw std::runtime_error("KEKW");
//     }
// };

// class Boo {
// private:
//     Foo* foo_ = nullptr;
//     int value_ = 0;
// public:
//     Boo(int value = 0)
//         : value_(value)
//     {}

//     Boo(int value, int foo_value)
//         : foo_(new Foo{foo_value})
//         , value_(value)
//     {}

//     ~Boo() {
//         delete foo_;
//     }

//     Boo(const Boo& other)
//         : value_(other.value_)
//         , foo_(new Foo(*other.foo_))
//     {
//     }

//     Boo& operator=(const Boo& other) {
//         value_ = other.value_;
//         delete foo_;
//         //foo_ = nullptr;

//         if(other.foo_ != nullptr) {
//             Foo* tmp = new Foo(*other.foo_);
//         }


//         return *this;
//     }

//     friend std::ostream& operator<< (std::ostream& stream, const Boo& value);
// };


// std::ostream& operator<< (std::ostream& stream, const Boo& value) {
//     stream << value.value_ << " " << (value.foo_ ?  value.foo_->value : 0) << std::endl;

//     return stream;
// }


// int foo() {
//     //Foo f;
//     //int* pi = new int(10);
//     throw std::runtime_error( "error");
//     //delete pi;
//     return 0;
// }



// void coo() {
//     throw std::string("Hello world");
// }


// void func() noexcept {
//     foo();
// }

// int main(int, char**) {

//     int i = 3;
//     try {
//         Boo b1(1, 1);
//         Boo b2(2, 2);
//         b1 = b2;
//     }
//     catch(const std::runtime_error& e) {
//         std::cout << e.what() << std::endl;
//     }



//     return 0;
//     try {
//         int i = 3;
//         //Foo f;
//         std::cout << "try block\n";
//         func();
//         std::cout << "smth going wrong\n";
//         //boo();
//         coo();
//     }
//     catch(int e) {
//         std::cout << "int exception " << e << std::endl;
//     }
//     catch(const std::string& str) {
//         std::cout << "string exception " << str << std::endl;
//     }
//     catch(const std::runtime_error& e) {
//         std::cout << "runtime_error exception " << e.what() << std::endl;
//     }
//     catch(const std::exception& e) {
//         std::cout << "std::exception exception " << e.what() << std::endl;
//     }
//     catch(...) {
//         std::cout << "catch block\n";
//     }
// }


