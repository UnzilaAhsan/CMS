#ifndef SEMESTER_H
#define SEMESTER_H
#include "MyString.h"
#include "Course.h"

class Semester {
public:
    MyString sem_id;
    Course* offered;
    int offered_ct;

    Semester();
    Semester(MyString id, Course* courses, int count);
    Semester(const Semester& s);
    ~Semester();
    MyString getSemID() const;
    friend std::ostream& operator<<(std::ostream& os, const Semester& s);
};
#endif
