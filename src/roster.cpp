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

Roster::Roster() {
	for(int i = 0; i < 5; ++i) {
		this->classRosterArray.at(i) = nullptr;
	}

	this->currentNumberOfStudents = 0;
}

 void Roster::convertStringsToStudents(std::string studentValues[], int arraySize) {
	std::string newStudentID = "";
	std::string newFirstName = "";
	std::string newLastName = "";
	std::string newEmail = "";
	int newAge = 0;
	int newCourse1 = 0;
	int newCourse2 = 0;
	int newCourse3 = 0;
	Degree newDegreeProgram;
	for(int i = 0; i < 9; ++i) {
		if(i == 0) {
			newStudentID = studentValues[i];
		}
		else if(i == 1) {
			newFirstName = studentValues[i];
		}
		else if(i == 2) {
			newLastName = studentValues[i];
		}
		else if(i == 3) {
			newEmail = studentValues[i];
		}
		else if(i == 4) {
			newAge = std::stoi(studentValues[i]);
		}
		else if(i == 5) {
			newCourse1 = std::stoi(studentValues[i]);
		}
		else if(i == 6) {
			newCourse2 = std::stoi(studentValues[i]);
		}
		else if(i == 7) {
			newCourse3 = std::stoi(studentValues[i]);
		}
		else if(i == 8) {
			newDegreeProgram = stringToDegree(studentValues[i]);
		}
		else {
			std::cout << "Couldn't add field: " << i << std::endl;
		}
	}

	add(newStudentID, newFirstName, newLastName, newEmail, newAge, newCourse1, newCourse2, newCourse3, newDegreeProgram);
}

void Roster::ParseStudents(const std::string studentsAsStrings[], const int arraySize) {
	int numberOfParams = 9;
	std::string tempSubstring = "";
	std::string studentParams[numberOfParams];
	int currentParameter = 0;
	unsigned int commaLocation = 0;

	for(int i = 0; i < arraySize; ++i) {
	    commaLocation = 0;
	    currentParameter = 0;

	    std::string currentArrayString = studentsAsStrings[i];
	    while(currentParameter < 9) {
	      commaLocation = currentArrayString.find_first_of(',');
	      tempSubstring = currentArrayString.substr(0, commaLocation);
	      studentParams[currentParameter] = tempSubstring;
	      currentArrayString.erase(0, commaLocation + 1);
	      ++currentParameter;
	    }

	    convertStringsToStudents(studentParams, numberOfParams);
	}
}

void Roster::add
		(
			std::string studentID, std::string firstName, std::string lastName,
			std::string email, int age, int daysInCourse1, int daysInCourse2,
			int daysInCourse3, Degree degreeProgram
		) {

	if(degreeProgram == Degree::SECURITY) {
		SecurityStudent* newSecurityStudent = nullptr;
		newSecurityStudent = new SecurityStudent
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
			this->classRosterArray[GetCurrentNumStudents()] = newSecurityStudent;
			UpdateCurrentNumStudents(true);
	}
	else if(degreeProgram == Degree::NETWORK) {
		NetworkStudent* newNetworkStudent = nullptr;
		newNetworkStudent = new NetworkStudent
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
		this->classRosterArray[GetCurrentNumStudents()] = newNetworkStudent;
		UpdateCurrentNumStudents(true);
	}
	else if(degreeProgram == Degree::SOFTWARE) {
		SoftwareStudent* newSoftwareStudent = nullptr;
		newSoftwareStudent = new SoftwareStudent
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
		this->classRosterArray[GetCurrentNumStudents()] = newSoftwareStudent;
		UpdateCurrentNumStudents(true);
	}
	else {
		std::cout << "Couldn't add student to Roster." << std::endl;
	}
}

Degree Roster::stringToDegree(std::string degreeString) {
  if(degreeString == "SECURITY") {
    return SECURITY;
  }
  else if(degreeString == "NETWORK") {
    return NETWORK;
  }
  else if(degreeString == "SOFTWARE") {
    return SOFTWARE;
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

void Roster::PrintAll() {
	for(int i = 0; i < GetCurrentNumStudents(); ++i) {
		this->classRosterArray.at(i)->Print();
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

	myRoster.ParseStudents(studentData, STUDENT_DATA_SIZE);

	myRoster.PrintAll();
	return 0;
}

