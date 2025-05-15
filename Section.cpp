#include <iostream>
#include "Section.h"
using namespace std;


    Section::Section() : students(nullptr), std_ct(0) {}
    Section::Section(Teacher t, Student* s, int ct, Course c) : teacher(t), course(c), std_ct(ct) {
        students = new Student[ct];
        for (int i = 0; i < ct; i++) students[i] = s[i];
    }
    Section::Section(const Section& other) : teacher(other.teacher), course(other.course), std_ct(other.std_ct) {
        students = new Student[std_ct];
        for (int i = 0; i < std_ct; i++) students[i] = other.students[i];
    }
    Section::~Section() { delete[] students; }

    Student* Section::getStudents() const { return students; }
    int Section::getStudentCount() const { return std_ct; }
    Teacher Section::getTeacherconst() const { return teacher; }
    Course Section::getCourse() const { return course; }

