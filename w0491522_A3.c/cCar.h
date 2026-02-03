#pragma once
#include "cEmployee.h"
#include <iostream>

using namespace std;

class cEmployee; // Forward declaration

class cCar
{
public:
	cCar();
	~cCar();
	cCar(cCar&);
	void getCarData();
	void showCarData();
	bool showSpeficData(int);
	void mutateSpecificData();
	void mutateAllData();
private:
	cEmployee _owner;
	int _recordID;
	char* _licensePlate;
	char* _make;
	char* _colour;
	inline static float _cost = 0;
};

