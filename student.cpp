#include "student.h"
#include <iostream>

using std::string;

/* Default parameters. */
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < dayPerCourseArraySize; i++) {
		this->daysPerCourse[i] = 0;
	}
	this->studentMajor = DegreeProgram::undeclared;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysPerCourse[], DegreeProgram studentMajor) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < dayPerCourseArraySize; i++) {
		this->daysPerCourse[i] = daysPerCourse[i];
	}
	this->studentMajor = studentMajor;
}

/* Mutators (i.e., Setters) */
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysPerCourse(int daysPerCourse[]){
	for (int i = 0; i < dayPerCourseArraySize; i++)
		this->daysPerCourse[i] = daysPerCourse[i];
}
void Student::setDegreeProgram(DegreeProgram studentMajor) {
	this->studentMajor = studentMajor;
}

/* Accessors (i.e., Getters) */
const string  Student::getStudentID() {
	return this->studentID;
}
const string  Student::getFirstName() {
	return this->firstName;
}
const string  Student::getLastName() {
	return this->lastName;
}
const string  Student::getEmail() {
	return this->email;
}
const int  Student::getAge() {
	return this->age;
}
int* Student::getDaysPerCourse() {
	return this->daysPerCourse;
}
DegreeProgram Student::getStudentMajor() {
	return this->studentMajor;
}

/* Returns string instead of enum int for DegreeProgram */
const string Student::getStudentMajorString() {
	int degreeNameIndex = getStudentMajor();
	return programNames(degreeNameIndex);
}
const string programNames(int degreeNameIndex){
	return degreeProgramNames[degreeNameIndex];
}

/* Prints student data */
void Student::print() {
	    std::cout << "StudentID: " << getStudentID();
		std::cout << "\tFirst Name: " << getFirstName();
		std::cout << "\tLast Name: " << getLastName();
		std::cout << "\tEmail: " << getEmail();
		std::cout << "\tAge: " << getAge();
        std::cout << "\tdaysInCourse: " << *getDaysPerCourse() << "," << *(getDaysPerCourse() + 1) << "," << *(getDaysPerCourse() + 2);
        std::cout << "\tDegree Program: " << getStudentMajorString(); // Returns string for DegreeProgram instead of int
		//std::cout << "\tDegree Program: " << getStudentMajor(); // Returns enum int for DegreeProgram
		std::cout << std::endl;
}

/* Destructor */
Student::~Student() {};