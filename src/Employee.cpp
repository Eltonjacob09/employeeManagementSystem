/*
 * Employee.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include "Employee.h"

Employee::Employee(string newName, int newAge, double newSalary,
		int newYearsWorked, int newDepartment, string title,
		string loc, int iD,int newRating):iDNumber(iD){
	while(newName == ""){
		cin.clear();
		cin.ignore();
		cout << "\nEnter Name (John Smith): \n"; getline(cin,newName);
	}
	while(newAge < 18 || newAge > 70){
		cout << "Enter Age: "; cin >> newAge;
	}
	while(newSalary < 0 || newSalary > 1000000){//base maximum on year
		cout << "Enter Salary: "; cin >> newSalary;
	}
	while(newYearsWorked < 0 || newYearsWorked > 52){
		cout << "Enter years worked: "; cin >> newYearsWorked;
	}
	while(newDepartment < 1 || newDepartment > 10){
		cout << "List of Departments \n1: Accounting\n2: Customer Service\n3: Distribution\n4: Human Resources\n5: Information Technology\n6: Legal\n7: Management\n8: Marketing\n9: Research and Development\n10: Sales\n\nEnter a department number: "; cin >> newDepartment;
	}
	while(title == ""){
		cin.clear();
		cin.ignore();
		cout << "\nEnter a job title: \n"; getline(cin,title);
	}
	while(loc == ""){
		cin.clear();
		cin.ignore();
		cout << "\nEnter a Location: \n"; getline(cin,loc);
	}
	while(iD > 99999999 || iD < 1){
		cout << "Enter ID number(8 digits):"; cin >> iD;
	}
	while(newRating < 0 || newRating > 100){
		cout << "Enter employee rating(0-100): "; cin >> newRating;
	}
	this->name        =      newName;
	this->age         =      newAge;
	this->salary      =      newSalary;
	this->yearsWorked =      newYearsWorked;
	this->department  =      newDepartment;
	this->jobTitle    =      title;
	this->location    =      loc;
	this->rating = newRating;
	this->nextName = NULL;
	this->nextAge = NULL;
	this->nextSalary = NULL;
	this->nextYearsWorked = NULL;
	this->nextIDNumber = NULL;
	this->nextDepartment = NULL;
	this->nextJobTitle = NULL;
	this->nextLocation = NULL;
	this->nextRating = NULL;
	this->previousName = NULL;
	this->previousAge = NULL;
	this->previousSalary = NULL;
	this->previousYearsWorked = NULL;
	this->previousIDNumber = NULL;
	this->previousDepartment = NULL;
	this->previousJobTitle = NULL;
	this->previousLocation = NULL;
	this->previousRating = NULL;

}

string   Employee::getName(){
	return this->name;
}
int      Employee::getAge(){
	return this->age;
}
double   Employee::getSalary(){
	return this->salary;
}
int      Employee::getYearsWorked(){
	return this->yearsWorked;
}
int      Employee::getIDNumber(){
	return this->iDNumber;
}
int      Employee::getDepartment(){
	return this->department;
}
string   Employee::getJobTitle(){
	return this->jobTitle;
}
string   Employee::getLocation(){
	return this->location;
}
int      Employee::getRating(){
	return this->rating;
}
void Employee::setName(string name){
	this->name = name;
}
void Employee::setAge(int age){
	this->age = age;
}
void Employee::setSalary(double salary){
	this->salary = salary;
}
void Employee::setYearsWorked(int yearsWorked){
	this->yearsWorked = yearsWorked;
}
void Employee::setJobTitle(string jobTitle){
	this->jobTitle = jobTitle;
}
void Employee::setLocation(string location){
	this->location = location;
}
void Employee::setRating(int rating){
	this->rating = rating;
}
void	 Employee::newYear(){
	this->age ++;
	this->yearsWorked ++;
	this->salary = salary+(salary/25)*((double)rating/100);
	int tempRating = rand()%(21)+rating - 10;
	if(tempRating > 100){
		this->rating = 100;
	}
	else if(tempRating < 1){
		this->rating = 1;
	}
	else{this->rating = tempRating;}

}
TerminatedEmployee::TerminatedEmployee(string newName,int iD):iDNumber(iD){
	while(newName == ""){
		cin.clear();
		cin.ignore();
		cout << "\nEnter Name (John Smith): \n"; getline(cin,newName);
	}
	while(iD > 99999999 || iD < 1){
		cout << "Enter ID number(8 digits):"; cin >> iD;
	}
	this->name        =      newName;
	this->nextName = NULL;
	this->nextIDNumber = NULL;
	this->previousName = NULL;
	this->previousIDNumber = NULL;

}
string   TerminatedEmployee::getName(){
	return this->name;
}
int      TerminatedEmployee::getIDNumber(){
	return this->iDNumber;
}

