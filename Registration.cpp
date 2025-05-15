#include <iostream>
#include "Registration.h"
using namespace std;


    Registration::Registration() : enrolled(nullptr), enrolled_ct(0), grades(nullptr) {}
    Registration::Registration(const Semester& s) : sem(s), enrolled_ct(0), enrolled(nullptr), grades(nullptr) {}
    void Registration::enrollInCourse(const Course& course) {
        Course* temp = new Course[enrolled_ct + 1];
        for (int i = 0; i < enrolled_ct; i++) {
            temp[i] = enrolled[i];
        }
        temp[enrolled_ct] = course;
        delete[] enrolled;
        enrolled = temp;
        enrolled_ct++;

        char* tempGrades = new char[enrolled_ct];
        for (int i = 0; i < enrolled_ct - 1; i++) {
            tempGrades[i] = grades ? grades[i] : ' ';
        }
        tempGrades[enrolled_ct - 1] = ' ';
        delete[] grades;
        grades = tempGrades;
    }

    void Registration::printRegistration() {
        cout << "Semester: " << sem.getSemID() << "\n";
        for (int i = 0; i < enrolled_ct; i++) {
            cout << enrolled[i] << "Grade: " << grades[i] << "\n";
        }
    }
    Registration::~Registration() {
        delete[] enrolled;
        delete[] grades;
    }
    void Registration::setGrade(char grade, MyString course_id)
    {
        for (int i = 0; i < enrolled_ct; i++)
        {
            if (enrolled[i].getID() == course_id)
            {
                grades[i] = grade;
            }
        }
    }
    char Registration::getGrade(MyString course_id) const
    {
        for (int i = 0; i < enrolled_ct; i++)
        {
            if (enrolled[i].getID() == course_id) return grades[i];
        }
    }
