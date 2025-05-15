#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include "Address.h"
#include "Name.h"

class Person {
public:
    Date dob;
    Address addr;
    Name name;
    char gender;

    Person();
    Person(Date d, Address a, Name n, char g);
    Person(const Person& p);
    ~Person();

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif