#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "MyString.h"
#include "History.h"

class Teacher : public Person {
public:
    MyString pwd;
    History history;
    MyString id;

    Teacher();
    Teacher(MyString i, MyString p, History h, Date d, Address a, Name n, char g);
    Teacher(const Teacher& other);
    MyString getPwd() const;
    MyString getID() const;
    void viewHistory() const;
    friend std::ostream& operator<<(std::ostream& os, const Teacher& t);
    ~Teacher();
};


#endif
