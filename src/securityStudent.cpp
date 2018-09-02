/*
 * securityStudent.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#include "securityStudent.h"

SecurityStudent::SecurityStudent() {
	degreeProgram = Degree::SECURITY;
}

SecurityStudent::SecurityStudent
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

Degree SecurityStudent::getDegreeProgram() {
	return degreeProgram;
}

void SecurityStudent::SetDegreeProgram(Degree newProgram) {
	degreeProgram = newProgram;

	return;
}

void SecurityStudent::Print() {
	std::cout << "Student ID: " << std::setw(2) << std::left << GetID();
	std::cout << "\tFirst Name: " << std::setw(8) << std::left << GetFName();
	std::cout << "\tLast Name: " << std::setw(8) << std::left << GetLName();
	std::cout << "\tAge: " << std::setw(8) << std::left << GetAge();
	std::cout << "\tDays In Courses: " << std::setw(10) << std::left << GetCourseTimesString();
	std::cout << "\tDegree Program: " << "SECURITY" << std::endl;
}
