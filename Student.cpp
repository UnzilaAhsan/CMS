#include <iostream>
#include "Student.h"
using namespace std;


    Student::Student() : std_id(0), reg(nullptr) {}
    Student::Student(int id, Name n, Date d, MyString p, Address a, char g)
        : Person(d, a, n, g), std_id(id), reg(nullptr), pwd(p) {}

    int Student::getStudentID() const { return std_id; }
    MyString Student::getPwd() const { return pwd; }
    void Student::registerInSemester(const Semester& s) {
        if (reg != nullptr) delete reg;
        reg = new Registration(s);
    }
    void Student::registerInCourse(const Course& c) {
        if (reg) {
            reg->enrollInCourse(c);
        }
    }
    void Student::showTranscript() {
        if (reg) {
            cout << "Transcript for Student ID: " << std_id << ", Name: " << name;
            reg->printRegistration();
        }
    }
    Student::~Student() {
        delete reg;
    }
    void Student::setGrade(char grade, MyString course_id)
    {
        reg->setGrade(grade, course_id);
    }
    char Student::getGrade(MyString course_id)
    {
        return reg->getGrade(course_id);
    }
