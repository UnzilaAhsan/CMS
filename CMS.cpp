#include <iostream>
#include "Address.h"
#include "Course.h"
#include "Date.h"
#include "Find.h"
#include "History.h"
#include "MyString.h"
#include "Name.h"
#include "Person.h"
#include "Registration.h"
#include "Section.h"
#include "Semester.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

int main() {
    MyString password;
    cout << "\t\t\t\t---Welcome to the Course Management System---\nPlease enter your password to gain access to the system:\n";
    cin >> password;

    Course c1("OOP", "CS101", 4);
    Course c2("MVC", "CS102", 3);
    Course c3("DSA", "CS103", 4);
    Course c4("DLD", "CS104", 3);
    Course courses1[] = { c1, c2 };
    Course courses2[] = { c3, c4 };
    History h1(courses1, 2, 5.5);
    History h2(courses2, 2, 11);
    Date dob(10, 9, 1990);
    Address addr("Lahore", "Pakistan");
    Name tname1("Talal", "Ahmad");
    Name tname2("Hira", "Fatima");
    Teacher t1("T001", "pass456", h1, dob, addr, tname1, 'M');
    Teacher t2("T002", "pass457", h2, dob, addr, tname2, 'F');
    Teacher teachers[] = { t1, t2 };

    Course courses[] = { c1, c2, c3, c4 };
    Semester sem("Spring2025", courses, 3);

    Name name1("Sara", "Ahmed");
    Date dob1(12, 5, 2002);
    Address addr1("Lahore", "Pakistan");
    Student student1(101, name1, dob1, "saraPwd", addr1, 'F');
    student1.registerInSemester(sem);
    student1.registerInCourse(courses[0]);
    student1.registerInCourse(courses[1]);
    student1.setGrade('B', "CS101");
    student1.setGrade('A', "CS102");

    Name name2("Farah", "Khan");
    Date dob2(3, 9, 2001);
    Address addr2("Lahore", "Pakistan");
    Student student2(102, name2, dob2, "farahPwd", addr2, 'F');
    student2.registerInSemester(sem);
    student2.registerInCourse(courses[1]);
    student2.registerInCourse(courses[2]);
    student2.setGrade('B', "CS102");
    student2.setGrade('A', "CS103");

    Student students[] = { student1, student2 };
    Section s1(t1, students, 2, c1);
    Section sections[] = { s1 };
    int section_ct = 1;

    Find CMS(students, 2, teachers, 2);

    int choice;
    do {
        cout << "\nSelect : \n";
        cout << "1. Student Section\n";
        cout << "2. Teacher Section\n";
        cout << "3. Exit\n";
        cin >> choice;

        switch (choice) {
        case 2: {

            cout << "a. View your history\n";
            cout << "b. Change grade of a student\n";
            cout << "c. View students of a teacher\n";

            char ch;
            cin >> ch;
            if (ch == 'a')
            {
                MyString id;
                cout << "Enter id: \n";
                cin >> id;
                Teacher f = CMS.searchTeacher(id);
                f.viewHistory();
            }
            else if (ch == 'b') {
                MyString course_id;
                char grade;
                int std_id;
                cout << "Enter std id : ";
                cin >> std_id;
                cout << "Enter course id: ";
                cin >> course_id;
                Student v = CMS.search(std_id);
                cout << "Previous grade: " << v.getGrade(course_id) << "\n";
                cout << "New grade: ";
                cin >> grade;
                v.setGrade(grade, course_id);
                cout << "Updated Transcript: \n";
                v.showTranscript();
            }

            else if (ch == 'c')
            {
                MyString tid;
                cout << "Enter teacher ID: ";
                cin >> tid;
                bool found = false;
                for (int i = 0; i < section_ct; i++) {
                    if (sections[i].getTeacherconst().getID() == tid) {
                        found = true;
                        cout << "Course: " << sections[i].getCourse();
                        Student* studs = sections[i].getStudents();
                        for (int j = 0; j < sections[i].getStudentCount(); j++) {
                            cout << "Student: " << studs[j];
                        }
                    }
                }
                if (!found) cout << "No sections found for this teacher.\n";
            }


            break;
        }

        case 1: {

            cout << "a. View your transcript\n";
            cout << "b. view teachers of a student\n";
            char ch;
            cin >> ch;
            if (ch == 'a')
            {
                int id;
                cout << "Enter id: \n";
                cin >> id;
                Student f = CMS.search(id);
                f.showTranscript();
            }
            else if (ch == 'b')
            {
                int sid;
                cout << "Enter student ID: ";
                cin >> sid;
                bool found = false;
                for (int i = 0; i < section_ct; i++) {
                    Student* studs = sections[i].getStudents();
                    for (int j = 0; j < sections[i].getStudentCount(); j++) {
                        if (studs[j].getStudentID() == sid) {
                            found = true;
                            cout << "Taught by: " << sections[i].getTeacherconst();
                            cout << "Course: " << sections[i].getCourse();
                        }
                    }
                }
                if (!found) cout << "No teachers found for this student.\n";
            }
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 3);

    return 0;
}
