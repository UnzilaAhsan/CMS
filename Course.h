#ifndef COURSE_H
#define COURSE_H

#include "MyString.h"
class Course {
public:
    MyString title, id;
    int cr_hrs;

    Course();
    Course(MyString t, MyString i, int c);
    Course(const Course& other);
    ~Course();

    friend std::ostream& operator<<(std::ostream& os, const Course& c);
    MyString getID() const;
};


#endif