#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void ValidGetLine(string& targetStr, const string promptStr, const string failStr) {
	cout << promptStr << endl;
	getline(cin, targetStr);
	if (targetStr == "" || targetStr == " ") {
		getline(cin, targetStr);
	}

	while (cin.fail()) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetStr;
	}

	return;
}

//Input cin for strings
void ValidCin(string& targetStr, const string promptStr, const string failStr) {
	cout << promptStr;
	cin >> targetStr;
	cout << endl;

	while (cin.fail()) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetStr;
	}

	return;
}

//Input cin for integers
void ValidCin(int& targetInt, const string promptStr, const string failStr, const int minInt = 0, const int maxInt = 0) {
	cout << promptStr;
	cin >> targetInt;
	cout << endl;

	while (cin.fail() || targetInt < minInt || (maxInt != 0 && targetInt > maxInt)) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetInt;
	}

	return;
}
//Input cin for doubles
void ValidCin(double& targetDouble, const string promptStr, const string failStr, const double minDouble = 0, const double maxDouble = 0) {
	cout << promptStr;
	cin >> targetDouble;
	cout << endl;

	while (cin.fail() || targetDouble < minDouble || (maxDouble != 0 && targetDouble > maxDouble)) {
		// Clear error state
		cin.clear();

		// Ignore characters in stream until newline
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << failStr << endl << endl;
		cout << promptStr;
		cin >> targetDouble;
	}

	return;
}

int main() {
	string customerName = "";
	string cartDate = "";
	string userTask = "";

	ValidGetLine(customerName, "Enter Customer's Name: ", "Invalid");
	ValidGetLine(cartDate, "Enter Today's Date: ", "Invalid");

	ShoppingCart myCart(customerName, cartDate);

	cout << "Enter option: ";
	cin >> userTask;
	cout << endl;

	while (userTask != "quit") {
		if (userTask == "add") {
			string newItemName;
			string newItemDescription;
			double newItemPrice;
			int newItemQuantity;

			ValidGetLine(newItemName, "Enter the item name: ", "Invalid.");
			ValidGetLine(newItemDescription, "Enter the item Description: ", "Invalid.");
			ValidCin(newItemPrice, "Enter the item Price: ", "Invalid.");
			ValidCin(newItemQuantity, "Enter the item Quantity: ", "Invalid.");

			ItemToPurchase newItem = ItemToPurchase(newItemName, newItemDescription, newItemPrice, newItemQuantity);
			myCart.AddItem(newItem);

			cout << endl;
		}
		else if (userTask == "remove") {
			string nameToRemove;

			ValidGetLine(nameToRemove, "Enter name of the item to remove: ", "Invalid.");

			myCart.RemoveItem(nameToRemove);

			cout << endl;
		}
		else if (userTask == "change") {
			string nameOfItem;
			int newQuantity;

			ValidGetLine(nameOfItem, "Enter the item name: ", "Invalid.");
			ValidCin(newQuantity, "Enter the new quantity: ", "Invalid.");

			myCart.UpdateItem(nameOfItem, newQuantity);

			cout << endl;
		}
		else if (userTask == "descriptions") {
			myCart.PrintDescriptions();
		}
		else if (userTask == "cart") {
			myCart.PrintCart();
		}
		else {
			cout << "MENU" << endl
				<< "add - Add item to cart" << endl
				<< "remove - Remove item from cart" << endl
				<< "change - Change item quantity" << endl
				<< "descriptions - Output items' descriptions" << endl
				<< "cart - Output shopping cart" << endl
				<< "options - Print the options menu" << endl
				<< "quit - Quit" << endl
				<< endl;
		}

		cout << "Enter option: ";
		cin >> userTask;
		cout << endl;

	}

	cout << "Goodbye." << endl;

	return 0;
}