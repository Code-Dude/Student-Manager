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
#include "securityStudent.h"

using namespace std;

Roster::Roster() {
	// TODO Auto-generated constructor stub

}

Roster::~Roster() {
	// TODO Auto-generated destructor stub
}

int main() {
	const string studentData[] =
	{
	 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,test,name,test@email.edu,23,8,30,45,SOFTWARE"
	};

	SecurityStudent newStudent(
			"123456789",
			"test",
			"name",
			"test@email.edu",
			23,
			50,
			60,
			100,
			SOFTWARE
			);

	newStudent.Print();

	cout << "Hello, World!" << endl;

	return 0;
}

