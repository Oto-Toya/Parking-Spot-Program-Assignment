#include "cCar.h"

// Constructor - initializes all member variables and allocates dynamic memory
cCar::cCar()
{
	cout << "cCar Constructor called" << endl;
	
	// Allocate memory for license plate (7 chars for string + null terminator)
	_licensePlate = new char[7];
	
	// Allocate memory for car make (20 chars for string + null terminator)
	_make = new char[20];
	
	// Allocate memory for car colour (20 chars for string + null terminator)
	_colour = new char[20];
}

// Destructor - frees all dynamically allocated memory
cCar::~cCar()
{
	cout << "cCar Destructor called" << endl;
	
	// Free license plate memory
	delete[] _licensePlate;
	
	// Free car make memory
	delete[] _make;
	
	// Free car colour memory
	delete[] _colour;
}

// Copy Constructor - creates a deep copy of another car object
cCar::cCar(cCar& copy)
{
	// Allocate memory for dynamic members
	_licensePlate = new char[7];
	_make = new char[20];
	_colour = new char[20];

	cout << "cCar Copy Constructor called" << endl;

	// Copy the record ID (primitive type)
	_recordID = copy._recordID;

	// Deep copy license plate string with null terminator
	strncpy_s(_licensePlate, 7, copy._licensePlate ? copy._licensePlate : "", 6);
	_licensePlate[6] = '\0';

	// Deep copy car make string with null terminator
	strncpy_s(_make, 7, copy._make ? copy._make : "", 6);
	_make[19] = '\0';

	// Deep copy car colour string with null terminator
	strncpy_s(_colour, 7, copy._colour ? copy._colour : "", 6);
	_colour[19] = '\0';

	// Copy employee owner information
	_owner.ownercopy(_owner, copy._owner);
}

// Gets car data from user input
void cCar::getCarData()
{
	// Only ask for parking cost if it hasn't been set yet (static variable)
	if (!_cost)
	{
		cout << "Enter parking cost: ";
		cin >> _cost;
	}
	
	// Get car record ID
	cout << "Enter car record ID: ";
	cin >> _recordID;
	cin.ignore(INT_MAX, '\n');
	cin.clear();

	// Get license plate (max 6 characters)
	cout << "Enter car license plate: ";
	cin.getline(_licensePlate, 7);
	cin.clear();

	// Get car make (max 19 characters)
	cout << "Enter car make: ";
	cin.getline(_make, 20);
	cin.clear();

	// Get car colour (max 19 characters)
	cout << "Enter car colour: ";
	cin.getline(_colour, 20);
	cin.clear();

	// Get owner information
	_owner.getEmployeeData();
}

// Displays all car data
void cCar::showCarData()
{
	cout << endl;
	cout << "Parking Cost: " << _cost << endl;	
	cout << "Car Record ID: " << _recordID << endl;
	cout << "Car License Plate: " << _licensePlate << endl;
	cout << "Car Make: " << _make << endl;
	cout << "Car Colour: " << _colour << endl;
	_owner.showEmployeeData();
}

// Displays car data only if the record ID matches the parameter
bool cCar::showSpeficData(int carRec)
{
	cin.ignore(INT_MAX, '\n');
	
	// Compare input record ID with this car's record ID
	if (carRec == _recordID)
	{
		// Record ID matches - display car data
		showCarData();
		return 1;  // Return true to indicate match found
	}
	else {
		// Record ID does not match
		return 0;  // Return false to indicate no match
	}
}

// Allows user to modify specific car attributes
void cCar::mutateSpecificData()
{
	int i;
	cout << "Mutate Options\n1.Record ID\n2.License Plate\n3.Make\n4.Colour\n5.Owner Details\n6.Parking Cost" << endl;
	cin >> i;
	cin.ignore(INT_MAX, '\n');
	
	// Modify based on user selection
	if (i == 1) {
		cout << "Enter New Record ID: ";
		cin >> _recordID;
		cin.ignore(INT_MAX, '\n');
	}
	else if (i == 2) {
		cout << "Enter New License Plate: ";
		cin.getline(_licensePlate, 7);
		cin.clear();
	}
	else if (i == 3) {
		cout << "Enter New Make: ";
		cin.getline(_make, 20);
		cin.clear();
	}
	else if (i == 4) {
		cout << "Enter New Colour: ";
		cin.getline(_colour, 20);
		cin.clear();
	}
	else if (i == 5) {
		// Modify owner information
		_owner.mutateEmployeeData();
	}
	else if (i == 6) {
		cout << "Enter new parking cost: ";
		cin >> _cost;
	}
	else {
		cout << "Selection out of bounds";
	}
}

// Allows user to modify all car attributes at once
void cCar::mutateAllData()
{
	cout << "Enter new car record ID: ";
	cin >> _recordID;
	cin.ignore(INT_MAX, '\n');
	cin.clear();

	cout << "Enter new car license plate: ";				
	cin.getline(_licensePlate, 7);
	cin.clear();

	cout << "Enter new car make: ";
	cin.getline(_make, 20);
	cin.clear();

	cout << "Enter new car colour: ";
	cin.getline(_colour, 20);
	cin.clear();

	// Get updated owner information
	_owner.getEmployeeData();
}


