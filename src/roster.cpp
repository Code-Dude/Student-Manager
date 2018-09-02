/*
 * roster.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */


#include <iostream>
#include <string>
#include <iomanip>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

Roster::Roster() {
}

Roster::~Roster() {
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
			this->classRosterArray.push_back(newSecurityStudent);
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
		this->classRosterArray.push_back(newNetworkStudent);
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
		this->classRosterArray.push_back(newSoftwareStudent);
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
  else {
    return SOFTWARE;
  }
}

std::string Roster::degreeToString(Degree degree) {
	if(degree == Degree::SECURITY) {
		return "SECURITY";
	}
	else if(degree == Degree::NETWORK) {
		return "NETWORK";
	}
	else {
		return "SOFTWARE";
	}
}

void Roster::PrintAll() {
	for(unsigned int i = 0; i < this->classRosterArray.size(); ++i) {
		classRosterArray.at(i)->Print();
	}
}

int Roster::GetCurrentNumStudents() {
	return classRosterArray.size();
}

void Roster::remove(std::string studentID) {
	bool studentDeleted = false;


	for(int i = 0; i < GetCurrentNumStudents(); ++i) {
		if(classRosterArray.at(i)->GetID() == studentID) {
			classRosterArray.erase(classRosterArray.begin() + i);
			studentDeleted = true;
		}
	}

	if(!studentDeleted) {
		std::cout << "No student with ID: " << studentID << " was found..." << std::endl;
	}
}

void Roster::printAverageDaysInCourse(std::string studentID) {
	bool foundStudent = false;

	for(int i = 0; i < GetCurrentNumStudents(); ++i) {
		if(classRosterArray.at(i)->GetID() == studentID) {
			std::cout << "Student ID: " << classRosterArray.at(i)->GetID();
			std::cout << " Number of days in classes- "
					  << classRosterArray.at(i)->GetCourseTimesString()
					  << " Average Number of days in classes- "
					  << classRosterArray.at(i)->getAverageCourseTime()
					  << std::endl;
			foundStudent = true;
			break;
		}
	}

	if(!foundStudent) {
		std::cout << "No student with ID: " << studentID << " was found..." << std::endl;
	}
}

bool Roster::validateEmail(std::string email) {
	int numAtsigns = 0;
	int numPeriods = 0;

	for(unsigned int i = 0; i < email.length(); ++i) {
		if(email.at(i) == '.') {
			++numPeriods;
		}
		else if(email.at(i) == '@') {
			++numAtsigns;
		}
		else if(email.at(i) == ' ') {
			return false;
		}
	}

	if(numPeriods == 1 && numAtsigns == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Roster::printInvalidEmails() {
	for(int i = 0; i < GetCurrentNumStudents(); ++i) {
		std::string email = classRosterArray.at(i)->GetEmail();
		if(!validateEmail(email)) {
			std::cout << "Invalid Email Address: " << email
					  << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(int degreeProgram) {
	std::cout << degreeToString(static_cast<Degree>(degreeProgram))
			  << " Students" << std::endl;
	for(int i = 0; i < GetCurrentNumStudents(); ++i) {
		if(classRosterArray.at(i)->getDegreeProgram() == static_cast<Degree>(degreeProgram)) {
			classRosterArray.at(i)->Print();
		}
	}
}

int main() {
	const int STUDENT_DATA_SIZE = 5;
	std::string currentID = "";

	const std::string studentData[] =
	{
	 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,test,name,test@email.edu,23,8,30,45,SOFTWARE"
	};

	Roster* classRoster;

	classRoster = new Roster;

	classRoster->ParseStudents(studentData, STUDENT_DATA_SIZE);
	classRoster->PrintAll();
	classRoster->printInvalidEmails();

	for(int i = 0; i < classRoster->GetCurrentNumStudents(); ++i) {
		currentID = classRoster->classRosterArray.at(i)->GetID();

		classRoster->printAverageDaysInCourse(currentID);
	}

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");

	delete classRoster;

	return 0;
}

