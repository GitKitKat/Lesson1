#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static int calcTCost()
{

	float tax = 0.05f;

	// prompt user for the number of items on the shopping list
	cout << "How many items do you want to calculate costs for? (max. 25): ";
	int groceries = 0;
	cin >> groceries;
	float gPrices[25];
	int gQuantity[25]; 
	int gTrack = 0;
	float gICost = 0;

	float gtotalCost = 0.0f;
	int gtotalItems = 0;

	string gAItems[50];
	char delimiter = ',';
	int index = 0;
	string items;

	// prompt user for the seperate items + costs
	for (int i = 0; i < groceries; i++) {
		cout << "Please enter the numerical price and quantity of item " << i+1 << " (price,quantity): ";
		cin >> items;

		// translates the collected string into an array
		istringstream stream(items);

		string token;

		while (getline(stream, token, delimiter)) {
			gAItems[index++] = token;
		}
	}

	// convert the collected string into variables to be used
	for (int i = 0; i < groceries; i++) {
		gPrices[i] = stof(gAItems[gTrack]);
		gQuantity[i] = stoi(gAItems[gTrack + 1]);
		gTrack += 2;
	}

	cout << "\n"; 

	for (int i = 0; i < groceries; i++) {
		cout << fixed;
		cout.precision(2);

		gICost = (gPrices[i] * gQuantity[i]) + (gPrices[i] * gQuantity[i] * tax);
		gtotalCost += gICost;
		gtotalItems += gQuantity[i];
		cout << "The total cost of item " << i+1 << ", including tax, is $" << gICost << "." << endl;
	}

	cout << "The overall cost is $" << gtotalCost << " for " << gtotalItems << " items." << endl;

	return 1;
}