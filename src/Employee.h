/*
 * Employee.h
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <limits>
#include <random>
using namespace std;
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee{
private:
	string name;
	int age;
	double salary;
	int yearsWorked;
	const int iDNumber;
	int department; //has to convert to string
	string jobTitle;
	string location;
	int rating;

public:
	Employee *nextName;
	Employee *nextAge;
	Employee *nextSalary;
	Employee *nextYearsWorked;
	Employee *nextIDNumber;
	Employee *nextDepartment;
	Employee *nextJobTitle;
	Employee *nextLocation;
	Employee *nextRating;
	Employee *previousName;
	Employee *previousAge;
	Employee *previousSalary;
	Employee *previousYearsWorked;
	Employee *previousIDNumber;
	Employee *previousDepartment;
	Employee *previousJobTitle;
	Employee *previousLocation;
	Employee *previousRating;
	Employee();
	Employee(string newName, int newAge, double newSalary,
			int newYearsWorked, int newDepartment, string title,
			string loc, int iD,int newRating);
	string getName();
	int getAge();
	double getSalary();
	int getYearsWorked();
	int getIDNumber();
	int getDepartment();
	string getJobTitle();
	string getLocation();
	int getRating();

	void setName(string name);
	void setAge(int age);
	void setSalary(double salary);
	void setYearsWorked(int yearsWorked);
	void setJobTitle(string jobTitle);
	void setLocation(string location);
	void setRating(int rating);
	void newYear();
};

class TerminatedEmployee{
private:
	string name;
	const int iDNumber;

public:
	TerminatedEmployee *nextName;
	TerminatedEmployee *nextIDNumber;
	TerminatedEmployee *previousName;
	TerminatedEmployee *previousIDNumber;
	TerminatedEmployee();
	TerminatedEmployee(string newName,int iD);
	string getName();
	int getIDNumber();
};





#endif /* EMPLOYEE_H_ */
