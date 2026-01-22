
#include <iostream>
#include "cCar.h"

using namespace std;
void displayCars(cCar, cCar, cCar);

int main()
{
	cCar* car[3] = { nullptr, nullptr, nullptr };
	int numCars = 0;
	for (int i = 0; i != 4;) {
		cout << "Car Management System\n1. Add Car Data\n2. Display Car Data\n3. Modify Car Data\n4. Exit Program" << endl;
		i = 0;
		cin >> i;
		cin.ignore(INT_MAX, '\n');
		if (i == INT_MAX) {
			cin.clear();
			char* trash;
			trash = new char[50];
			cin.getline(trash, 50);
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			delete[] trash;
			continue;
		}
		if (i == 0) {
			cin.clear();
			char* junk;
			junk = new char[50];
			cin.getline(junk, 50);
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			delete[] junk;

		}
		if (i == 1) {
			cout << "How many cars do you want to add (max 3)?" << endl;
			cin >> numCars;
			cin.ignore(INT_MAX, '\n');
			for (int j = 0; j < numCars && j < 3; j++) {
				if (car[j] == nullptr)
				{
					car[j] = new cCar();
					car[j]->getCarData();
				}
				else {
					cout << "Car slot " << j + 1 << " is already filled." << endl;
				}
			}
		}
		else if (i == 2) {
			if (numCars == 1) {
				car[0]->showCarData();
			}
			else if (numCars == 2) {
				car[0]->showCarData();
				car[1]->showCarData();
			}
			else if (numCars == 3) {
				displayCars(*car[0], *car[1], *car[2]);
			}
			else {
				cout << "No cars to display." << endl;
			}

		}
		if (i == 3) {
			if (numCars != 0) {
				int carnum;
				cout << "Which car do you want to modify (1-3)?" << endl;
				cin >> carnum;
				cin.ignore(INT_MAX, '\n');
				if (carnum < 1 || carnum >= numCars) {
					cout << "What do you want to modify?\n1. All Data\n2. Specific Data" << endl;
					int modifyChoice;
					cin >> modifyChoice;
					cin.ignore(INT_MAX, '\n');
					if (modifyChoice == 1) {
						car[carnum - 1]->mutateAllData();
					}
					else if (modifyChoice == 2) {
						car[carnum - 1]->mutateSpecificData();
					}
					else {
						cout << "Selection out of bounds" << endl;
					}
				}
				else {
					cout << "Car number out of bounds." << endl;
				}
			}
			else {
				cout << "No cars to modify." << endl;
			}
		}
		else if (i == 4) {
			for (int k = 0; k < 3; k++) {
				if (car[k] != nullptr) {
					delete car[k];
				}
				break;
			}
		}
		else {
			cout << "Selection out of bounds" << endl;
		}
	}
	car[0] = new cCar();
	car[0]->getCarData();
	cCar carCopy(*car[0]);
	carCopy.showCarData();

	system("pause");
}

void displayCars(cCar one, cCar two, cCar three) {
	one.showCarData();
	two.showCarData();
	three.showCarData();
}
