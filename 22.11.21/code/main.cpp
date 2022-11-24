#include <iostream>
#include <numeric>


class CRational {
/*
    Числитель (целое) и знаменатель(натуральное), несократимые

    1/2
    -1/2

    2/-4

    2/4 1/2

*/
public:


    CRational(int32_t numerator = 0, int32_t denumerator = 1) {
        std::cout << "CRational\n";
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

    CRational(const CRational& other)
        : numerator_(other.numerator_)
        , denumerator_(other.denumerator_)
    {
        std::cout << "CRational(copy)\n";
    }

    // CRational(CRational&& ) {
    //     std::cout << "CRational(move)\n";
    // }

    ~CRational() {
        std::cout << "~CRational\n";
    }


    CRational& operator=(const CRational& other) {
        numerator_ = other.numerator_;
        denumerator_ = other.denumerator_;

        return *this;
    }

    void Print() const {
        f();
        std::cout << numerator_ << '/' << denumerator_ << std::endl;
    }

    int32_t numerator() const {
        return numerator_;
    }

    uint32_t denumerator() const {

        return denumerator_;
    }

    void f() const {

    }

private:
    int32_t numerator_ = 0;
    uint32_t denumerator_ = 1;

};



int main() {
    // CRational r(-2,-4);
    // //CRational r2 = r;
    // CRational r3;
    // r3 = r;

    // r3.Print();

    CRational* pr = (CRational*)malloc(sizeof(CRational));
    free(pr);
    //delete pr;


    return 0;
}













// 2й полупоток

// class CRational {
// /*
//     Несократимыя дробь
// */

// public:
//     CRational(int32_t numerator = 0, int64_t denuminator = 1) {
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

//     CRational(const CRational& other)
//         : numerator_(other.numerator_)
//         , denuminator_(other.denuminator_)
//     {
//     }

//     CRational& operator=(const CRational& other) {
//         numerator_ = other.numerator_;
//         denuminator_ = other.denuminator_;

//         return *this;
//     }

//     ~CRational() {

//     }

//     void print() const {
//         f();
//         std::cout << numerator_ << '/' << denuminator_ << std::endl;
//     }

//     int32_t numerator() const {
//         return numerator_;
//     }

//     uint32_t denuminator() const {
//         return denuminator_;
//     }

//     void f() const {

//     }
// private:
//     int32_t numerator_;
//     uint32_t denuminator_;
//     int* n ;
// };

// int main(int, char**) {

//     CRational r(-1,2);
//     CRational r2 = r;
//     CRational r3;
//     r3 = r;


//     r.print();


//     // #0 1/3
//     // #1 -5/-2
//     // #2  2/4 == 1/2

//     int i = 1;
//     int* n = new int(2);

//     delete n ;

//     return 0;
// }
