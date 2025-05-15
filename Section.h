#ifndef SECTION_H
#define SECTION_H
#include "Teacher.h"
#include "Student.h"
#include "Course.h"

class Section {
public:
    Teacher teacher;
    Student* students;
    int std_ct;
    Course course;

    Section();
    Section(Teacher t, Student* s, int ct, Course c);
    Section(const Section& other);
    ~Section();

    Student* getStudents() const;
    int getStudentCount() const;
    Teacher getTeacherconst() const;
    Course getCourse() const;
};


#endif