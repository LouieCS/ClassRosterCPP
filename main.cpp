#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"

int main() {
	std::cout << "Programming language:  C++" << std::endl;
	std::cout << "Developed by:          Louie Sanchez" << std::endl;
	std::cout << "____________________________________" << std::endl;
	std::cout << std::endl;

	/* Modified “studentData Table” which includes personal information as the last item */
	const std::string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Louie,Sanchez,misterlouie@gmail.com,26,14,30,60,SOFTWARE"
	};

	/* Create a student object for each student in the data table and populate classRosterArray. */
	int sizeRoster = size(studentData);
	const int studentDataTable = sizeRoster;
	Roster classRoster;
	for (int i = 0; i < sizeRoster; ++i) {
		classRoster.parse(studentData[i]);
	};

	classRoster.printAll();

	classRoster.printInvalidEmails();

	/* Loops through classRosterArray for each student to calculate average days in three courses. */
	std::cout << "Printing average number of days in the three courses for every student..." << std::endl;
	for (int i = 0; i < sizeRoster; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	};
	std::cout << std::endl << std::endl;


	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");


	return 0;
}