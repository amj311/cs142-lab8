#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

ShoppingCart::ShoppingCart(string initialName, string initialDate) {
	customerName = initialName;
	cartDate = initialDate;
}

string ShoppingCart::GetCustomer() {
	return customerName;
}

string ShoppingCart::GetDate() {
	return cartDate;
}

void ShoppingCart::AddItem(ItemToPurchase newItem) {
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList.at(i).GetName() == newItem.GetName()) {
			cout << "Item is already in cart. Nothing added." << endl;
			return;
		}
	}
	itemsList.push_back(newItem);

	return;
	
}

void ShoppingCart::RemoveItem(string nameToRemove) {
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList.at(i).GetName() == nameToRemove) {
			itemsList.erase(itemsList.begin() + i);
			return;
		}
	}
	cout << "Item not found in cart. Nothing removed." << endl;

	return;
}

void ShoppingCart::UpdateItem(string nameToUpdate, int newQuantity) {
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList.at(i).GetName() == nameToUpdate) {
			itemsList.at(i).SetQuantity(newQuantity);
			return;
		}
	}
	cout << "Item not found in cart. Nothing modified." << endl;

	return;
}

int ShoppingCart::GetNumItems() {
	int totalItems = 0;

	for (int i = 0; i < itemsList.size(); i++) {
		totalItems += itemsList.at(i).GetQuantity();
	}

	return totalItems;
}

double ShoppingCart::GetTotCost() {
	double totalCost = 0;

	for (int i = 0; i < itemsList.size(); i++) {
		totalCost += itemsList.at(i).GetQuantity()*itemsList.at(i).GetPrice();
	}

	return totalCost;
}

void ShoppingCart::PrintDescriptions() {
	cout << customerName << "'s Shopping Cart - " << cartDate << endl;

	if(itemsList.size() > 0) {
		cout << "Item Descriptions" << endl;
		for (int i = 0; i < itemsList.size(); i++) {
			cout << itemsList.at(i).PrintDescription() << endl;
		}
	}
	else {
		cout << "Shopping cart is empty." << endl;
	}
	
	cout << endl;

	return;
}

void ShoppingCart::PrintCart() {
	cout << customerName << "'s Shopping Cart - " << cartDate << endl;

	if (itemsList.size() > 0) {
		cout << "Number of Items: " << GetNumItems() << endl << endl;
		for (int i = 0; i < itemsList.size(); i++) {
			cout << itemsList.at(i).PrintCost() << endl;
		}
		cout << endl
			<< fixed << setprecision(2) << "Total: $" << GetTotCost() << endl << endl;
	}
	else {
		cout << "Shopping cart is empty." << endl;
	}

	return;
}
