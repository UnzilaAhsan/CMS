#include <iostream>
#include "History.h"
using namespace std;

    History::History() : course_ct(0), courses(nullptr), experience(0) {}
    History::History(Course c[], int ct, float e) : course_ct(ct), experience(e) {
        courses = new Course[ct];
        for (int i = 0; i < ct; i++)
            courses[i] = c[i];
    }
    History::History(const History& other) : course_ct(other.course_ct), experience(other.experience) {
        courses = new Course[course_ct];
        for (int i = 0; i < course_ct; i++)
            courses[i] = other.courses[i];
    }
    History::~History() { delete[] courses; }

    ostream& operator<<(ostream& os, const History& h) {
        os << "Courses in History:\n";
        for (int i = 0; i < h.course_ct; i++)
            os << h.courses[i];
        os << "Experience: " << h.experience << " years\n";
        return os;
    }
