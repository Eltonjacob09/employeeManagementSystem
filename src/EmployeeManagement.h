/*
 * EmployeeManagement.h
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <limits>
#include "LinkedList.h"
#ifndef EMPLOYEEMANAGEMENT_H_
#define EMPLOYEEMANAGEMENT_H_

class EmployeeManagement {
private:
	static int employeecounter;

public:
	EmployeeManagement(){
		int A = 0;
	}
	void AddEmployee(LinkedList *list);
	void RemoveEmployee(LinkedList *list,LinkedList *tList);
	void EditEmployee(LinkedList *List);
	void ListEmployees(LinkedList *List, LinkedList *tList);
	void NewYear(LinkedList *list);

};




#endif /* EMPLOYEEMANAGEMENT_H_ */
