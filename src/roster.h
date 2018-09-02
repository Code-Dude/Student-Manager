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

class Roster {
public:
	Roster();
	void ParseStudents(const std::string studentsAsStrings[], const int arraySize);
	void add(
				std::string studentID, std::string firstName, std::string lastName,
				std::string email, int age, int daysInCourse1, int daysInCourse2,
				int daysInCourse3, Degree degreeProgram
			);
	int GetCurrentNumStudents();
	void UpdateCurrentNumStudents(bool increment);
	void convertStringsToStudents(std::string studentValues[], int arraySize);
	Degree stringToDegree(std::string degreeString);
	void PrintAll();

private:
	std::array<Student*, 5> classRosterArray;
	int currentNumberOfStudents;
};

#endif /* SRC_ROSTER_H_ */
