#include <iostream>
#include "Semester.h"
using namespace std;


    Semester::Semester() : offered(nullptr), offered_ct(0) {}
    Semester::Semester(MyString id, Course* courses, int count) : sem_id(id), offered_ct(count) {
        offered = new Course[offered_ct];
        for (int i = 0; i < offered_ct; i++) {
            offered[i] = courses[i];
        }
    }
    Semester::Semester(const Semester& s) : sem_id(s.sem_id), offered_ct(s.offered_ct) {
        offered = new Course[offered_ct];
        for (int i = 0; i < offered_ct; ++i) {
            offered[i] = s.offered[i];
        }
    }
    Semester::~Semester() { delete[] offered; }
    MyString Semester::getSemID() const { return sem_id; }
    ostream& operator<<(ostream& os, const Semester& s) {
        os << "Semester : " << s.sem_id << "\nOffered Courses: ";
        for (int i = 0; i < s.offered_ct; i++) {
            os << s.offered[i];
        }
        return os;
    }

