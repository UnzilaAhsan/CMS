#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
public:
    int day, month, year;

    Date();
    Date(int d, int m, int y);
    Date(const Date& other);
    ~Date();
    friend std::ostream& operator<<(std::ostream& os, const Date& dt);
};
#endif 