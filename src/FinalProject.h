/*
 * FinalProject.h
 *
 *  Created on: Apr 16, 2018
 *      Author: jake
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <limits>
#include "LinkedList.h"
#include "Employeemanagement.h"
#include "InputOutput.h"
#ifndef FINALPROJECT_H_
#define FINALPROJECT_H_
using namespace std;





void ExecuteProgram(LinkedList *list, LinkedList *tList){
	string filename = "";
	input_output io;
	int mainInput;
	while(true){
		cout << "\nWhat would you like to do?\n"
				"1: OPEN employee database\n"
				"2: NEW employee database\n"
				"3: SAVE employee database\n"
				"10: Exit program\n"
				"Enter the number associated with the command: ";
		cin >> mainInput;
		switch(mainInput){
		case 1:
			list->resetList();
			tList->resetList();
			io.resetInputOutput();
			io.read_file();
			io.parse_string(list, tList);
			//OPEN database
			break;
		case 2:
			cout << "\nCreating new database!\n" << endl;
			list->resetList();
			tList->resetList();
			//NEW database
			break;
		case 3:
			filename = "";
			while(filename == ""){
				cin.clear();
				cin.ignore();
				cout << "\nEnter the filename of the database to save: \n";
				getline(cin,filename);
			}
			io.resetInputOutput();
			io.setFileNameOut(filename);
			io.saveDatabase(list,tList);
			//SAVE database
			break;
		case 4:
			//Nothing
			break;
		case 10:
			//Exit
			return;
			break;
		}
		if(mainInput == 1 || mainInput == 2){
			EmployeeManagement* eM = new EmployeeManagement();
			int input;
			int exit = 1;
			while(true){
				cout << "\nWhat would you like to do?\n"
						"1: Add Employee\n"
						"2: Edit Employee\n"
						"3: Terminate Employee\n"
						"4: Show List of Employee(s)\n"
						"5: New Year for Employee(s)\n"
						"10: Exit to main menu\n"
						"Enter the number associated with the command: ";
				cin.clear();
				cin >> input;




				switch(input){
				case 1:
					eM->AddEmployee(list);
					break;
				case 2:
					eM->EditEmployee(list);
					break;
				case 3:
					eM->RemoveEmployee(list,tList);
					//cout << "Removed Employee" << endl;
					break;
				case 4:
					eM->ListEmployees(list, tList);
					break;
				case 5:
					eM->NewYear(list);
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				case 10:
					exit = 0;
					break;
				default:
					break;
				}
				if(exit == 0){
					break;
				}
			}
		}




	}

}

#endif /* FINALPROJECT_H_ */
