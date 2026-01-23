#include "cEmployee.h"

cEmployee::cEmployee()
{
	cout << "cEmployee Constructor called" << endl;
	_name = new char[20];
	_department = new char[20];
}

cEmployee::~cEmployee()
{
	cout << "cEmployee Destructor called" << endl;
	delete[] _name;
	delete[] _department;
}

void cEmployee::getEmployeeData() {
	cout << "Enter employee name: ";
	cin.getline(_name, 20);
	cin.clear();

	cout << "Enter employee department: ";
	cin.getline(_department, 20);
	cin.clear();
}

void cEmployee::showEmployeeData() {
	cout << "Employee Name: " << _name << endl;
	cout << "Employee Department: " << _department << endl;
}

void cEmployee::mutateEmployeeData()
{
	cout << "Enter new employee name: ";
	cin.getline(_name, 20);
	cin.clear();

	cout << "Enter new employee department: ";
	cin.getline(_department, 20);
	cin.clear();
}

void cEmployee::ownercopy(const cEmployee& dest, const cEmployee& src)
{
	strncpy_s(dest._name, 20, src._name ? src._name : "", 19);
	dest._name[19] = '\0';
	strncpy_s(dest._department, 20, src._department ? src._department : "", 19);
	dest._department[19] = '\0';
}
