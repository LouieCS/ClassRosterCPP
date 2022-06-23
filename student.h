#ifndef _STUDENT_H_
#define _STUDENT_H_
#pragma once
#include "degree.h"
#include <string>

using std::string;

class Student {
public:
	/* for dayPerCourse array, which is the number of days it takes students to complete each of the three courses */
	static const int dayPerCourseArraySize = 3;

	/* constructors */
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysPerCourse[], DegreeProgram studentMajor);

	/* mutator (i.e., setter) for each instance variable */
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysPerCourse(int daysPerCourse[]);
	void setDegreeProgram(DegreeProgram studentMajor);

	/* accessor (i.e., getter) for each instance variable */
	const string getStudentID();
	const string getFirstName();
	const string getLastName();
	const string getEmail();
	const int getAge();
	int* getDaysPerCourse();
	DegreeProgram getStudentMajor();
	const string getStudentMajorString();

	/* print() to print specific student data */
	void print();

	/* destructor */
	~Student();

private:
	/* student variables */
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysPerCourse[dayPerCourseArraySize];
	DegreeProgram studentMajor;
};

#endif