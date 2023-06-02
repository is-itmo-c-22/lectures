#include <iostream>


struct Foo {
    Foo() {
     //   std::cout << "Foo()\n";
    }

    ~Foo() {
       // std::cout << "~Foo()\n";
    }
    Foo(const Foo&) {
       // std::cout << "Foo(const Foo&)\n";
    }
    Foo& operator=(const Foo&) {
    //    std::cout << "operator=\n" ; return *this;
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

void foo(Foo& ) {
    std::cout << "void foo(Foo& ) \n";
}

void foo(const Foo& ) {
    std::cout << "void foo(const Foo& ) \n";
}

void foo(Foo&& ) {
    std::cout << "void foo(Foo&& ) \n";
}

template <typename T>
void function (T&& value) {
}


void function (Foo & && value) {
}

// 1  полупоток
int main() {
    Foo f;

    function(f);  //
    function(Foo{});

    return 0;


    Foo f;
    const Foo cf;
    Foo&& rvf = Foo{};

    foo(f);
    foo(cf);
    foo(Foo{});
    foo(rvf); // !!!

    return 0;
    // Foo f = foo3(2);
    return 0;
}



// 2 полупоток
// struct Foo {
//     Foo() {
//        // std::cout << "Foo()\n";
//     }
//     ~Foo() {
//        // std::cout << "~Foo()\n";
//     }
//     Foo(const Foo&) {
//        // std::cout << "Foo(const Foo&)\n";
//     }
//     Foo& operator=(const Foo&) {
//        // std::cout << "operator=\n" ;
//        return *this;
//     }
// };


// Foo foo1() {
//     return Foo();
// }

// Foo foo2() {
//     Foo result;
//     return result;
// }

// Foo foo3(int i) {
//     Foo odd;
//     Foo even;
//     return i % 2 == 0 ? odd : even;
// }

// void foo(Foo& ) {
// std::cout << "void foo(Foo& ) \n";
// }
// void foo(const Foo& ) {
// std::cout << "void foo(const Foo& ) \n";
// }
// void foo(Foo&& ) {
// std::cout << "void foo(Foo&& ) \n";
// }

// int main() {
//  //   Foo f = foo3(2);

//     Foo f;
//     const Foo cf;
//     Foo&& rvf = Foo{};


//     foo(f);
//     foo(cf);
//     foo(Foo{});
//     foo(rvf); // !!!
// }
