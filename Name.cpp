#include <iostream>
#include "Name.h"
using namespace std;
   
   Name:: Name() {}
   Name:: Name(MyString fn, MyString ln) : first_name(fn), last_name(ln) {}
   Name:: Name(const Name& other) : first_name(other.first_name), last_name(other.last_name) {}
   Name:: ~Name() {}

   ostream& operator<<(ostream& os, const Name& n) {
        os << n.first_name << " " << n.last_name << "\n";
        return os;
   }

