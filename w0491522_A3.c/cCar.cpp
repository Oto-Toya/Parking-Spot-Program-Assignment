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
	_licensePlate = new char[7];
	_make = new char[20];
	_colour = new char[20];

	cout << "cCar Copy Constructor called" << endl;

	_recordID = copy._recordID;

	strncpy_s(_licensePlate, 7, copy._licensePlate ? copy._licensePlate : "", 6);
	_licensePlate[6] = '\0';

	strncpy_s(_make, 7, copy._make ? copy._make : "", 6);
	_make[19] = '\0';

	strncpy_s(_colour, 7, copy._colour ? copy._colour : "", 6);
	_colour[19] = '\0';

	_owner.ownercopy(_owner, copy._owner);
}

void cCar::getCarData()
{
	if (!_cost)
	{
	cout << "Enter parking cost: ";
	cin >> _cost;
	}
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
	cout << "Parking Cost: "<< _cost << endl;	
	cout << "Car Record ID: " << _recordID << endl;
	cout << "Car License Plate: " << _licensePlate << endl;
	cout << "Car Make: " << _make << endl;
	cout << "Car Colour: " << _colour << endl;
	_owner.showEmployeeData();
}

bool cCar::showSpeficData(int carRec)
{
	cin.ignore(INT_MAX, '\n');
	if (carRec == _recordID )
		showCarData();
	else {
		return 0;
	}
}

void cCar::mutateSpecificData()
{
	int i;
	cout << "Mutate Options\n1.Record ID\n2.License Plate\n3.Make\n4.Colour\n5.Owner Details\n6.Parking Cost" << endl;
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

	_owner.getEmployeeData();
}


