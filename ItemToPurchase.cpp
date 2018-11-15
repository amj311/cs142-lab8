#include "ItemToPurchase.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;


ItemToPurchase::ItemToPurchase(string initialName, string initialDescription, double initialPrice, int initialQuantity) {
	itemName = initialName;
	itemDescription = initialDescription;
	itemPrice = initialPrice;
	itemQuantity = initialQuantity;
}

void ItemToPurchase::SetName(string nameToSet) {
	itemName = nameToSet;
}

string ItemToPurchase::GetName() {
	return itemName;
}

void ItemToPurchase::SetDescription(string descriptionToSet) {
	itemDescription = descriptionToSet;
}

string ItemToPurchase::GetDescription() {
	return itemDescription;
}

void ItemToPurchase::SetPrice(double priceToSet) {
	itemPrice = priceToSet;
}

double ItemToPurchase::GetPrice() {
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantityToSet) {
	itemQuantity = quantityToSet;
}

int ItemToPurchase::GetQuantity() {
	return itemQuantity;
}

string ItemToPurchase::PrintCost() {
	ostringstream outString;

	outString << fixed << setprecision(2)
		<< itemName
		<< " " << itemQuantity
		<< " @ $"  << itemPrice
		<< " = $" << itemQuantity*itemPrice;

	return outString.str();
}

string ItemToPurchase::PrintDescription() {
	return GetName() + ": " + GetDescription();
}
