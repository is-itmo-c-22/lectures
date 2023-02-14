#include <iostream>
#include <chrono>

#include <iostream>


//1 полупоток
class CPerson {
public:
    CPerson(const std::string& name, int year)
        : name_(name)
        , year_(year)
    {
        std::cout << "CPerson(ctor)\n";
    }

    ~CPerson() {
        std::cout << "~CPerson()\n";

    }

    int age() const {
        int current_year =  2023; /// хитрый код для вычисления года
        return current_year - year_;
    }

    void set_name(const std::string& name) {
        name_ = name;
    }

    const std::string& name() const {
        return name_;
    }

protected:
    int year_;
private:
    std::string name_;

};

int howOldIn(const CPerson& p, int year)  {
    int current_year = 2023; //
    return year - current_year + p.age();
}

// Student is a person who studing in University


class Shape {

};


class Square  {
public:
    Square(unsigned size)
        : width(size)
    {}
    int width;
};

class Rect : public Square {
public:
    Rect(unsigned w, unsigned h)
        : Square(w)
        , height(h)
    {}

    unsigned height;

};


int area(const Square& sq) {
    return sq.width * sq.width;

}




void duble_width(Rect& r) {
    r.width *= 2;
}







class CStudent : public CPerson {
public:
    CStudent(
        const std::string& name,
        int year,
        const std::string& university
    ) : CPerson(name, year)
      , university_(university)
    {
        std::cout << "CStudent(ctor)\n";
    }

    ~CStudent() {
        std::cout << "~CStudent()\n";
    }

    const std::string& university() const {
        return university_;
    }

private:
    std::string university_;
};


class BudgetStudent : public CStudent {
public:
    BudgetStudent(
        const std::string& name,
        int year,
        const std::string& university,
        uint16_t sallary
    ) : CStudent(name, year, university)
      , sallary_(sallary)
    {
        std::cout << "BudgetStudent(ctor)\n";
    }

    ~BudgetStudent() {
        std::cout << "~BudgetStudent()\n";
    }

    void descreaseSallary(uint32_t sallary) {
        sallary_ -= sallary;
    }
private:
    uint16_t sallary_;
};


class CEmployee : public CPerson {
public:
    CEmployee(const std::string& name, int year, uint32_t sallary)
        : CPerson(name, year)
        , sallary_(sallary)
    {}

    void descreaseSallary(uint32_t sallary) {
        sallary_ -= sallary;
    }

private:
    uint32_t sallary_;
};

class CIntern : public BudgetStudent, public CEmployee {
public:


    CIntern(
        const std::string& name,
        int year,
        const std::string& university,
        uint16_t univ_sallary,
        uint32_t work_sallary
    ) : BudgetStudent(name, year, university, univ_sallary)
      , CEmployee(name, year, work_sallary)
    {}

    void descreaseSallary(uint32_t sallary) {
        CEmployee::descreaseSallary(sallary);
        BudgetStudent::descreaseSallary(sallary);
    }
};


class CLogger {
public:
     virtual void Log(const std::string& msg) {}

     virtual ~CLogger() = default;
};

class CConsoleLogger : public CLogger { 
public:
    void Log(const std::string& msg) {
        std::cout << "[Log] " << msg;
    }
};

#include <fstream>

class CFileLogger : public CLogger {
public:
    CFileLogger(const std::string& path)
        : stream_(path)
    {}

    ~CFileLogger() {
        stream_.close();
    }

    void Log(const std::string& msg) {
        stream_ << "[Log] " << msg;
    }

private:
    std::fstream stream_;
};

void func(CLogger& log) {
    log.Log("I am func\n");
}





int main(int, char**) {
    std::cout << sizeof(CLogger) << std::endl;
    std::cout << sizeof(CConsoleLogger) << std::endl;
    std::cout << sizeof(CFileLogger) << std::endl;

    CConsoleLogger logger;
    func(logger);

    //BudgetStudent p{"Ivan Ivanov", 2004, "ITMO", 15000};
    // std::cout << sizeof(CPerson) << std::endl;
    // std::cout << sizeof(CStudent) << std::endl;
    // std::cout << sizeof(BudgetStudent) << std::endl;
    // std::cout << sizeof(CEmployee) << std::endl;
    // std::cout << sizeof(CIntern) << std::endl;


    // CIntern intern ("Ivan Ivanov", 2004, "ITMO", 15000, 58743);
    // ///std::cout << intern.CEmployee::name() << std::endl;
    // intern.descreaseSallary(1000);


   // std::cout << howOldIn(p, 2036) << std::endl;

    return 0;
}








// 2 поток
// class CPerson {
// public:
//     CPerson(const std::string& name, int year)
//         : name_(name)
//         , year_(year)
//     {
//         std::cout << "CPerson(ctor)\n";
//         assert(name.length() != 0);
//     }

//     ~CPerson() {
//         std::cout << "CPerson(dtor)\n";
//     }

//     const std::string& name() const {
//         return name_;
//     }

//     int age() const {
//         int current_year = 2023; // хитрый код вычисляющий год
//         return current_year - year_;
//     }

//     void changeYear(){
//         year_ = 20;
//     }

// protected:
//     std::string name_;
//     int year_;
// };

// int howOldIn(const CPerson& person, int year) {
//     int current_year = 2023; // хитрый код вычисляющий год
//     return year - person.age() - current_year;
// }

// // Student is a person who studing in university

// class CStudent : public CPerson {
// public:
//     CStudent(
//         const std::string& name,
//         unsigned year,
//         const std::string& university
//     ) : CPerson(name, year)
//       , university_ (university)
//     {
//         std::cout << "CStudent(ctor)\n";
//     }


//     ~CStudent() {
//         std::cout << "CStudent(dtor)\n";
//     }

//     const std::string& university() const {
//         return university_;
//     }

//     void func() {
//         year_ = 20;
//     }

// private:
//     std::string university_;
// };

// class BudgetStudent : public CStudent {
// public:
//     BudgetStudent(
//         const std::string& name,
//         int year,
//         const std::string& university,
//         uint16_t sallary
//     ) : CStudent(name, year, university)
//       , sallary_(sallary)
//     {}

//     void increaseSallary(uint32_t value) {
//         sallary_ += value;
//     }

// private:
//     uint16_t sallary_;
// };


// class CEmployee : public CPerson {
// public:
//     CEmployee(const std::string& name, int yearOfBord, uint32_t sallary)
//         : CPerson(name, yearOfBord)
//         , sallary_(sallary)
//     {}

//     void increaseSallary(uint32_t value) {
//         sallary_ += value;
//     }

// private:
//     uint32_t sallary_;
// };


// class CIntern : public BudgetStudent, public CEmployee {
// public:


//     CIntern(
//         const std::string& name,
//         int year,
//         const std::string& university,
//         uint16_t univ_sallary,
//         uint32_t work_sallary
//     ) : BudgetStudent(name, year, university, univ_sallary)
//       , CEmployee(name, year, work_sallary)
//     {}

//     void increaseSallary(uint32_t value) {
//         BudgetStudent::increaseSallary(value);
//         CEmployee::increaseSallary(value);
//     }
// };


// class Figure {

// };



// class Square : public Figure {
// public:
//     Square(unsigned size)
//         : width(size)
//     {};
//     int width;
// };


// class Rect : public Square {
// public:
//     Rect(int w, int h)
//         : Square(w)
//         , height(h)
//     {}

//     unsigned height;
// };

// void double_width(Rect& r) {
//     r.width *= 2;
// }


// unsigned area(const Square& sq) {
//     return sq.width * sq.width;
// }



// class CLogger {
// public:
//     virtual void Log(const char* message) {}
// };

// class CConsoleLogger : public CLogger {
// public:
//     void Log(const char* message) {
//         std::cout << "[Log]: " << message;
//     }
// };


// #include <fstream>

// class CFileLogger : public CLogger {
// public:
//     CFileLogger(const std::string& path)
//         : stream_(path) {

//     }

//     ~CFileLogger() {
//         stream_.close();
//     }

//     void Log(const char* message) {
//         stream_ << "[Log]: " << message;
//     }
// private:
//     std::fstream stream_;
// };

// void func(CLogger& log) {
//     log.Log("I am func\n    ");
// }



// int main(int, char**) {

//     std::cout << sizeof(CLogger) << std::endl;
//     std::cout << sizeof(CConsoleLogger) << std::endl;
//     std::cout << sizeof(CFileLogger) << std::endl;


//     CConsoleLogger log;
//     func(log);

//     // // std::cout << "Hello new lection" << std::endl;
//     // BudgetStudent p{"Ivan Ivanov", 2004, "ITMO", 2000};
//     // // std::cout << p.age();


//     // std::cout << sizeof(CPerson) << std::endl;
//     // std::cout << sizeof(CStudent) << std::endl;
//     // std::cout << sizeof(BudgetStudent) << std::endl;
//     // std::cout << sizeof(CEmployee) << std::endl;
//     // std::cout << sizeof(CIntern) << std::endl;

//     // CIntern intern("Ivan Ivanov", 2004, "ITMO", 2000, 10000000);
//     // std::cout << intern.CEmployee::name();
//     // intern.increaseSallary(10000);

//     // // std::cout << howOldIn(p, 2036) << std::endl;



//     return 0;
// }
