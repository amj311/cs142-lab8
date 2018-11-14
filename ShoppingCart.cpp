#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

ShoppingCart::ShoppingCart(string customerName, string cartDate) {
	this->customerName = customerName;
	this->cartDate = cartDate;
}

string ShoppingCart::GetCustomer() {
	return this->customerName;
}

string ShoppingCart::GetDate() {
	return this->cartDate;
}

void ShoppingCart::AddItem(ItemToPurchase newItem) {
	for (int i = 0; i < this->itemsList.size(); i++) {
		if (this->itemsList.at(i).GetName() == newItem.GetName()) {
			cout << "Item is already in cart. Nothing added." << endl;
			return;
		}
	}
	this->itemsList.push_back(newItem);

	return;
	
}

void ShoppingCart::RemoveItem(string nameToRemove) {
	for (int i = 0; i < this->itemsList.size(); i++) {
		if (this->itemsList.at(i).GetName() == nameToRemove) {
			this->itemsList.erase(itemsList.begin() + i);
			return;
		}
	}
	cout << "Item not found in cart. Nothing removed." << endl;

	return;
}

void ShoppingCart::UpdateItem(string nameToUpdate, int newQuantity) {
	for (int i = 0; i < this->itemsList.size(); i++) {
		if (this->itemsList.at(i).GetName() == nameToUpdate) {
			this->itemsList.at(i).SetQuantity(newQuantity);
			return;
		}
	}
	cout << "Item not found in cart. Nothing modified." << endl;

	return;
}

int ShoppingCart::GetNumItems() {
	int totalItems = 0;

	for (int i = 0; i < this->itemsList.size(); i++) {
		totalItems += itemsList.at(i).GetQuantity();
	}

	return totalItems;
}

double ShoppingCart::GetTotCost() {
	double totalCost = 0;

	for (int i = 0; i < this->itemsList.size(); i++) {
		totalCost += this->itemsList.at(i).GetQuantity()*itemsList.at(i).GetPrice();
	}

	return totalCost;
}

void ShoppingCart::PrintDescriptions() {
	cout << this->customerName << "'s Shopping Cart - " << this->cartDate << endl;

	if(this->itemsList.size() > 0) {
		cout << "Item Descriptions" << endl;
		for (int i = 0; i < this->itemsList.size(); i++) {
			cout << this->itemsList.at(i).GetDescription() << endl;
		}
	}
	else {
		cout << "Shopping cart is empty." << endl;
	}
	
	cout << endl;

	return;
}

void ShoppingCart::PrintCart() {
	cout << this->customerName << "'s Shopping Cart - " << this->cartDate << endl;

	if (this->itemsList.size() > 0) {
		cout << "Number of Items: " << this->GetNumItems() << endl << endl;
		for (int i = 0; i < this->itemsList.size(); i++) {
			cout << this->itemsList.at(i).GetCost() << endl;
		}
		cout << endl
			<< fixed << setprecision(2) << "Total: $" << this->GetTotCost() << endl << endl;
	}
	else {
		cout << "Shopping cart is empty." << endl;
	}

	return;
}
