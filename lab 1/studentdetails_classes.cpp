#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // Include for find_if

using namespace std;  // Corrected to 'std'

class Course {
public:
    string course_code;
    string course_name;

    void inputCourseDetails() {
        cout << "Enter course code: ";
        cin >> course_code;
        cout << "Enter course name: ";
        cin >> course_name;
    }
};

class Grade {
public:
    int mark;
    char the_grade;

    void inputMarksAndGrade() {
        cout << "Enter marks: ";
        cin >> mark;

        if (mark > 69) {
            the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    string registration_number;
    string name;
    int age;
    Course course;
    Grade grade;

    void inputStudentDetails() {
        cout << "Enter registration number: ";
        cin >> registration_number;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        course.inputCourseDetails();
    }

    void editStudentDetails() {
        cout << "Enter new registration number: ";
        cin >> registration_number;
        cout << "Enter new name: ";
        cin >> name;
        cout << "Enter new age: ";
        cin >> age;
        course.inputCourseDetails();
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        if (students.size() < 40) {
            Student newStudent;
            newStudent.inputStudentDetails();
            students.push_back(newStudent);
            cout << "Student added successfully.\n";
        } else {
            cout << "Maximum number of students reached.\n";
        }
    }

    void editStudent() {
        string regNumber;
        cout << "Enter registration number of the student to edit: ";
        cin >> regNumber;

        auto it = find_if(students.begin(), students.end(),
            [regNumber](const Student& student) { return student.registration_number == regNumber; });

        if (it != students.end()) {
            it->editStudentDetails();
            cout << "Student details updated successfully.\n";
        } else {
            cout << "Student with registration number " << regNumber << " not found.\n";
        }
    }

    void addMarks() {
        string regNumber;
        cout << "Enter registration number of the student to add marks: ";
        cin >> regNumber;

        auto it = find_if(students.begin(), students.end(),
            [regNumber](const Student& student) { return student.registration_number == regNumber; });

        if (it != students.end()) {
            it->grade.inputMarksAndGrade();
            cout << "Marks and grade added successfully.\n";
        } else {
            cout << "Student with registration number " << regNumber << " not found.\n";
        }
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Add a student\n";
            cout << "2. Edit a student's details\n";
            cout << "3. Add marks and calculate grades\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    editStudent();
                    break;
                case 3:
                    addMarks();
                    break;
                case 4:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    StudentManagementSystem system;
    system.displayMenu();

    return 0;
}
