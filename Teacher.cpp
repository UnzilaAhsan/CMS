#include <iostream>
#include "Teacher.h"
using namespace std;

    Teacher::Teacher() {}
    Teacher::Teacher(MyString i, MyString p, History h, Date d, Address a, Name n, char g)
        : Person(d, a, n, g), id(i), pwd(p), history(h) {}

    Teacher::Teacher(const Teacher& other)
        : Person(other), pwd(other.pwd), history(other.history), id(other.id) {}

    MyString Teacher::getPwd() const { return pwd; }
    MyString Teacher::getID() const { return id; }
    void Teacher::viewHistory() const { cout << history; }
    ostream& operator<<(ostream& os, const Teacher& t)
    {
        os << static_cast<const Person&>(t); 
        os << "ID: " << t.id << "\nPassword: " << t.pwd << "\nHistory:\n" << t.history;
        return os;
    }
    Teacher::~Teacher() {}


