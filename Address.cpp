#include <iostream>
#include "Address.h"
using namespace std;

    Address::Address() {}
    Address::Address(MyString c, MyString co) : city(c), country(co) {}
    Address::Address(const Address& other) : city(other.city), country(other.country) {}
    Address::~Address() {}
    ostream& operator<<(ostream& os, const Address& a) {
        os << a.city << ", " << a.country << "\n";
        return os;
    }
