/*
 * EmployeeManagement.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include "EmployeeManagement.h"
void EmployeeManagement::AddEmployee(LinkedList *list){
	string name;
	int age;
	double salary;
	int yearsWorked;
	int iDNumber;
	int department;
	string jobTitle;
	string location;
	int rating;
	cin.clear();

	cout << "\nAdding new employee!" << endl << endl;
	cout << "Enter Name (John Smith): \n";
	cin.ignore();
	getline(cin,name);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter Age: ";
	cin >> age;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter Salary: ";
	cin >> salary;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter years worked: ";
	cin >> yearsWorked;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	employeecounter++;
	iDNumber=employeecounter;

	cout << "\nList of Departments \n1: Accounting\n2: Customer Service\n3: Distribution\n4: Human Resources\n5: Information Technology\n6: Legal\n7: Management\n8: Marketing\n9: Research and Development\n10: Sales\n\nEnter a department number: ";
	cin >> department;
	cin.clear();
	cin.ignore();
	cout << "Enter a job title: \n";
	getline(cin,jobTitle);
	cin.clear();
	cin.ignore();
	cout << "Enter a Location: \n";
	getline(cin,location);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter employee rating(0-100): ";
	cin >> rating;
	cin.clear();
	Employee *emp = new Employee(name, age, salary,yearsWorked, department,jobTitle,location,iDNumber,rating);
	list->newEmployee(emp);



}
void EmployeeManagement::EditEmployee(LinkedList *list){
	list->editEmployee();
}
void EmployeeManagement::ListEmployees(LinkedList *list, LinkedList *tList){

	int input = 0;
	while(input < 1 || input > 10){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nWhat would you like to list?\n1: Name\n2: Age\n3: Salary\n4: Years Worked\n5: ID Number\n6: Department\n7: Job Title\n8: Location\n9: Rating\n10: Terminated Employee Name\nEnter the number associated with the list: ";
		cin >> input;
	}
	if(input == 10){
		tList->printList(input);
	}
	else{
		list->printList(input);
	}

}
void EmployeeManagement::RemoveEmployee(LinkedList *list,LinkedList *tList){
	string name = "";
	while(name == ""){
		cin.clear(); cin.ignore();

		cout << "Enter the name of the employee to be terminated: \n";
		getline(cin,name);
	}
	list->removeEmployee(name,tList);
	//cout << "Finished List->RemoveEmployee" << endl;
}
void EmployeeManagement::NewYear(LinkedList *list){
	list->newYear();
}


