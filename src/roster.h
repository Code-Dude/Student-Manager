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
	std::array<std::array<std::string, 9>, 5> ParseStudents(const std::string studentsAsStrings[], const int arraySize);
	void add(
				std::string studentID, std::string firstName, std::string lastName,
				std::string email, int age, int daysInCourse1, int daysInCourse2,
				int daysInCourse3, Degree degreeProgram
			);
	int GetCurrentNumStudents();
	void UpdateCurrentNumStudents(bool increment);

private:
	std::array<Student*, 5> classRosterArray;
	int currentNumberOfStudents = 0;
};

#endif /* SRC_ROSTER_H_ */
