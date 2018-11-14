/*
 * LinkedList.h
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <limits>
#include "Employee.h"
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {

private:


	Employee* headName;
	Employee* tailName;
	Employee* headAge;
	Employee* tailAge;
	Employee* headSalary;
	Employee* tailSalary;
	Employee* headYearW;
	Employee* tailYearW;
	Employee* headID;
	Employee* tailID;
	Employee* headDepartment;
	Employee* tailDepartment;
	Employee* headJobTitle;
	Employee* tailJobTitle;
	Employee* headLocation;
	Employee* tailLocation;
	Employee* headRating;
	Employee* tailRating;

	TerminatedEmployee* headNameT;
	TerminatedEmployee* tailNameT;
	TerminatedEmployee*	headIDNumberT;
	TerminatedEmployee*	tailIDNumberT;

public:
	LinkedList(){
		headName = NULL;
		tailName = NULL;
		headAge  = NULL;
		tailAge  = NULL;
		headSalary = NULL;
		tailSalary = NULL;
		headYearW  = NULL;
		tailYearW  = NULL;
		headID     = NULL;
		tailID     = NULL;
		headDepartment = NULL;
		tailDepartment = NULL;
		headJobTitle       = NULL;
		tailJobTitle       = NULL;
		headLocation        = NULL;
		tailLocation        = NULL;
		headRating     = NULL;
		tailRating     = NULL;

		headNameT         = NULL;
		tailNameT		  = NULL;
		headIDNumberT	  = NULL;
		tailIDNumberT	  = NULL;
	}
	void resetList();
	void newEmployee(Employee *temp);
	void newTerminatedEmployee(TerminatedEmployee *temp);
	void removeEmployee(string name,LinkedList *tList);//still need to decipher between same names
	void printList(int catagory);
	void newYear();
	void editEmployee(); // create
	Employee* getHeadName();
	TerminatedEmployee* getHeadNameT();
	int getTailID();
};



#endif /* LINKEDLIST_H_ */
