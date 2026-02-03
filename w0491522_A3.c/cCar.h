#pragma once
#include "cEmployee.h"
#include <iostream>

using namespace std;

class cEmployee; // Forward declaration for cEmployee class

// cCar class definition - represents a parked car with owner information
class cCar
{
public:
	// Constructor - initializes a new car object
	cCar();
	
	// Destructor - cleans up dynamically allocated memory
	~cCar();
	
	// Copy Constructor - creates a deep copy of another car object
	cCar(cCar&);
	
	// Gets car data from user input
	void getCarData();
	
	// Displays all car data
	void showCarData();
	
	// Displays car data if record ID matches the parameter
	bool showSpeficData(int);
	
	// Allows user to modify specific car attributes
	void mutateSpecificData();
	
	// Allows user to modify all car attributes
	void mutateAllData();
	
private:
	// Employee object representing car owner
	cEmployee _owner;
	
	// Unique record ID for the car
	int _recordID;
	
	// Dynamically allocated string for license plate (7 chars max)
	char* _licensePlate;
	
	// Dynamically allocated string for car make (20 chars max)
	char* _make;
	
	// Dynamically allocated string for car colour (20 chars max)
	char* _colour;
	
	// Static variable - shared among all car instances
	inline static float _cost = 0;
};

