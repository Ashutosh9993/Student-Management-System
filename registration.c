#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for student data
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_HOSTEL_NAME_LENGTH 20
#define MAX_COURSE_LENGTH 10
#define MAX_ROOM_NUMBER_LENGTH 10

// Structure to hold student record data
typedef struct {
    int studentId;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char hostelName[MAX_HOSTEL_NAME_LENGTH];
    char course[MAX_COURSE_LENGTH];
    char roomNumber[MAX_ROOM_NUMBER_LENGTH];
    // Add other fields as needed (e.g., date of birth, year of study)
} StudentRecord;

// Function to generate random student records
void generateStudentRecords(StudentRecord students[], int numStudents) {
    char firstNames[][MAX_NAME_LENGTH] = {"John", "Alice", "Michael", "Emily", "David", /* Add more names */};
    char lastNames[][MAX_NAME_LENGTH] = {"Smith", "Johnson", "Williams", "Jones", "Brown", /* Add more names */};
    char hostelNames[][MAX_HOSTEL_NAME_LENGTH] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", /* Add more names */};
    char courses[][MAX_COURSE_LENGTH] = {"BTech", "MTech", "MS", "PhD", "MBA"};
    char roomNumbers[][MAX_ROOM_NUMBER_LENGTH] = {"101", "102", "103", "201", "202", /* Add more room numbers */};

    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < numStudents; i++) {
        // Generate random indices for selecting names, hostel, and course
        int firstNameIndex = rand() % (sizeof(firstNames) / sizeof(firstNames[0]));
        int lastNameIndex = rand() % (sizeof(lastNames) / sizeof(lastNames[0]));
        int hostelIndex = rand() % (sizeof(hostelNames) / sizeof(hostelNames[0]));
        int courseIndex = rand() % (sizeof(courses) / sizeof(courses[0]));
        int roomNumberIndex = rand() % (sizeof(roomNumbers) / sizeof(roomNumbers[0]));

        // Generate remaining details using random function or user input
        int studentId = i + 1; // Assuming student IDs start from 1

        // Create the student record and add it to the array
        StudentRecord student;
        student.studentId = studentId;
        strcpy(student.firstName, firstNames[firstNameIndex]);
        strcpy(student.lastName, lastNames[lastNameIndex]);
        strcpy(student.hostelName, hostelNames[hostelIndex]);
        strcpy(student.course, courses[courseIndex]);
        strcpy(student.roomNumber, roomNumbers[roomNumberIndex]);

        students[i] = student;
    }
}

// Function to register student records in the database
void registerStudents(StudentRecord students[], int numStudents) {
    FILE* databaseFile = fopen("student_database.txt", "w");
    if (databaseFile == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        StudentRecord student = students[i];
        fprintf(databaseFile, "%d;%s;%s;%s;%s;%s\n", student.studentId, student.firstName, student.lastName,
                student.hostelName, student.course, student.roomNumber);
    }

    fclose(databaseFile);
}

int main() {
    int numStudents = 100; // Number of students to generate

    StudentRecord students[MAX_STUDENTS];
    generateStudentRecords(students, numStudents);
    registerStudents(students, numStudents);

    printf("%d students registered successfully.\n", numStudents);

    return 0;
}
