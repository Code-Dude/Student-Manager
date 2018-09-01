/*
 * roster.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#include "roster.h"
#include "degree.h"
#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include <array>

std::array<std::array<std::string, 9>, 5> Roster::ParseStudents(const std::string studentsAsStrings[], const int arraySize) {
	std::array<std::array<std::string, 9>, 5> parsedStudents;
	int currentArrayLocation = 0;
	unsigned int commaLocation = 0;

	for(int i = 0; i < arraySize; ++i) {
	    commaLocation = 0;
	    currentArrayLocation = 0;

	    std::string currentArrayString = studentsAsStrings[i];
	    while(commaLocation != std::string::npos) {
	      std::string tempSubstring = "";
	      commaLocation = currentArrayString.find_first_of(',');
	      tempSubstring = currentArrayString.substr(0, commaLocation);
	      parsedStudents[i][currentArrayLocation] = tempSubstring;
	      currentArrayString.erase(0, commaLocation + 1);
	      ++currentArrayLocation;
	    }
	}

	return parsedStudents;
}

void Roster::add
		(
			std::string studentID, std::string firstName, std::string lastName,
			std::string email, int age, int daysInCourse1, int daysInCourse2,
			int daysInCourse3, Degree degreeProgram
		) {

	if(degreeProgram == Degree::SECURITY) {
		SecurityStudent newSecurityStudent
					(
						studentID,
						firstName,
						lastName,
						email,
						age,
						daysInCourse1,
						daysInCourse2,
						daysInCourse3,
						degreeProgram
					);
			this->classRosterArray.at(GetCurrentNumStudents()) = &newSecurityStudent;
	}
	else if(degreeProgram == Degree::NETWORK) {
		NetworkStudent newNetworkStudent
				(
					studentID,
					firstName,
					lastName,
					email,
					age,
					daysInCourse1,
					daysInCourse2,
					daysInCourse3,
					degreeProgram
				);
		this->classRosterArray[GetCurrentNumStudents()] = &newNetworkStudent;
	}
	else if(degreeProgram == Degree::SOFTWARE) {
		SoftwareStudent newSoftwareStudent
				(
					studentID,
					firstName,
					lastName,
					email,
					age,
					daysInCourse1,
					daysInCourse2,
					daysInCourse3,
					degreeProgram
				);
		this->classRosterArray[GetCurrentNumStudents()] = &newSoftwareStudent;
	}
	else {
		std::cout << "Couldn't add student to Roster." << std::endl;
	}
}

int Roster::GetCurrentNumStudents() {
	return this->currentNumberOfStudents;
}

void Roster::UpdateCurrentNumStudents(bool increment) {
	if(increment) {
		this->currentNumberOfStudents += 1;
	}
	else {
		this->currentNumberOfStudents -= 1;
	}
}

int main() {
	const int STUDENT_DATA_SIZE = 5;

	const std::string studentData[] =
	{
	 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,test,name,test@email.edu,23,8,30,45,SOFTWARE"
	};

	Roster myRoster;

	std::array<std::array<std::string, 9>, 5> students = myRoster.ParseStudents(studentData, STUDENT_DATA_SIZE);
	for(int i = 0; i < STUDENT_DATA_SIZE; ++i) {
		for(int j = 0; j < 9; ++j) {
			std::cout << students[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}

