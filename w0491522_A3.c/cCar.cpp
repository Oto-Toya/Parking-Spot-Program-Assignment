#include "cCar.h"

cCar::cCar()
{
	cout << "cCar Constructor called" << endl;
	_licensePlate = new char[7];
	_make = new char[20];
	_colour = new char[20];
}

cCar::~cCar()
{
	cout << "cCar Destructor called" << endl;
	delete[] _licensePlate;
	delete[] _make;
	delete[] _colour;
}

cCar::cCar(cCar& copy)
{
	cout << "cCar Constructor called" << endl;

	_recordID = copy._recordID;
	_licensePlate = copy._licensePlate;
	_make = copy._make;
	_colour = copy._colour;
	_owner = copy._owner;
}

void cCar::getCarData()
{
	cout << "Enter car record ID: ";
	cin >> _recordID;
	cin.ignore(INT_MAX, '\n');
	cin.clear();

	cout << "Enter car license plate: ";
	cin.getline(_licensePlate, 7);
	cin.clear();

	cout << "Enter car make: ";
	cin.getline(_make, 20);
	cin.clear();

	cout << "Enter car colour: ";
	cin.getline(_colour, 20);
	cin.clear();

	_owner.getEmployeeData();
}

void cCar::showCarData()
{
	cout << endl;
	cout << "Car Record ID: " << _recordID << endl;
	cout << "Car License Plate: " << _licensePlate << endl;
	cout << "Car Make: " << _make << endl;
	cout << "Car Colour: " << _colour << endl;
	_owner.showEmployeeData();
}

void cCar::showSpeficData()
{
	int i;
	cout << "Display Options\n1. Record ID\n2. License Plate\n3. Make\n4. Colour\n5. Owner Details" << endl;
	cin >> i;
	cin.ignore(INT_MAX, '\n');
	if (i == 1) {
		cout << "Car Record ID: " << _recordID << endl;
	}
	else if (i == 2) {
		cout << "Car License Plate: " << _licensePlate << endl;
	}
	else if (i == 3) {
		cout << "Car Make: " << _make << endl;
	}
	else if (i == 4) {
		cout << "Car Colour: " << _colour << endl;
	}
	else if (i == 5) {
		_owner.showEmployeeData();
	}
	else {
		cout << "Selection out of bounds";
	}
}

void cCar::mutateSpecificData()
{
	int i;
	cout << "Mutate Options\n1.Record ID\n2.License Plate\n3.Make\n4.Colour\n5.Owner Details" << endl;
	cin >> i;
	cin.ignore(INT_MAX, '\n');
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
		cout << "Enter New Colour";
		cin.getline(_colour, 20);
		cin.clear();
	}
	else if (i == 5) {
		_owner.getEmployeeData();
	}
	else {
		cout << "Selection out of bounds";
	}
}

void cCar::mutateAllData()
{
	cout << endl;
	cout << "New Car Record ID: " << _recordID << endl;
	cout << "New Car License Plate: " << _licensePlate << endl;
	cout << "New Car Make: " << _make << endl;
	cout << "New Car Colour: " << _colour << endl;
	_owner.showEmployeeData();
}

