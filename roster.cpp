#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>

/* Parses each set of data identified in the “studentData Table.” */
void Roster::parse(string studentData) {
    int rhs = studentData.find(',');
    string studentID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string email = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string studentMajor = studentData.substr(lhs, rhs - lhs);
    DegreeProgram degreeProgram = undeclared;

    for (int i = 0; i < size(degreeProgramNames); i++) {
        if (studentMajor == degreeProgramNames[i]) {
            if (i == 0) { degreeProgram = undeclared; }
            if (i == 1) { degreeProgram = SECURITY; }
            if (i == 2) { degreeProgram = NETWORK; }
            if (i == 3) { degreeProgram = SOFTWARE; }
        }
    }
    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

/* Adds each student object to classRosterArray. */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

/* Removes students from the roster by student ID. */
void Roster::remove(string studentID) {
    bool findStudentID = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            findStudentID = true;
            if (i < sizeRoster - 1) {
                Student* tempRow = classRosterArray[i];
                classRosterArray[i] = classRosterArray[sizeRoster - 1];
                classRosterArray[sizeRoster - 1] = tempRow;
            }
            Roster::lastIndex--;
        }
    }
    if (findStudentID) {
        Roster::sortByID();
        std::cout << "Student ID " << studentID << " has been removed from the roster." << std::endl;
        std::cout << std::endl;
    }
    else {
        std::cout << "Error...Student ID " << studentID << " was not found on the roster." << std::endl;
        std::cout << std::endl;
    }
}

/* Prints a complete tab-separated list of student data. */
void Roster::printAll() {
    std::cout << "Printing all student records from the class roster..." << std::endl;
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
    std::cout << std::endl << std::endl;
}

/* Prints a student’s average number of days in the three courses. */
void Roster::printAverageDaysInCourse(string studentID) {
    int averageDaysPerCourse = 0;
    int totalDaysPerCourse = 0;
    int numberOfCourses = Student::dayPerCourseArraySize;
    for (int i = 0; i < sizeRoster; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            for (int j = 0; j < numberOfCourses; j++) {
                totalDaysPerCourse += classRosterArray[i]->getDaysPerCourse()[j];
            }
        }
    }
    averageDaysPerCourse = totalDaysPerCourse / numberOfCourses;
    std::cout << "StudentID: " << studentID << "\tAverage: " << averageDaysPerCourse << " days" << std::endl;
}

/* Verifies student email addresses and displays all invalid email addresses to the user. */
void Roster::printInvalidEmails() {
    std::cout << "Printing all invalid emails from the class roster..." << std::endl;
    bool invalidEmails = false;
    for (int i = 0; i < sizeRoster; i++) {
        string emailAddress = (classRosterArray[i]->getEmail());
        if (emailAddress.find("@") == string::npos || emailAddress.find(" ") != string::npos || emailAddress.find(".") == string::npos) {
            invalidEmails = true;
            std::cout << "StudentID: " << classRosterArray[i]->getStudentID() << "\tInvalid Email: " << emailAddress << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
}

/* Prints out student information for a degree program specified by an enumerated type. */
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::cout << "Printing all records of students enrolled in ";
    std::cout << programNames(degreeProgram) << "..." << std::endl;
    for (int i = 0; i < sizeRoster; i++) {
        if (Roster::classRosterArray[i]->getStudentMajor() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    std::cout << std::endl << std::endl;
}

/*Sorts classRosterArray by Student ID ascending.*/
void Roster::sortByID() {
    for (int i = 0; i < lastIndex; i++) {
        if (Roster::classRosterArray[i]->getStudentID() > Roster::classRosterArray[i + 1]->getStudentID()) {
            Student* tempRow = classRosterArray[i];
            classRosterArray[i] = classRosterArray[i + 1];
            classRosterArray[i + 1] = tempRow;
        }
    }
}

/* Destructor */
Roster::~Roster() {}