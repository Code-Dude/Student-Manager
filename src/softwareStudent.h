/*
 * softwareStudent.h
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#ifndef SRC_SOFTWARESTUDENT_H_
#define SRC_SOFTWARESTUDENT_H_

#include "student.h"

class SoftwareStudent : public Student {
public:
	SoftwareStudent(
		std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int course1,
		int course2,
		int course3,
		Degree degreeProgram
	);

Degree getDegreeProgram();
void SetDegreeProgram(Degree newDegree);

private:
Degree degreeProgram;
};

#endif /* SRC_SOFTWARESTUDENT_H_ */
