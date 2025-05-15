#include <iostream>
#include "Date.h"
using namespace std;


   Date:: Date() :day(0), month(0), year(0) {}
   Date::Date(int d, int m, int y) {
        if (d > 0 && d <= 31 && m > 0 && m <= 12 && y > 0 && y <= 2025)
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            day = month = year = 0;
        }
    }
   Date:: Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}
   Date:: ~Date() {}

    ostream& operator<<(ostream& os, const Date& dt) {
        os << dt.day << "/" << dt.month << "/" << dt.year << "\n";
        return os;
    }
