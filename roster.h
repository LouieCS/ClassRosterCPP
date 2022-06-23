#ifndef _ROSTER_H_
#define _ROSTER_H_
#pragma once
#include "degree.h"
#include "student.h"
#include <string>

using std::string;

class Roster {
public:
	int lastIndex = -1; // Index for classRosterArray.
	static const int sizeRoster = 5; // This is the number of students in the roster/studentData table.
	Student* classRosterArray[sizeRoster] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // This holds the data provided in the “studentData Table.”
	
	void parse(string studentData); // Parses each set of data identified in the “studentData Table.”
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); // Sets the instance variables from part D1 and updates the roster.
	void remove(string studentID); // Removes students from the roster by student ID.
	void printAll(); // Prints a complete tab-separated list of student data.
	void printAverageDaysInCourse(string studentID); // Prints a student’s average number of days in the three courses.
	void printInvalidEmails(); // Verifies student email addresses and displays all invalid email addresses to the user.
	void printByDegreeProgram(DegreeProgram degreeProgram); // Prints out student information for a degree program specified by an enumerated type.
	void sortByID(); // Sorts classRosterArray by Student ID.

	~Roster(); // Destructor.
};

#endif