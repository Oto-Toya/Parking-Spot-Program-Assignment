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
	void mutateEmployeeData();
	void ownercopy(const cEmployee& dest,const cEmployee& src);
private:
	char* _name;
	char* _department;
};

