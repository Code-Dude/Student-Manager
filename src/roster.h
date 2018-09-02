/*
 * roster.h
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#ifndef SRC_ROSTER_H_
#define SRC_ROSTER_H_

#include "student.h"
#include <array>
#include <vector>

class Roster {
public:
	std::vector<Student*> classRosterArray;

	//Constructor
	Roster();

	//Destructor
	~Roster();

	//Member
	void ParseStudents(const std::string studentsAsStrings[], const int arraySize);
	void add(
				std::string studentID, std::string firstName, std::string lastName,
				std::string email, int age, int daysInCourse1, int daysInCourse2,
				int daysInCourse3, Degree degreeProgram
			);
	void remove(std::string studentID);
	int GetCurrentNumStudents();
	void convertStringsToStudents(std::string studentValues[], int arraySize);
	Degree stringToDegree(std::string degreeString);
	std::string degreeToString(Degree degree);
	void PrintAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	bool validateEmail(std::string email);
	void printByDegreeProgram(int degreeProgram);
};

#endif /* SRC_ROSTER_H_ */
