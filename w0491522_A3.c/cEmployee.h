#pragma once
#include <iostream>

class cEmployee; // Forward declaration
using namespace std;

class cEmployee
{
public:
	cEmployee();
	~cEmployee();
	void getEmployeeData();
	void showEmployeeData();
private:
	char* _name;
	char* _department;
};

