/*
 * student.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#include "student.h"
#include <iostream>



Student::Student() {
	this->studentID = "";
	this->firstName =  "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->courseTimes = {0, 0, 0};
};

Student::Student(
		std::string studentID = "",
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
}

std::string Student::GetID() {
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

std::string Student::GetCourseTimesString() {
	std::string courseString = "";

	courseString.append("{");
	courseString.append(std::to_string(courseTimes[0]));
	courseString.append(", ");
	courseString.append(std::to_string(courseTimes[1]));
	courseString.append(", ");
	courseString.append(std::to_string(courseTimes[2]));
	courseString.append("}");


	return courseString;
}

int Student::getAverageCourseTime() {
	int sum = 0;
	int numberOfCourses = 3;

	for(int i = 0; i < numberOfCourses; ++i) {
		sum += courseTimes[i];
	}

	return (sum / numberOfCourses);
}

void Student::Print() {
	std::array<int, 3> courses = GetCourseTimes();

	std::cout << "Student ID: " << GetID() << "\t"
			  << "First Name: " << GetFName() << "\t"
			  << "Last Name: " << GetLName() << "\t"
			  << "Age: " << GetAge() << "\t"
			  << "Days In Course: " << "{" << courses[0] << ", "
			  << courses[1] << ", " << courses[2] << "}\t"
			  << std::endl;
}

void Student::SetID(std::string ID) {
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

