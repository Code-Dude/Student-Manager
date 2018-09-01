/*
 * networkStudent.h
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#ifndef SRC_NETWORKSTUDENT_H_
#define SRC_NETWORKSTUDENT_H_

#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent(
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

#endif /* SRC_NETWORKSTUDENT_H_ */
