#include "MyString.h"
#include <iostream>
using namespace std; 

MyString::MyString() : data(nullptr), length(0) {}
MyString::MyString(const char* str) {
    length = 0;
    while (str[length] != '\0') length++;

    data = new char[length + 1];
    for (int i = 0; i < length; i++)
        data[i] = str[i];
    data[length] = '\0';
}
MyString::MyString(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    for (int i = 0; i < length; i++)
        data[i] = other.data[i];
    data[length] = '\0';
}
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
        data[length] = '\0';
    }
    return *this;
}
bool MyString::operator==(const MyString& other) const {
    if (length != other.length) return false;
    for (int i = 0; i < length; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}
ostream& operator<<(ostream& os, const MyString& str) {
    for (int i = 0; i < str.length; i++) os << str.data[i];
    return os;
}
istream& operator>>(istream& is, MyString& str) {
    char temp[100];
    is >> temp;
    delete[] str.data;       
    str = MyString(temp);  
    return is;
}

const char* MyString::c_str() const {
    return data;
}
MyString::~MyString() {
    delete[] data;
}
