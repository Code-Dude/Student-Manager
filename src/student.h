/*
 * student.h
 *
 *  Created on: Aug 31, 2018
 *      Author: Scott
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <string>
#include <array>
#include "degree.h"

class Student {
public:
	// Constructors
	Student();
	Student(
			std::string studentID,
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
	std::string GetID();
	std::string GetFName();
	std::string GetLName();
	std::string GetEmail();
	int GetAge();
	std::array<int, 3> GetCourseTimes();
	virtual Degree getDegreeProgram() = 0;

	//Print
	virtual void Print();

	// Setters
	void SetID(std::string ID);
	void SetFName(std::string firstName);
	void SetLName(std::string lastName);
	void SetEmail(std::string email);
	void SetAge(int age);
	void SetCourseTimes(int course1, int course2, int course3);
	virtual void SetDegreeProgram(Degree degree) = 0;


private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	std::array<int, 3> courseTimes;
};

#endif /* SRC_STUDENT_H_ */
