#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString {
    char* data;
    int length;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    bool operator==(const MyString& other) const;
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    const char* c_str() const;
    ~MyString();
};

#endif // MYSTRING_H
