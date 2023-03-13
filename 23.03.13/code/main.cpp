#include <iostream>
#include <vector>

#include <map>

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }

    Foo(const Foo&) {
        std::cout << "Foo(const Foo&)\n";
    }

    Foo& operator=(const Foo&) {
        std::cout << "operator=(const Foo&)\n";
        return *this;
    }

    ~Foo() {
        std::cout << "~Foo()\n";
    }

    bool operator<(const Foo&) const {
        return true;
    }
};

int main () {

    std::map<Foo, int> m;
    m.insert({Foo{}, 1});


    std::vector<Foo> v;
    v.reserve(3);
   // std::cout << "Size of int " << sizeof(int) << std::endl;
   // std::cout << sizeof(v) << std::endl;
   // std::cout << "Capacity: " << v.capacity() << " Size: " << v.size() << std::endl;

    for(int i = 0; i < 3; ++i) {
        v.emplace_back();
        //v[i] = Foo{};

      //  std::cout << i << ": Capacity: " << v.capacity() << " Size: " << v.size() << std::endl;
    }
    // 16 * sizeof(int) + 24
}


// 2й полупоток
// struct Foo {
//     int value;

//     bool operator<(const Foo& other) const {
//         return value < other.value;
//     }
//  };


// int main(int, char**) {

//     std::map<Foo, int> m;
//     m.insert({Foo{}, 1});
//     // std::cout << "Size of int " << sizeof(int) << std::endl;
//     // std::vector<int> v(9);
//     // v.resize(3);
//     // v.reserve(1);
//     // std::cout << "Capacity: " << v.capacity() << " Size: " << v.size() << " v size " << sizeof(v) << std::endl;

//     // for(int i = 0; i < 10; ++i) {
//     //     //v.push_back(i);
//     //     v[i] = i;
//     //     std::cout << i << ": Capacity: " << v.capacity() << " Size: " << v.size()<< " v size " << sizeof(v) << std::endl;
//     // }

//     return 0;
// }
