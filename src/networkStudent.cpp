/*
 * networkStudent.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#include "networkStudent.h"

NetworkStudent::NetworkStudent
		(
			std::string studentID,
			std::string firstName,
			std::string lastName,
			std::string emailAddress,
			int age,
			int course1,
			int course2,
			int course3,
			Degree degreeProgram
		) :
		Student
		(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			course1,
			course2,
			course3
		)
{
	this->degreeProgram = degreeProgram;

}

Degree NetworkStudent::getDegreeProgram() {
	return degreeProgram;
}

void NetworkStudent::SetDegreeProgram(Degree newProgram) {
	degreeProgram = newProgram;

	return;
}

