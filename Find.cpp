#include <iostream>
#include "Find.h"
using namespace std;

    Find::Find() : s(nullptr), s_ct(0), t(nullptr), t_ct(0) {}
    Find::Find(Student* student, int s_ct, Teacher* teacher, int t_ct) : s_ct(s_ct), t_ct(t_ct) {
        s = new Student[s_ct];
        for (int i = 0; i < s_ct; i++) s[i] = student[i];
        t = new Teacher[t_ct];
        for (int i = 0; i < t_ct; i++) t[i] = teacher[i];
    }

    Find::Find(const Find& other) : s_ct(other.s_ct), t_ct(other.t_ct) {
        s = new Student[s_ct];
        for (int i = 0; i < s_ct; i++) s[i] = other.s[i];
        t = new Teacher[t_ct];
        for (int i = 0; i < t_ct; i++) t[i] = other.t[i];
    }
    Student Find::search(int id) {
        for (int i = 0; i < s_ct; i++) {
            if (s[i].getStudentID() == id) {
                return s[i];
            }
        }
        return Student();
    }
    Teacher Find::searchTeacher(MyString teacher_id) {
        for (int i = 0; i < t_ct; i++) {
            if (t[i].getID() == teacher_id) {
                return t[i];
            }
        }
        return Teacher();
    }
    Find::~Find() {
        delete[] s;
        delete[] t;
    }


