#ifndef NAME_H
#define NAME_H
#include "MyString.h"

class Name {
public:
    MyString first_name, last_name;
    Name();
    Name(MyString fn, MyString ln);
    Name(const Name& other);
    ~Name();

    friend std::ostream& operator<<(std::ostream& os, const Name& n);
};

#endif // !NAME_H
