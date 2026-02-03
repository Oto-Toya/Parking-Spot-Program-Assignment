#include "cEmployee.h"
#include <cstring> // For strncpy_s

// Constructor - initializes all member variables and allocates dynamic memory
cEmployee::cEmployee()
{
	cout << "cEmployee Constructor called" << endl;
	
	// Allocate memory for employee name (20 chars for string + null terminator)
	_name = new char[20];
	
	// Allocate memory for employee department (20 chars for string + null terminator)
	_department = new char[20];
}

// Destructor - frees all dynamically allocated memory
cEmployee::~cEmployee()
{
	cout << "cEmployee Destructor called" << endl;
	
	// Free employee name memory
	delete[] _name;
	
	// Free employee department memory
	delete[] _department;
}

// Gets employee data from user input
void cEmployee::getEmployeeData() {
	// Get employee name (max 19 characters)
	cout << "Enter employee name: ";
	cin.getline(_name, 20);
	cin.clear();

	// Get employee department (max 19 characters)
	cout << "Enter employee department: ";
	cin.getline(_department, 20);
	cin.clear();
}

// Displays all employee data
void cEmployee::showEmployeeData() {
	cout << "Employee Name: " << _name << endl;
	cout << "Employee Department: " << _department << endl;
}

// Allows user to modify employee data
void cEmployee::mutateEmployeeData()
{
	// Update employee name
	cout << "Enter new employee name: ";
	cin.getline(_name, 20);
	cin.clear();

	// Update employee department
	cout << "Enter new employee department: ";
	cin.getline(_department, 20);
	cin.clear();
}

// Copies employee data from source to destination
void cEmployee::ownercopy(cEmployee& dest, const cEmployee& src)
{
	// Deep copy employee name with null terminator
	strncpy_s(dest._name, 20, src._name ? src._name : "", 19);
	dest._name[19] = '\0';
	
	// Deep copy employee department with null terminator
	strncpy_s(dest._department, 20, src._department ? src._department : "", 19);
	dest._department[19] = '\0';
}
