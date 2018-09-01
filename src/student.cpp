/*
 * student.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#include "student.h"

Student::Student(
		int studentID = 0,
		std::string firstName = "",
		std::string lastName = "",
		std::string emailAddress = "",
		int age = 0,
		int course1 = 0,
		int course2 = 0,
		int course3 = 0) {

	this->studentID = studentID;
	this->firstName =  firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->courseTimes = {course1, course2, course3};

}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

int Student::GetID() {
	return this->studentID;
}

std::string Student::GetFName() {
	return firstName;
}

std::string Student::GetLName() {
	return lastName;
}

std::string Student::GetEmail() {
	return emailAddress;
}

int Student::GetAge() {
	return age;
}

std::array<int, 3> Student::GetCourseTimes() {
	return courseTimes;
}

void Student::SetID(int ID) {
	studentID = ID;

	return;
}

void Student::SetFName(std::string fName) {
	firstName = fName;

	return;
}

void Student::SetLName(std::string lName) {
	lastName = lName;

	return;
}

void Student::SetEmail(std::string emailAddr) {
	emailAddress = emailAddr;

	return;
}

void Student::SetAge(int newAge) {
	age = newAge;

	return;
}

void Student::SetCourseTimes(int course1, int course2, int course3) {
	courseTimes.at(0) = course1;
	courseTimes.at(1) = course2;
	courseTimes.at(2) = course3;

	return;
}

