#pragma once
#include <iostream>
#include <cstring>

using namespace std;

// cEmployee class definition - represents an employee who owns a car
class cEmployee
{
public:
	// Constructor - initializes employee object and allocates dynamic memory
	cEmployee();
	
	// Destructor - frees dynamically allocated memory
	~cEmployee();
	
	// Gets employee data from user input
	void getEmployeeData();
	
	// Displays all employee data
	void showEmployeeData();
	
	// Allows user to modify employee data
	void mutateEmployeeData();
	
	// Copies employee data from source to destination
	void ownercopy(cEmployee& dest, const cEmployee& src);
	
private:
	// Dynamically allocated string for employee name (20 chars max)
	char* _name;
	
	// Dynamically allocated string for employee department (20 chars max)
	char* _department;
};

