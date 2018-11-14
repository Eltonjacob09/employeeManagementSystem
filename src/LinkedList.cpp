/*
 * LinkedList.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include "LinkedList.h"
void LinkedList::resetList(){
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
void LinkedList::newEmployee (Employee *emp) {
	//STRING
#ifndef NAME
	if(headName == NULL){
		headName = emp;
		tailName = emp;
	}
	else{
		string empName = emp->getName();
		Employee *temp = headName;
		Employee *previousTemp = headName->previousName;
		while(true){
			string name = temp->getName();
			int length = 0;
			if(empName.length()>name.length()){
				length = name.length();
			}
			else{length = empName.length();}
			if(strncmp(empName.c_str(),name.c_str(),length) < 0){
				//cout << "<0name: " << name << "\nempName: " << empName << endl;
				if(previousTemp == NULL){
					emp->nextName = headName;
					emp->nextName->previousName = emp;
					headName = emp;
					break;
				}
				else{
					emp->nextName = temp;
					previousTemp->nextName = emp;
					emp->previousName = previousTemp; ////BACKWARDS
					temp->previousName = emp;
					break;
				}
			}
			else if(strncmp(name.c_str(),empName.c_str(),length) == 0){
				//cout << "0name: " << name << "\ntempName: " << empName << endl;
				if(temp->nextName == NULL){
					temp->nextName = emp;
					emp->previousName = temp; ////BACKWARDS
					tailName = emp;
					break;
				}
			}
			else{
				if(temp->nextName == NULL){
					//cout << "here for" << emp->getName() << endl;
					temp->nextName = emp;
					emp->previousName = temp; ////BACKWARDS
					tailName = emp;
					break;
				}
			}

			if(temp->nextName ==NULL){
				break;
			}
			else{
				previousTemp = temp;
				temp = temp->nextName;

			}
		}
	}
#endif
	//INT
#ifndef AGE
	//see if pointer to headAge is NULL/empty
	if(headAge == NULL){
		headAge = emp;
		tailAge = emp;
	}
	//there is a linked list already. Now find out where the pointer needs to go
	else{
		int empAge = emp->getAge();//this is our new employee age to sort
		Employee* nextTemp = headAge;//copy reference to go through LL chain
		Employee* previousTemp = NULL;//have reference to past pointer
		int tempAge = nextTemp->getAge();//copy age of nextTemp
		while(true){
			if(empAge < tempAge){
				if(previousTemp == NULL){//insert into beginning/headAge
					//cout << "in previous NULL" << endl;
					emp->nextAge = headAge;
					headAge = emp;
					break;
				}
				else{//insert in middle
					//cout << "in previous" << endl;
					emp->nextAge = previousTemp->nextAge;
					previousTemp->nextAge = emp;
					break;
				}
			}
			else if(nextTemp->nextAge == NULL){//insert at end if greater than everything
				nextTemp->nextAge = emp;
				tailAge = emp;
				break;
			}
			else{
				previousTemp = nextTemp;
				nextTemp = nextTemp->nextAge;
				tempAge = nextTemp->getAge();
			}
		}
	}
#endif
	//DOUBLE
#ifndef SALARY
	//see if pointer to headSalary is NULL/empty
	if(headSalary == NULL){
		headSalary = emp;
		tailSalary = emp;
	}
	//there is a linked list already. Now find out where the pointer needs to go
	else{
		double empSalary = emp->getSalary();//this is our new employee Salary to sort
		Employee* nextTemp = headSalary;//copy reference to go through LL chain
		Employee* previousTemp = NULL;//have reference to past pointer
		double tempSalary = nextTemp->getSalary();//copy Salary of nextTemp
		while(true){
			if(empSalary < tempSalary){
				if(previousTemp == NULL){//insert into beginning/headSalary
					emp->nextSalary = headSalary;
					headSalary = emp;
					break;
				}
				else{//insert in middle
					emp->nextSalary = previousTemp->nextSalary;
					previousTemp->nextSalary = emp;
					break;
				}
			}
			else if(nextTemp->nextSalary == NULL){//insert at end if greater than everything
				nextTemp->nextSalary = emp;
				tailSalary = emp;
				break;
			}
			else{
				previousTemp = nextTemp;
				nextTemp = nextTemp->nextSalary;
				tempSalary = nextTemp->getSalary();
			}
		}
	}
#endif
	//INT
#ifndef YEARSWORKED
	//see if pointer to headYearW is NULL/empty
	if(headYearW == NULL){
		headYearW = emp;
		tailYearW = emp;
	}
	//there is a linked list already. Now find out where the pointer needs to go
	else{
		int empYearsWorked = emp->getYearsWorked();//this is our new employee YearsWorked to sort
		Employee* nextTemp = headYearW;//copy reference to go through LL chain
		Employee* previousTemp = NULL;//have reference to past pointer
		int tempYearsWorked = nextTemp->getYearsWorked();//copy YearsWorked of nextTemp
		while(true){
			if(empYearsWorked < tempYearsWorked){
				if(previousTemp == NULL){//insert into beginning/headYearsWorked
					emp->nextYearsWorked = headYearW;
					headYearW = emp;
					break;
				}
				else{//insert in middle
					emp->nextYearsWorked = previousTemp->nextYearsWorked;
					previousTemp->nextYearsWorked = emp;
					break;
				}
			}
			else if(nextTemp->nextYearsWorked == NULL){//insert at end if greater than everything
				nextTemp->nextYearsWorked = emp;
				tailYearW = emp;
				break;
			}
			else{
				previousTemp = nextTemp;
				nextTemp = nextTemp->nextYearsWorked;
				tempYearsWorked = nextTemp->getYearsWorked();
			}
		}
	}
#endif
	//INT
#ifndef ID
	//see if pointer to headID is NULL/empty
	if(headID == NULL){
		headID = emp;
		tailID = emp;
	}
	//there is a linked list already. Now find out where the pointer needs to go
	else{
		int empIDNumber = emp->getIDNumber();//this is our new employee IDNumber to sort
		Employee* nextTemp = headID;//copy reference to go through LL chain
		Employee* previousTemp = NULL;//have reference to past pointer
		int tempIDNumber = nextTemp->getIDNumber();//copy IDNumber of nextTemp
		while(true){
			if(empIDNumber < tempIDNumber){
				if(previousTemp == NULL){//insert into beginning/headID
					emp->nextIDNumber = headID;
					headID = emp;
					break;
				}
				else{//insert in middle
					emp->nextIDNumber = previousTemp->nextIDNumber;
					previousTemp->nextIDNumber = emp;
					break;
				}
			}
			else if(nextTemp->nextIDNumber == NULL){//insert at end if greater than everything
				nextTemp->nextIDNumber = emp;
				tailID = emp;
				break;
			}
			else{
				previousTemp = nextTemp;
				nextTemp = nextTemp->nextIDNumber;
				tempIDNumber = nextTemp->getIDNumber();
			}
		}
	}
#endif
	//INT
#ifndef DEPARTMENT
	//see if pointer to headDepartment is NULL/empty
	if(headDepartment == NULL){
		headDepartment = emp;
		tailDepartment = emp;
	}
	//there is a linked list already. Now find out where the pointer needs to go
	else{
		int empDepartment = emp->getDepartment();//this is our new employee Department to sort
		Employee* nextTemp = headDepartment;//copy reference to go through LL chain
		Employee* previousTemp = NULL;//have reference to past pointer
		int tempDepartment = nextTemp->getDepartment();//copy Department of nextTemp
		while(true){
			if(empDepartment < tempDepartment){
				if(previousTemp == NULL){//insert into beginning/headDepartment
					emp->nextDepartment = headDepartment;
					headDepartment = emp;
					break;
				}
				else{//insert in middle
					emp->nextDepartment = previousTemp->nextDepartment;
					previousTemp->nextDepartment = emp;
					break;
				}
			}
			else if(nextTemp->nextDepartment == NULL){//insert at end if greater than everything
				nextTemp->nextDepartment = emp;
				tailDepartment = emp;
				break;
			}
			else{
				previousTemp = nextTemp;
				nextTemp = nextTemp->nextDepartment;
				tempDepartment = nextTemp->getDepartment();
			}
		}
	}
#endif
	//STRING
#ifndef JOBTITLE
	if(headJobTitle == NULL){
			headJobTitle = emp;
			tailJobTitle = emp;
		}
		else{
			string tempJobTitle = emp->getJobTitle();
			Employee *temp = headJobTitle;
			Employee *previousTemp = headJobTitle->previousJobTitle;
			while(true){
				string JobTitle = temp->getJobTitle();
				int length = 0;
				if(tempJobTitle.length()>JobTitle.length()){
					length = JobTitle.length();
				}
				else{length = tempJobTitle.length();}
				if(strncmp(tempJobTitle.c_str(),JobTitle.c_str(),length) < 0){
					//cout << "<0JobTitle: " << JobTitle << "\ntempJobTitle: " << tempJobTitle << endl;
					if(previousTemp == NULL){
						emp->nextJobTitle = headJobTitle;
						headJobTitle = emp;
						break;
					}
					else{
						emp->nextJobTitle = temp;
						previousTemp->nextJobTitle = emp;
						break;
					}
				}
				else if(strncmp(JobTitle.c_str(),tempJobTitle.c_str(),length) == 0){
					//cout << "0JobTitle: " << JobTitle << "\ntempJobTitle: " << tempJobTitle << endl;
					if(temp->nextJobTitle == NULL){
						temp->nextJobTitle = emp;
						tailJobTitle = emp;
						break;
					}
				}
				else{
					if(temp->nextJobTitle == NULL){
						temp->nextJobTitle = emp;
						tailJobTitle = emp;
						break;
					}
				}

				if(temp->nextJobTitle ==NULL){
					break;
				}
				else{
					previousTemp = temp;
					temp = temp->nextJobTitle;

				}
			}
		}
#endif
	//STRING
#ifndef LOCATION
	if(headLocation == NULL){
			headLocation = emp;
			tailLocation = emp;
		}
		else{
			string tempLocation = emp->getLocation();
			Employee *temp = headLocation;
			Employee *previousTemp = headLocation->previousLocation;
			while(true){
				string Location = temp->getLocation();
				int length = 0;
				if(tempLocation.length()>Location.length()){
					length = Location.length();
				}
				else{length = tempLocation.length();}
				if(strncmp(tempLocation.c_str(),Location.c_str(),length) < 0){
					//cout << "<0Location: " << Location << "\ntempLocation: " << tempLocation << endl;
					if(previousTemp == NULL){
						emp->nextLocation = headLocation;
						headLocation = emp;
						break;
					}
					else{
						emp->nextLocation = temp;
						previousTemp->nextLocation = emp;
						break;
					}
				}
				else if(strncmp(Location.c_str(),tempLocation.c_str(),length) == 0){
					//cout << "0Location: " << Location << "\ntempLocation: " << tempLocation << endl;
					if(temp->nextLocation == NULL){
						temp->nextLocation = emp;
						tailLocation = emp;
						break;
					}
				}
				else{
					if(temp->nextLocation == NULL){
						temp->nextLocation = emp;
						tailLocation = emp;
						break;
					}
				}

				if(temp->nextLocation ==NULL){
					break;
				}
				else{
					previousTemp = temp;
					temp = temp->nextLocation;

				}
			}
		}
#endif
	//INT
#ifndef RATING
	//see if pointer to headRating is NULL/empty
		if(headRating == NULL){
			headRating = emp;
			tailRating = emp;
		}
		//there is a linked list already. Now find out where the pointer needs to go
		else{
			int empRating = emp->getRating();//this is our new employee Rating to sort
			Employee* nextTemp = headRating;//copy reference to go through LL chain
			Employee* previousTemp = NULL;//have reference to past pointer
			int tempRating = nextTemp->getRating();//copy Rating of nextTemp
			while(true){
				if(empRating < tempRating){
					if(previousTemp == NULL){//insert into beginning/headRating
						emp->nextRating = headRating;
						headRating->previousRating = emp;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
						headRating = emp;
						break;
					}
					else{//insert in middle
						emp->nextRating = previousTemp->nextRating;
						emp->nextRating->previousRating = emp;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
						emp->previousRating = previousTemp;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
						previousTemp->nextRating = emp;
						break;
					}
				}
				else if(nextTemp->nextRating == NULL){//insert at end if greater than everything
					nextTemp->nextRating = emp;
					emp->previousRating = nextTemp;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
					tailRating = emp;
					break;
				}
				else{
					previousTemp = nextTemp;
					nextTemp = nextTemp->nextRating;
					tempRating = nextTemp->getRating();
				}
			}
		}
#endif
}
void LinkedList::newTerminatedEmployee(TerminatedEmployee *tTemp){
#ifndef NAME
	if(headNameT == NULL){
		headNameT = tTemp;
		tailNameT = tTemp;
	}
	else{
		string empName = tTemp->getName();
		TerminatedEmployee *temp = headNameT;
		TerminatedEmployee *previousTemp = headNameT->previousName;
		while(true){
			string name = temp->getName();
			int length = 0;
			if(empName.length()>name.length()){
				length = name.length();
			}
			else{length = empName.length();}
			if(strncmp(empName.c_str(),name.c_str(),length) < 0){
				//cout << "<0name: " << name << "\nempName: " << empName << endl;
				if(previousTemp == NULL){
					tTemp->nextName = headNameT;
					tTemp->nextName->previousName = tTemp;
					headNameT = tTemp;
					break;
				}
				else{
					tTemp->nextName = temp;
					previousTemp->nextName = tTemp;
					tTemp->previousName = previousTemp; ////BACKWARDS
					temp->previousName = tTemp;
					break;
				}
			}
			else if(strncmp(name.c_str(),empName.c_str(),length) == 0){
				//cout << "0name: " << name << "\ntempName: " << empName << endl;
				if(temp->nextName == NULL){
					temp->nextName = tTemp;
					tTemp->previousName = temp; ////BACKWARDS
					tailNameT = tTemp;
					break;
				}
			}
			else{
				if(temp->nextName == NULL){
					//cout << "here for" << emp->getName() << endl;
					temp->nextName = tTemp;
					tTemp->previousName = temp; ////BACKWARDS
					tailNameT = tTemp;
					break;
				}
			}

			if(temp->nextName ==NULL){
				break;
			}
			else{
				previousTemp = temp;
				temp = temp->nextName;

			}
		}
	}
#endif
	//cout << "NAME COMPLETE" << endl;
#ifndef ID
	//see if pointer to headID is NULL/empty
	if(headIDNumberT == NULL){
		//cout << "HEADIDNUMBERT is NULL" << endl;
		headIDNumberT = tTemp;
		tailIDNumberT = tTemp;
		//cout << "Finished initialization" << endl;
	}
	//there is a linked list already. Now find out where the pointer needs to go
	else{
		//cout << "HEADIDNUMBER is not NULL" << endl;
		int empIDNumber = tTemp->getIDNumber();//this is our new employee IDNumber to sort
		TerminatedEmployee* nextTemp = headIDNumberT;//copy reference to go through LL chain
		TerminatedEmployee* previousTemp = NULL;//have reference to past pointer
		int tempIDNumber = nextTemp->getIDNumber();//copy IDNumber of nextTemp
		while(true){
			if(empIDNumber < tempIDNumber){
				if(previousTemp == NULL){//insert into beginning/headID
					tTemp->nextIDNumber = headIDNumberT;
					headIDNumberT = tTemp;
					break;
				}
				else{//insert in middle
					tTemp->nextIDNumber = previousTemp->nextIDNumber;
					previousTemp->nextIDNumber = tTemp;
					break;
				}
			}
			else if(nextTemp->nextIDNumber == NULL){//insert at end if greater than everything
				nextTemp->nextIDNumber = tTemp;
				tailIDNumberT = tTemp;
				break;
			}
			else{
				previousTemp = nextTemp;
				nextTemp = nextTemp->nextIDNumber;
				tempIDNumber = nextTemp->getIDNumber();
			}
		}
	}
#endif
	//cout << "Finished newEmployee" << endl;
}
void LinkedList::removeEmployee(string name,LinkedList *tList){
	Employee *temp = headName;

	if(temp == NULL){
		cout << "nothing to remove" << endl;
	}
	else{
		//search for name and remove
		while(true){
			if(strcmp(temp->getName().c_str(), name.c_str()) == 0 && temp->nextName != NULL && strcmp(temp->nextName->getName().c_str(),name.c_str()) != 0){
				//found name now delete
				if(temp->previousName == NULL){
					cout << temp->getName().c_str() << endl;
					headName = temp->nextName;
					//here
				}
				else{
					cout << "not beginning" << endl;
					temp->previousName->nextName = temp->nextName;
					if(temp->previousName->nextName == NULL){
						tailName = temp->previousName;
					}
					//here
				}
				TerminatedEmployee *terminatedEmp = new TerminatedEmployee(temp->getName(),temp->getIDNumber());
				cout << "Employee " << terminatedEmp->getName() << " has been terminated." << endl;
				tList->newTerminatedEmployee(terminatedEmp);
				//cout << "after" << endl;
				//free(temp);
				break;
			}
			else if(strcmp(temp->getName().c_str(), name.c_str()) == 0 && temp->nextName != NULL && strcmp(temp->nextName->getName().c_str(),name.c_str()) == 0){
				Employee* temp1 = temp;
				cout << "\nThere is more than one \"" << name << "\" in the employee database. They are listed below:\n\"NAME\"            ID Number:"<< endl;
				while(strcmp(name.c_str(),temp1->getName().c_str()) == 0){
					cout << left << setw(16) << temp1->getName() << "  " << temp1->getIDNumber() << "\n";
					if(temp1->nextName != NULL){
						temp1 = temp1->nextName;
					}
					else{
						break;
					}
				}
				int iDNumber;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter the ID number of the employee to be terminated: ";
				cin >> iDNumber;
				temp1 = temp;
				while(true){
					if(iDNumber == temp1->getIDNumber()){
						if(temp1->previousName == NULL){
							//cout << temp1->getName().c_str() << endl;
							headName = temp1->nextName;
							//here
						}
						else{
							temp1->previousName->nextName = temp1->nextName;
							if(temp1->previousName->nextName == NULL){
								tailName = temp1->previousName;
							}
							//here
						}
						TerminatedEmployee *terminatedEmp = new TerminatedEmployee(temp1->getName(),temp1->getIDNumber());
						cout << "Employee " << terminatedEmp->getName() << " has been terminated." << endl;
						cout.clear();
						tList->newTerminatedEmployee(terminatedEmp);
						//cout << "Finished tList->newTerminatedEmployee" << endl;
						//free(temp1);
						return;
					}
					else if(strcmp(name.c_str(),temp1->getName().c_str()) == 0){
						if(temp1->nextName != NULL){
							temp1 = temp1->nextName;
						}
						else{
							cout << "\nID number not found! Returning to main menu.\n" << endl;
							break;
						}
					}
					else{
						cout << "\nID number not found! Returning to main menu.\n" << endl;
						break;
					}
				}
			}
			else if(strcmp(temp->getName().c_str(), name.c_str()) == 0 && temp->nextName == NULL){
				tailName = temp->previousName;
				temp->previousName->nextName = NULL;
				TerminatedEmployee *terminatedEmp = new TerminatedEmployee(temp->getName(),temp->getIDNumber());
				cout << "Employee " << terminatedEmp->getName() << " has been terminated." << endl;
				tList->newTerminatedEmployee(terminatedEmp);
				//cout << "after" << endl;
				//free(temp);
				break;
			}
			else if(temp->nextName == NULL){
				cout << "Employee not in database"<< endl;
				break;
			}
			else{
				temp = temp->nextName;
			}
		}
	}
}
void LinkedList::printList(int catagory){


	Employee* tempEmp;
	switch(catagory){
	case 1://BY NAME
#ifndef PRINT_NAME
		tempEmp = headName;
		printf("Displaying employee's by name\n\"NAME\"            ID Number:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getIDNumber() << "\n";
				if(tempEmp->nextName == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextName;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 2://BY AGE
#ifndef PRINT_AGE
		tempEmp = headAge;
		printf("Displaying employee's by age\n\"NAME\"            Age:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getAge() << "\n";
				if(tempEmp->nextAge == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextAge;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 3://BY SALARY
#ifndef PRINT_Salary
		tempEmp = headSalary;
		printf("Displaying employee's by Salary\n\"NAME\"            Salary:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getSalary() << "\n";
				if(tempEmp->nextSalary == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextSalary;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
		break;
#endif
	case 4://BY YEARSWORKED
#ifndef YearsWorked
		tempEmp = headYearW;
		printf("Displaying employee's by YearsWorked\n\"NAME\"            YearsWorked:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getYearsWorked() << "\n";
				if(tempEmp->nextYearsWorked == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextYearsWorked;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 5://BY IDNUMBER
#ifndef IDNumber
		tempEmp = headID;
		printf("Displaying employee's by IDNumber\n\"NAME\"            IDNumber:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getIDNumber() << "\n";
				if(tempEmp->nextIDNumber == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextIDNumber;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 6://BY DEPARTMENT
#ifndef Department
		tempEmp = headDepartment;
		printf("Displaying employee's by Department\n\"NAME\"            Department:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getDepartment() << "\n";
				if(tempEmp->nextDepartment == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextDepartment;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 7://BY JOBTITLE
#ifndef PRINT_JobTitle
		tempEmp = headJobTitle;
		printf("Displaying employee's by JobTitle\n\"NAME\"            JobTitle:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getJobTitle() << "\n";
				if(tempEmp->nextJobTitle == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextJobTitle;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 8://BY LOCATION
#ifndef PRINT_Location
		tempEmp = headLocation;
		printf("Displaying employee's by Location\n\"NAME\"            Location:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getLocation() << "\n";
				if(tempEmp->nextLocation == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->nextLocation;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 9://BY RATING
#ifndef Rating
		tempEmp = tailRating;
		printf("Displaying employee's by Rating\n\"NAME\"            Rating:\n");
		//see if stack is filled with anything
		if(tempEmp != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << tempEmp->getName() << "  " << tempEmp->getRating() << "\n";
				if(tempEmp->previousRating == NULL){
					break;
				}
				else{
					tempEmp = tempEmp->previousRating;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif
		break;
	case 10://BY TERMINATEDNAME
#ifndef PRINT_NAME
		TerminatedEmployee *terminatedEmp = headNameT;
		printf("\nDisplaying employee's by name\n\"NAME\"            ID Number:\n");
		//see if stack is filled with anything
		if(headNameT != NULL){
			//print data until printStack node next* is NULL
			while(true){
				cout << left << setw(16) << terminatedEmp->getName() << "  " << terminatedEmp->getIDNumber() << "\n";
				if(terminatedEmp->nextName == NULL){
					break;
				}
				else{
					terminatedEmp = terminatedEmp->nextName;
				}
			}
		}
		else{
			//if empty, output N/A
			cout <<"N/A";
		}
		cout << endl;
#endif

		break;
	}




}
void LinkedList::newYear(){
	if(headName == NULL){
		cout << "\n****INVALID OPTION****\n\nThere are no employee(s) in database!\n" << endl;
		return;
	}
	Employee *temp = headName;
	while(temp != NULL){
		temp->newYear();
		temp = temp->nextName;
	}
}
void LinkedList::editEmployee(){
	printList(5);
	int ID;
	cout << "\nEDIT EMPLOYEE INTERFACE\n\nEnter ID number of employee:";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> ID;
	Employee *emp = headID;
	cout << "after headID" << endl;
	cout << emp->getIDNumber() << endl;
	while(true){
		if(emp->getIDNumber() == ID){
			cout << "\nCurrent Employee:\n ID Number: " << ID <<"\nName: " << emp->getName() << "\nAge: " << emp->getAge() << "\nSalary: " << emp->getSalary() << "\nYears Worked: " << emp->getYearsWorked() << "\nJob Title: " << emp->getJobTitle() << "\nLocation: " << emp->getLocation() << "\nRating: " << emp->getRating() << endl;
			int category;
			cout << "\nWhat would you like to edit?\n1: Name\n2: Age\n3:Salary\n4:Years Worked\n5: Job Title\n6:Location\n7:Rating\nEnter the number associated with the category: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> category;
			string newname;
			int age;
			double salary;
			int yearsWorked;
			string jobTitle;
			string location;
			int rating;
			switch(category){
			case 1:
				cout << "\nEnter new name: ";
				cin.clear();
				cin.ignore();
				cin >> newname;
				emp->setName(newname);
				break;
			case 2:
				cout << "\nEnter new age: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> age;
				emp->setAge(age);
				break;
			case 3:
				cout << "\nEnter new salary: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> salary;
				emp->setSalary(salary);
				break;
			case 4:
				cout << "\nEnter new years worked: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> yearsWorked;
				emp->setYearsWorked(yearsWorked);
				break;
			case 5:
				cout << "\nEnter new job title: ";
				cin.clear();
				cin.ignore();
				cin >> jobTitle;
				emp->setJobTitle(jobTitle);
				break;
			case 6:
				cout << "\nEnter new job location: ";
				cin.clear();
				cin.ignore();
				cin >> location;
				emp->setLocation(location);
			    break;
			case 7:
				cout << "\nEnter new rating: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> rating;
				emp->setRating(rating);
				break;
			}

			cout << "\nEdited Employee:\n ID Number: " << ID <<"\nName: " << emp->getName() << "\nAge: " << emp->getAge() << "\nSalary: " << emp->getSalary() << "\nYears Worked: " << emp->getYearsWorked() << "\nJob Title: " << emp->getJobTitle() << "\nLocation: " << emp->getLocation() << "\nRating: " << emp->getRating() << endl;
			string input = "";
			string y = "Y";
			while(true){
				cin.clear();
				cout << "Would you like to change anything else?(Y/N)\n";
				cin >> input;
				cout << input << endl;
				if(strcmp(input.c_str(), "Y") == 0 || strcmp(input.c_str(), "N") == 0){
					break;
				}
			}
			if(strcmp(input.c_str(), "N") == 0){
				cout << "\nReturning to employee menu\n" << endl;
				return;
			}
		}
		else if(emp->nextIDNumber != NULL){
			emp = emp->nextIDNumber;
		}
		else{
			return;
		}
	}
}
Employee* LinkedList::getHeadName(){
	return this->headName;
}
TerminatedEmployee* LinkedList::getHeadNameT(){
	return this->headNameT;
}



