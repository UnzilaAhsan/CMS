#include <iostream>
#include "Person.h"
using namespace std;

    Person::Person() {}
    Person::Person(Date d, Address a, Name n, char g) : dob(d), addr(a), name(n), gender(g) {}
    Person::Person(const Person& p) : dob(p.dob), addr(p.addr), name(p.name), gender(p.gender) {}
    Person::~Person() {}

    std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Name: " << p.name << "DOB: " << p.dob << "Address: " << p.addr << "Gender: " << p.gender << "\n";
        return os;
    }
