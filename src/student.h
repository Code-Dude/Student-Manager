/*
 * student.h
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <string>
#include "degree.h"
#include <array>

class Student {
public:
	// Constructor
	Student(
			int studentID,
			std::string firstName,
			std::string lastName,
			std::string emailAddress,
			int age,
			int course1,
			int course2,
			int course3
		   );

	// Destructor
	virtual ~Student();

	// Getters
	int GetID();
	std::string GetFName();
	std::string GetLName();
	std::string GetEmail();
	int GetAge();
	std::array<int, 3> GetCourseTimes();
	virtual void Print() = 0;
	virtual Degree getDegreeProgram() = 0;

	// Setters
	void SetID(int ID);
	void SetFName(std::string firstName);
	void SetLName(std::string lastName);
	void SetEmail(std::string email);
	void SetAge(int age);
	void SetCourseTimes(int course1, int course2, int course3);
	virtual void SetDegreeProgram(Degree degree) = 0;


private:
	int studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	std::array<int, 3> courseTimes;
};

#endif /* SRC_STUDENT_H_ */
