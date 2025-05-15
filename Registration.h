#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "Semester.h"
#include "Course.h"

class Registration {
public:
    Semester sem;
    Course* enrolled;
    int enrolled_ct;
    char* grades;

    Registration();
    Registration(const Semester& s);
    void enrollInCourse(const Course& course);
    void printRegistration();
    ~Registration();
    void setGrade(char grade, MyString course_id);
    char getGrade(MyString course_id) const;
};

#endif
