#include <iostream>
#include "Course.h"
using namespace std;

   Course:: Course() {}
   Course:: Course(MyString t, MyString i, int c) : title(t), id(i), cr_hrs(c) {}
   Course:: Course(const Course& other) : title(other.title), id(other.id), cr_hrs(other.cr_hrs) {}
   Course::~Course() {}

    ostream& operator<<(ostream& os, const Course& c) {
        os << "Course Title: " << c.title << ", ID: " << c.id << ", Credit Hours: " << c.cr_hrs << endl;
        return os;
    }

   MyString Course::getID() const { return id; }

