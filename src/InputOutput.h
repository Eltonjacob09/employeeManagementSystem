/*
 * InputOutput.h
 *
 *  Created on: Apr 20, 2018
 *      Author: jake
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <dirent.h>
#include "Employee.h"
#include "LinkedList.h"
#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_

class input_output{

private:

    // Current or Terminated Employees.
    // 1 for current, -1 for terminated.
    // All text files will start with current so initialize to 1.
    int employee_list;

    // Current Employees
    // Input Variables (followed by _in)
    string filename_in, line_data_in, person_name_in, person_location_in, person_jobtitle_in;
    std::vector<string> filedata_in;
    int person_age_in, person_id_in, person_yearsworked_in, person_deprtnum_in, person_rating_in;
    double person_salary_in;

    // Output Variables(followed by _out)
    string filename_out, line_data_out, person_name_out, person_jobtitle_out, person_location_out;
    std::vector<string> filedata_out;
    int person_age_out, person_id_out, person_yearsworked_out, person_deprtnum_out, person_rating_out;
    double person_salary_out;

    // Input Variables
    // For Terminated Employees
    // These variables will be followed by _term for terminated.
    int person_id_in_term;
    string person_name_in_term;

    // Output Variables
    // For Terminated Employees
    int person_id_out_term;
    string person_name_out_term;
    int output_first_term;




public:

    input_output(){
        employee_list = 1;
        output_first_term = 1;
    }
    void resetInputOutput(){
    	employee_list = 1;
    	filename_in = "";
    	line_data_in = "";
    	person_name_in = "";
    	person_location_in = "";
    	person_jobtitle_in = "";
    	filedata_in.clear();
    	person_age_in = 0;
    	person_id_in = 0;
    	person_yearsworked_in = 0;
    	person_deprtnum_in = 0;
    	person_rating_in = 0;
    	person_salary_out = 0;
    	person_id_in_term = 0;
    	person_name_in_term = "";
    	person_id_out_term = 0;
    	person_name_out_term = "";
    	output_first_term = 1;

    }
    // Input the file name into this function.
    // For example "Test.txt".
    // This will put in the text file line by line
    // into the filedata_in string vector.
    void setFileNameOut(string filename){
    	this->filename_out = filename;
    }
    void setFileNameIn(string filename){
    	this->filename_in = filename;
    }

    void read_file(void){

        	// Now asks for a valid input file
            ifstream myfile;
            cout << "\nHere are the Current Text Files: \n";
    	    DIR *dir;
    		struct dirent *ent;

    		// This is my directory add yours here.
    		if ((dir = opendir ("C:\\Eclipse_Oxygen\\3503\\FinalProject")) != NULL) {
    	 		/* print all the files and directories within directory */
    	  		while ((ent = readdir (dir)) != NULL) {
    	  			string str(ent -> d_name);
    	  			if(str.length() >3){
    	  				if(str.substr(str.length() - 3) == "txt"){
    					printf ("%s\n", ent->d_name);
    	   				}
    	  			}

    	 		}
    	 		 closedir (dir);
    		}
    		cout << endl;

            cout << "Please enter a file name: ";
           	cin >> filename_in;
    	    myfile.open(filename_in.c_str());

            do{
            	if(!myfile){
            		cout << "Invalid File. Please enter a valid input file name: ";

            		cin >> filename_in;
    	       	 	myfile.open(filename_in.c_str());
    	        	cin.clear();
    	        	cin.ignore(10000, '\n');
    	        }

            }

            while(!myfile);

            while(getline(myfile,line_data_in))
            {
                filedata_in.push_back(line_data_in);
            }
            myfile.close();
        }
    // Takes in the Person's name, age and id and stores them into the output string vector.
    // This is for CURRENT EMPLOYEES
    void output_vector(string person_name_out, int person_age_out, double person_salary_out,
    int person_yearsworked_out, int person_id_out, int person_deprtnum_out, string person_jobtitle_out,
    string person_location_out, int person_rating_out)
    {

        this -> person_name_out = person_name_out;
        this -> person_age_out = person_age_out;
        this -> person_salary_out = person_salary_out;
        this -> person_yearsworked_out = person_yearsworked_out;
        this -> person_id_out = person_id_out;
        this -> person_deprtnum_out = person_deprtnum_out;
        this -> person_jobtitle_out = person_jobtitle_out;
        this -> person_location_out = person_location_out;
        this -> person_rating_out = person_rating_out;

        filedata_out.push_back(person_name_out + ", " + to_string(person_age_out) + ", " + to_string(person_salary_out) +
        ", " + to_string(person_yearsworked_out) + ", " + to_string(person_id_out) + ", " + to_string(person_deprtnum_out) +
        ", " + person_jobtitle_out + ", " + person_location_out + ", " + to_string(person_rating_out));
    }

    // Call this AFTER output_vector
    // Stores the TERMINATED employees inside of the output string vector.
    void output_vector_term(string person_name_out_term, int person_id_out_term){
        this -> person_name_out_term = person_name_out_term;
        this -> person_id_out_term = person_id_out_term;

        if(output_first_term == 1){
            filedata_out.push_back("--, " + person_name_out_term + ", " + to_string(person_id_out_term));
        }

        if(output_first_term == 0){
            filedata_out.push_back(person_name_out_term + ", " + to_string(person_id_out_term));
        }

        output_first_term = 0;

    }

    void create_output_file(string filename_out){

        this -> filename_out = filename_out;

        // Makes an output file.
        ofstream outfile;
        outfile.open(filename_out.c_str(),ofstream::out | ofstream::trunc);
        for(int i = 0; i < (signed)filedata_out.size(); i++ ){
            outfile << filedata_out[i] << endl;
        }

        outfile.close();
    }

    void saveDatabase(LinkedList *list, LinkedList *tList){
    	if(list->getHeadName() == NULL && tList->getHeadNameT() == NULL){
    		cout << "****ERROR: DATABASE IS EMPTY!!!****\n" << endl;
    		return;
    	}
    	else if(list->getHeadName() != NULL && tList->getHeadNameT() == NULL){
    		Employee* emp = list->getHeadName();
    		while(true){
    			output_vector(emp->getName(), emp->getAge(), emp->getSalary(), emp->getYearsWorked(), emp->getIDNumber(), emp->getDepartment(), emp->getJobTitle(), emp->getLocation(), emp->getRating());
    			if(emp->nextName == NULL){
    				break;
    			}
    			else{
    				emp = emp->nextName;
    			}
    		}
    		print_file_out();
    		create_output_file(filename_out);
    	}
    	else if(list->getHeadName() == NULL && tList->getHeadNameT() != NULL){
    		TerminatedEmployee* emp = list->getHeadNameT();
    		while(true){
    			output_vector_term(emp->getName(), emp->getIDNumber());
    			if(emp->nextName == NULL){
    				break;
    			}
    			else{
    				emp = emp->nextName;
    			}
    		}
    		print_file_out();
    		create_output_file(filename_out);
    	}
    	else{
    		Employee* emp = list->getHeadName();
    		while(true){
    			output_vector(emp->getName(), emp->getAge(), emp->getSalary(), emp->getYearsWorked(), emp->getIDNumber(), emp->getDepartment(), emp->getJobTitle(), emp->getLocation(), emp->getRating());
    			if(emp->nextName == NULL){
    				break;
    			}
    			else{
    				emp = emp->nextName;
    			}
    		}
    		TerminatedEmployee* temp = tList->getHeadNameT();
    		while(true){
    			output_vector_term(temp->getName(), temp->getIDNumber());
    			if(temp->nextName == NULL){
    				break;
    			}
    			else{
    				temp = temp->nextName;
    			}
    		}
    		print_file_out();
    		create_output_file(filename_out);
    	}
    }

    // Print out all elements of the input string vector.
    // Used for testing purposes.
    void print_file_in(void){
        for(int i = 0; i < (signed)filedata_in.size(); i++){
            cout << filedata_in[i] << endl;
        }
    }

    // Print out all elements of the input string vector.
    // Used for testing purposes.
    void print_file_out(void){
        for(int i = 0; i < (signed)filedata_out.size(); i++){
            cout << filedata_out[i] << endl;
        }
    }

    // Print out the parsed string
    void print_parsed_in(void){

        cout << "Employee's Name: " << person_name_in << endl;
        cout << "Employee's Age: " << person_age_in << endl;
        cout << "Employee's Salary: " << setprecision (2) << fixed << person_salary_in << endl;
        cout << "Employee's Years in the Company: " << person_yearsworked_in << endl;
        cout << "Employee's ID Number: " << person_id_in << endl;
        cout << "Employee's Department Number: " << person_deprtnum_in << endl;
        cout << "Employee's Job Title: " << person_jobtitle_in << endl;
        cout << "Employee's Location: " << person_location_in << endl;
        cout << "Employee's Rating: " << person_rating_in << endl;
        cout << endl;

    }

    void print_parsed_in_term(void){
        cout << "Terminated Employee's Name: " << person_name_in_term << endl;
        cout << "Terminated Emplotee's ID Num: " << person_id_in_term << endl;
        cout << endl;
    }

    // Use this to parse an element of the filedata_in string vector.
    // Takes in an element of the string vector.
    // filedata_in[i]
    // i should be from 0 to filedata_in.size() - 1;
    void parse_string(LinkedList *list, LinkedList *tList){

        for(int i = 0; i < (signed)filedata_in.size(); i++){

            //cout << "This is iteration: " << i << ". Filedata_in is: " << filedata_in[i] << endl;

            // The special charecter -- in a text file will signify when the terminated
            // Employee list starts.
            if(filedata_in[i].substr(0, filedata_in[i].find(",")) == "--"){
                // Delete the charecter --.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);
                // Change to Terminated Employee List.
                employee_list = -1;
            }

            if(employee_list == 1){
                // Parse like this if the Employee is still active (employee_list == 1)
                // Stores the Person's name.
                person_name_in = filedata_in[i].substr(0, filedata_in[i].find(","));
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's age.
                person_age_in = atoi(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's Salary in a String.
                person_salary_in = stod(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Years of a Person's Work
                person_yearsworked_in = atoi(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's ID number.
                person_id_in = atoi(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's Department Number.
                person_deprtnum_in = atoi(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's Job Title.
                person_jobtitle_in = filedata_in[i].substr(0, filedata_in[i].find(",")).c_str();
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's Location.
                person_location_in = filedata_in[i].substr(0, filedata_in[i].find(",")).c_str();
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the Person's Ratings.
                person_rating_in = atoi(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());

                // Print out data each iteration.
                // Replace with group member's function call


                Employee *emp = new Employee(person_name_in, person_age_in, person_salary_in, person_yearsworked_in, person_deprtnum_in,
                person_jobtitle_in, person_location_in, person_id_in, person_rating_in);

                list->newEmployee(emp);
            }

            if(employee_list == -1){
                // Stores the terminated Employee's name.
                person_name_in_term = filedata_in[i].substr(0, filedata_in[i].find(","));
                // Need to erase to read the next comma.
                filedata_in[i].erase(0, filedata_in[i].find(",") + 2);

                // Stores the terminated Employee's ID number.
                person_id_in_term = atoi(filedata_in[i].substr(0, filedata_in[i].find(",")).c_str());



                TerminatedEmployee *tEmp = new TerminatedEmployee(person_name_in_term,person_id_in_term);
                tList->newTerminatedEmployee(tEmp);



            }


        }

    }

    // Get the person's name of the stringvector[i]
    // Call this after parsing the string.
    string get_person_name(void){
        return person_name_in;
    }

    // Get the person's age of the stringvector[i]
    // Call this after parsing the string.
    int get_person_age(void){
        return person_age_in;
    }

    // Get the person's age of the stringvector[i]
    // Call this after parsing the string.
    int get_person_id(void){
        return person_id_in;
    }

    int get_size_vector_in(void){
        return filedata_in.size();
    }

    double get_person_salary(void){
        return person_salary_in;
    }

    int get_person_years(void){
        return person_yearsworked_in;
    }

    int get_person_deprtnum(void){
        return person_deprtnum_in;
    }

    string get_person_location(void){
        return person_location_in;
    }

    int get_person_rating(void){
        return person_rating_in;
    }

    string get_person_jobtitle(void){
        return person_jobtitle_in;
    }
};
/*
int main(){
    int size;
    string filename_in = "data.txt";

    // Make Object.
    input_output input_output_obj;

    // TESTING INPUT METHODS

    // Read the Input File.
    input_output_obj.read_file(filename_in);

    // Parse the Input File into usable data.
    LinkedList *temp = new LinkedList();
    LinkedList *tTemp = new LinkedList();
    input_output_obj.parse_string(temp,tTemp);

    // TESTING OUTPUT METHODS

    // Add to Currently Employed.
    input_output_obj.output_vector("Billy Bob", 69, 1000.02, 50, 1918, 2, "Manager", "Jacksonville", 59);

    // Add to Terminated Employee.
    input_output_obj.output_vector_term("John Smoth", 7689);
    input_output_obj.output_vector_term("Anthony Simas", 9087);
    //input_output_obj.print_file_out();
    input_output_obj.create_output_file("Data.txt");

}
*/



#endif /* INPUTOUTPUT_H_ */
