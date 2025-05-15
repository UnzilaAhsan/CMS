#ifndef FIND_H
#define FIND_H
#include "Student.h"
#include "Teacher.h"

class Find {
public:
    Student* s;
    int s_ct;
    Teacher* t;
    int t_ct;

    Find();
    Find(Student* student, int s_ct, Teacher* teacher, int t_ct);
    Find(const Find& other);
    Student search(int id);
    Teacher searchTeacher(MyString teacher_id);
    ~Find();
};

#endif
