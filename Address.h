#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include "MyString.h"

class Address {
public:
    MyString city, country;
    Address();
    Address(MyString c, MyString co);
    Address(const Address& other);
    ~Address();

    friend std::ostream& operator<<(std::ostream& os, const Address& a);
};

#endif // !ADDRESS_H
