#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Registration.h"
#include "MyString.h"

class Student : public Person {
public:
    int std_id;
    Registration* reg;
    MyString pwd;

    Student();
    Student(int id, Name n, Date d, MyString p, Address a, char g);
    int getStudentID() const;
    MyString getPwd() const;
    void registerInSemester(const Semester& s);
    void registerInCourse(const Course& c);
    void showTranscript();
    ~Student();
    void setGrade(char grade, MyString course_id);
    char getGrade(MyString course_id);
};

#endif
