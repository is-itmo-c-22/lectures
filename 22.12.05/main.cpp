#include <cstdlib>
#include <iostream>
#include <numeric>
#include <cstring>
#include <vector>


class CRational {
/*
    Числитель (целое) и знаменатель(натуральное), несократимые

    1/2
    -1/2

    2/-4

    2/4 1/2

*/
public:


    explicit CRational(int32_t numerator = 0, int32_t denumerator = 1) {
       // std::cout << "CRational(ctor)\n";
        if(denumerator == 0) {
            // make smth;
        }

        if(denumerator < 0) {
            numerator *= -1;
            denumerator *= -1;
        }

        int gcd = std::gcd(numerator, denumerator);
        numerator_ = numerator / gcd;
        denumerator_ = denumerator / gcd;
    }

    // CRational(const CRational& other)
    //     : numerator_(other.numerator_)
    //     , denumerator_(other.denumerator_)
    // {
    //     std::cout << "CRational(copy)\n";
    // }

    // CRational(CRational&& ) {
    //     std::cout << "CRational(move)\n";
    // }

    ~CRational() {
       //std::cout << "~CRational\n";
    }


    // CRational& operator=(const CRational& other) {
    //     numerator_ = other.numerator_;
    //     denumerator_ = other.denumerator_;
    //     std::cout << "operator=\n";
    //     return *this;
    // }

    void Print() const {
        f();
        std::cout << numerator_ << '/' << denumerator_ << std::endl;
    }

    // int32_t numerator() const {
    //     return numerator_;
    // }

    // uint32_t denumerator() const {

    //     return denumerator_;
    // }

    void f() const {

    }

    bool operator==(const CRational& rhs) const {
        return (numerator_ == rhs.numerator_) && (denumerator_ == rhs.denumerator_);
    }

    bool operator!=(const CRational& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const CRational& rhs)  const {
        return numerator_ * rhs.denumerator_ < denumerator_ * rhs.numerator_;
    }

    bool operator>(const CRational& rhs) const {
        return rhs < *this;
    }

    bool operator<=(const CRational& rhs) const {
        return !(*this > rhs);
    }

    CRational& operator++() {
        numerator_ += denumerator_;
        return *this;
    }

    CRational operator++(int) {
        CRational tmp(*this);
        operator++();
        return tmp;
    }

    explicit operator float() {
        return (float)numerator_/denumerator_;
    }

    friend std::ostream& operator<<(std::ostream& stream, const CRational& r);

    CRational& operator<<(int rhs) {
        numerator_ <<= rhs;
        return *this;
    }

private:
    int32_t numerator_ = 0;
    uint32_t denumerator_ = 1;

};

class GeoPoint {
public:
    GeoPoint() = default;

    explicit GeoPoint(const CRational& lat, const CRational& lon)
        : lat_(lat)
        , lon_(lon)
    {
        std::cout << "GeoPoint(ctor)\n";
    }

    GeoPoint(const GeoPoint& other) = delete;
    // GeoPoint(const GeoPoint& other)
    //     : lat_(other.lat_)
    //     , lon_(other.lon_)
    // {
    //     std::cout << "GeoPoint(copy)\n";
    // }

    GeoPoint& operator=(const GeoPoint& other) = delete;

    // GeoPoint& operator=(const GeoPoint& other) {
    //     std::cout << "GeoPoint operator=\n";
    //     lat_ = other.lat_;
    //     lon_ = other.lon_;

    //     return *this;
    // }

    // ~GeoPoint() {
    //     std::cout << "~GeoPoint\n";
    // }

private:
    CRational lat_;
    CRational lon_;
};

std::ostream& operator<<(std::ostream& stream, const CRational& r) {
    stream << r.numerator_ << "/" << r.denumerator_;
    return stream;
}

std::istream& operator>>(std::istream& stream, CRational& r) {
    int n;
    int d;
    char ch;
    stream >> n;
    stream >> ch;
    stream >> d;

    r = CRational(n,d);

    return stream;
}

// void PrintRational(const CRational& number) {
//     std::cout << number.numerator()
//     << '/'
//     << number.denumerator()
//     << std::endl;
// }


void f(int value) {
    std::cout << "void f(int value)\n";
}


int twice(int value) {
    return 2 * value;
}

class CMultilpy {
public:
    CMultilpy(int mult)
        : mult_(mult)
    {}

    int operator()(int value) const {
        return mult_ * value;
    }

private:
    int mult_;
};

#include <cstdio>


class CFile {
public:
    CFile(const char* path, const char* mode)
        : file_(std::fopen(path, mode))
    {}

    ~CFile() {
        if(file_ != nullptr)
            fclose(file_);
    }

    operator FILE*() {
        return file_;
    }

private:
    FILE* file_;
};

void func() {
    CFile stream("text.dat", "w");

    fprintf(stream, "ITMO");

    return ;

}

class Foo {
public:
    Foo() = default;

    explicit Foo(int value)
        : value_(value)
    {}

    int value() const {
        return value_;
    }

private:
    int value_ = 2022;
};


// class FooPtr {
// public:
//     FooPtr(Foo* ptr = nullptr)
//         : ptr_(ptr)
//     {}

//     FooPtr(int value)
//         : ptr_(new Foo(value))
//     {}

//     ~FooPtr() {
//         delete ptr_;
//     }

//     Foo* operator->() const {
//         return ptr_;
//     }

//     Foo& operator*() {
//         return *ptr_;
//     }

// private:
//     Foo* ptr_;
// };

void func2() {
    // FooPtr ptr(new Foo(2023));

    // Foo* fooPtr = new Foo(10);

    // std::cout << ptr->value() << std::endl;
    // std::cout << (*ptr).value() << std::endl;

    Foo f(2022);

    return;


}

int main() {

    CRational r{2,4};

    r.operator<<(1);

    std::cout << r << std::endl;

    return 0;
}






// // class CIntArray {
// // public:
// //     CIntArray(size_t size)
// //         : array_(new int[size])
// //         , size_(size)
// //     {}

// //     ~CIntArray() {
// //         delete[] array_;
// //     }

// //     CIntArray(const CIntArray& other) = delete;
// //     //     : array_(new int[other.size_])
// //     //     , size_(other.size_)
// //     // {
// //     //     std::memcpy(array_, other.array_, sizeof(int) * size_);
// //     // }


// //     CIntArray& operator=(const CIntArray& other) = delete;
// //     // {
// //     //     if(this == &other)
// //     //         return *this;

// //     //     if(size_ != other.size_) {
// //     //         delete[] array_;
// //     //         array_ = new int[other.size_];
// //     //     }
// //     //     size_ = other.size_;

// //     //     std::memcpy(array_, other.array_, sizeof(int) * size_);
// //     //     return *this;
// //     // }

// // private:
// //     int* array_;
// //     size_t size_;

// // };

















//2й полупоток

// class CRational {
// /*
//     Несократимыя дробь
// */

// public:
//     explicit CRational(int32_t numerator = 0, int64_t denuminator = 1) {

//         if(denuminator == 0) {
//             // make smth;
//         }
//         if(denuminator < 0) {
//             denuminator *= -1;
//             numerator *= -1;
//         }

//         unsigned gcd = std::gcd(numerator, denuminator);
//         numerator_ = numerator / gcd;
//         denuminator_ = denuminator / gcd;
//     }

//     // CRational(const CRational& other)
//     //     : numerator_(other.numerator_)
//     //     , denuminator_(other.denuminator_)
//     // {
//     //     std::cout << "CRational(copy)\n";
//     // }

//     // CRational& operator=(const CRational& other) {
//     //     std::cout << "CRational& operator=\n";
//     //     numerator_ = other.numerator_;
//     //     denuminator_ = other.denuminator_;

//     //     return *this;
//     // }

//     ~CRational() {

//     }

//     void print() const {
//         std::cout << numerator_ << '/' << denuminator_ << std::endl;
//     }

//     // int32_t numerator() const {
//     //     return numerator_;
//     // }

//     // uint32_t denuminator() const {
//     //     return denuminator_;
//     // }

//     CRational operator+(const CRational& rhs) {
//         return CRational(numerator_ * rhs.denuminator_ + rhs.numerator_ * denuminator_, denuminator_ * rhs.denuminator_);
//     }

//     bool operator<(const CRational& rhs) {
//         return numerator_ * rhs.denuminator_ < rhs.numerator_ * denuminator_;
//     }

//     bool operator>(const CRational& rhs) {
//         return numerator_ * rhs.denuminator_ > rhs.numerator_ * denuminator_;
//     }


//     CRational operator++(int) {
//         CRational tmp = *this;
//         numerator_ += denuminator_;
//         return tmp;
//     }

//     CRational& operator++() {
//         numerator_ += denuminator_;
//         return *this;
//     }

//     operator float() const {
//         return (float)numerator_/denuminator_;
//     }

//     friend std::ostream& operator<<(std::ostream& stream, const CRational& value);

//     friend int main(int, char**);

// private:
//     int32_t numerator_;
//     uint32_t denuminator_;

// };


// // CRational operator*(const CRational& lhs, const CRational& rhs) {
// //     return CRational(lhs.numerator() * rhs.numerator(), lhs.denuminator() * rhs.denuminator());
// // }

// // bool operator==(const CRational& lhs, const CRational& rhs) {
// //     return lhs.numerator() * rhs.denuminator() == rhs.numerator() * lhs.denuminator();
// // }


// // bool operator!=(const CRational& lhs, const CRational& rhs) {
// //     return !(lhs == rhs);
// // }

// class GeoPoint {

// public:
//     GeoPoint() = default;

//     GeoPoint(const GeoPoint&) = delete;

//     GeoPoint(const CRational& lat, const CRational& lon)
//          : lat_(lat)
//          , lon_(lon)
//     {
//         std::cout << "GetPoint(copy)\n";
//     }

//     ~GeoPoint() {
//         std::cout << "~GetPoint\n";
//     };


//     GeoPoint& operator=(const GeoPoint&) = delete;



// private:
//     CRational lat_;
//     CRational lon_;
// };

// // void PrintRational(const CRational& number) {
// //     std::cout << number.numerator()
// //     << '/'
// //     << number.denuminator()
// //     << std::endl;
// // }


// class CIntArray {
// public:
//     CIntArray(size_t size)
//         : array_(new int[size])
//         , size_(size)
//     {
//         //static_assert(size > 0);
//     }

//     ~CIntArray() {
//         delete[] array_;
//     }

//     CIntArray(const CIntArray& other)
//         : array_(new int[other.size_])
//         , size_(other.size_)
//     {
//         std::memcpy(array_, other.array_, sizeof(int)*size_);
//     }

//     CIntArray& operator=(const CIntArray& other) {
//         if(this == &other)
//             return *this;

//         delete[] array_;

//         array_ = new int[other.size_];
//         size_ = other.size_;
//         std::memcpy(array_, other.array_, sizeof(int)*size_);

//         return *this;
//     }

//     int& operator[](size_t idx) {
//         return array_[idx];
//     }


// private:
//     int* array_;
//     size_t size_;
// };

// std::ostream& operator<<(std::ostream& stream, const CRational& value) {
//     stream << value.numerator_ << "/" << value.denuminator_;

//     return stream;
// }

// // CRational operator*(int lhs, const CRational& rhs) {
// //     return CRational(lhs * rhs.numerator(), rhs.denuminator());
// // }



// class Multiply {
// public:
//     Multiply(int mult)
//         : mult_(mult)
//     {}

//     int operator()(int value) {
//         return mult_ * value;
//     }
// private:
//     int mult_;
// };


// // int twice(int value) {
// //     return 2 * value;
// // }

// #include <vector>
// #include <algorithm>



// int main(int, char**) {
//     Multiply twice(2);

//     //std::cout << twice(2) << std::endl;
//     std::cout << twice(2) << std::endl;

//     std::vector<int> v = {1,2,3,4,5};
//     std::transform(v.begin(), v.end(), v.begin(), Multiply{5});

//     for(int i : v) {
//         std::cout << i << " ";
//     }

//     std::cout << std::endl;

//     return 0;
// }
