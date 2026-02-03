#include <iostream>
#include "cCar.h"

using namespace std;

// Function declarations
void displayCars(cCar, cCar, cCar);
void ordinaryfunction(cCar&);

int main()
{
	// Initialize array of 3 car pointers, all set to nullptr
	cCar* car[3] = { nullptr, nullptr, nullptr };
	int numCars = 0;
	
	// Main menu loop - continues until user selects option 5 (Exit)
	for (int i = 0; i != 5;) {
		// Display menu options
		cout << "Car Management System\n1. Add Car Data\n2. Display Car Data\n3. Modify Car Data\n4. Display Specific Car Data\n5. Exit Program" << endl;
		i = 0;
		cin >> i;
		cin.ignore(INT_MAX, '\n');
		
		// Check for invalid input (INT_MAX indicates overflow)
		if (i == INT_MAX) {
			cin.clear();
			char* trash;
			trash = new char[50];
			cin.getline(trash, 50);
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			delete[] trash;
			continue;
		}
		
		// Check if input is zero (invalid)
		if (i == 0) {
			cin.clear();
			char* junk;
			junk = new char[50];
			cin.getline(junk, 50);
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			delete[] junk;
		}
		
		// Option 1: Add new cars
		if (i == 1) {
			cout << "How many cars do you want to add (max 3)?" << endl;
			cin >> numCars;
			cin.ignore(INT_MAX, '\n');
			
			// Validate numCars input is within acceptable range
			if (numCars < 1 || numCars > 3) {
				cout << "Invalid input. Please enter a number between 1 and 3." << endl;
				numCars = 0;
				continue;
			}
			
			// Loop through each car slot up to numCars or 3 (whichever is smaller)
			for (int j = 0; j < numCars && j < 3; j++) {
				// Only allocate if the slot is empty
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
		
		// Option 2: Display all car data
		else if (i == 2) {
			if (numCars == 0) {
				cout << "No cars to display." << endl;
			}
			else if (numCars == 1) {
				// Check if car[0] is allocated before dereferencing
				if (car[0] != nullptr) {
					car[0]->showCarData();
				}
			}
			else if (numCars == 2) {
				// Check if cars are allocated before dereferencing
				if (car[0] != nullptr) {
					car[0]->showCarData();
				}
				if (car[1] != nullptr) {
					car[1]->showCarData();
				}
			}
			else if (numCars == 3) {
				// Check if all cars are allocated before dereferencing
				if (car[0] != nullptr && car[1] != nullptr && car[2] != nullptr) {
					// Pass car objects by value to displayCars function
					displayCars(*car[0], *car[1], *car[2]);
				}
				else {
					cout << "Not all car slots are filled." << endl;
				}
			}
		}
		
		// Option 3: Modify car data
		else if (i == 3) {
			if (numCars != 0) {
				int carnum;
				cout << "Which car do you want to modify (1-3)?" << endl;
				cin >> carnum;
				cin.ignore(INT_MAX, '\n');
				
				// Check if selected car number is valid (should be >= 1 AND <= numCars)
				if (carnum >= 1 && carnum <= numCars) {
					cout << "What do you want to modify?\n1. All Data\n2. Specific Data" << endl;
					int modifyChoice;
					cin >> modifyChoice;
					cin.ignore(INT_MAX, '\n');
					
					// Apply modification based on user choice
					if (modifyChoice == 1) {
						car[carnum - 1]->mutateAllData();
					}
					else if (modifyChoice == 2) {
						car[carnum - 1]->mutateSpecificData();
					}
					else {
						cout << "Selection out of bounds." << endl;
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
		
		// Option 4: Display specific car by record ID
		else if (i == 4) {
			if (numCars == 0) {
				cout << "No cars to display." << endl;
			}
			else {
				int carRec;
				cout << "Which car do you want to display (Record Number)?" << endl;
				cin >> carRec;
				cin.ignore(INT_MAX, '\n');
				
				// Track if a matching car was found
				bool found = false;
				
				// Loop through all allocated cars and display matching record ID
				// Fixed: Changed loop variable from i to j to avoid shadowing outer loop variable
				for (int j = 0; j < numCars; j++) {
					if (car[j] != nullptr) {
						// Properly check return value instead of semicolon after if
						if (car[j]->showSpeficData(carRec)) {
							found = true;
						}
					}
				}
				
				// If no matching car was found, display message once
				if (!found) {
					cout << "Car with record ID " << carRec << " not found." << endl;
				}
			}
		}
		
		// Option 5: Exit program and cleanup
		else if (i == 5) {
			// Delete all allocated car objects to free memory
			for (int k = 0; k < 3; k++) {
				if (car[k] != nullptr) {
					delete car[k];
					car[k] = nullptr;  // Set to nullptr after deletion
				}
			}
		}
		
		// Invalid menu selection
		else {
			cout << "Selection out of bounds." << endl;
		}
	}
	
	// Create a local car object and get its data
	cCar car1;
	car1.getCarData();
	
	// Pass car1 to ordinary function for processing
	ordinaryfunction(car1);
	
	// Display final car1 data
	cout << "car1 data:" << endl;
	car1.showCarData();

	system("pause");
	return 0;
}

// Function to display three cars (passed by value)
void displayCars(cCar one, cCar two, cCar three) {
	one.showCarData();
	two.showCarData();
	three.showCarData();
}

// Function to demonstrate copy constructor and mutation
void ordinaryfunction(cCar& cpy) {
	cout << "Inside ordinary function" << endl;
	
	// Create a local car using copy constructor
	cCar localCar(cpy);
	
	// Display car data before mutation
	cout << "Displaying local car data before:" << endl;
	localCar.showCarData();
	
	// Modify the local car data
	localCar.mutateAllData();
	
	// Display car data after mutation
	cout << "Displaying local car data after:" << endl;
	localCar.showCarData();
	
	// Display the original car data (should be unchanged)
	cout << "Displaying copy car data before:" << endl;
	cpy.showCarData();
}
