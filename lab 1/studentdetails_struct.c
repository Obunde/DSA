#include <stdio.h>
#include <string.h>

// Define the Course structure
struct Course {
    char course_code[10];
    char course_name[50];
};

// Define the Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student structure
struct Student {
    char registration_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grade;
};

// Function to add a new student
void addStudent(struct Student students[], int* studentCount) {
    if (*studentCount < 40) {
        printf("Enter registration number: ");
        scanf("%s", students[*studentCount].registration_number);
        printf("Enter name: ");
        scanf("%s", students[*studentCount].name);
        printf("Enter age: ");
        scanf("%d", &students[*studentCount].age);
        printf("Enter course code: ");
        scanf("%s", students[*studentCount].course.course_code);
        printf("Enter course name: ");
        scanf("%s", students[*studentCount].course.course_name);

        (*studentCount)++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

// Function to edit a student's details
void editStudent(struct Student students[], int studentCount) {
    char regNumber[20];
    printf("Enter registration number of the student to edit: ");
    scanf("%s", regNumber);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].registration_number, regNumber) == 0) {
            printf("Enter new registration number: ");
            scanf("%s", students[i].registration_number);
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new course code: ");
            scanf("%s", students[i].course.course_code);
            printf("Enter new course name: ");
            scanf("%s", students[i].course.course_name);

            found = 1;
            printf("Student details updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with registration number %s not found.\n", regNumber);
    }
}

// Function to add marks and calculate grades
void addMarks(struct Student students[], int studentCount) {
    char regNumber[20];
    printf("Enter registration number of the student to add marks: ");
    scanf("%s", regNumber);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].registration_number, regNumber) == 0) {
            printf("Enter marks: ");
            scanf("%d", &students[i].grade.mark);

            // Calculate grade based on the grading system
            if (students[i].grade.mark > 69) {
                students[i].grade.the_grade = 'A';
            } else if (students[i].grade.mark > 59) {
                students[i].grade.the_grade = 'B';
            } else if (students[i].grade.mark > 49) {
                students[i].grade.the_grade = 'C';
            } else if (students[i].grade.mark > 39) {
                students[i].grade.the_grade = 'D';
            } else {
                students[i].grade.the_grade = 'E';
            }

            found = 1;
            printf("Marks and grade added successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with registration number %s not found.\n", regNumber);
    }
}

int main() {
    struct Student students[40];
    int studentCount = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add a student\n");
        printf("2. Edit a student's details\n");
        printf("3. Add marks and calculate grades\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarks(students, studentCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
