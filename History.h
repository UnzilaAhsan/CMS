#ifndef HISTORY_H
#define HISTORY_H
#include "Course.h"

class History {
    int course_ct;
    Course* courses;
    float experience;

public:
    History();
    History(Course c[], int ct, float e);
    History(const History& other);
    ~History();

    friend std::ostream& operator<<(std::ostream& os, const History& h);
};
#endif