#include "ItemToPurchase.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;


ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity) {
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetName(string nameToSet) {
	this->itemName = nameToSet;
}

string ItemToPurchase::GetName() {
	return this->itemName;
}

void ItemToPurchase::SetDescription(string descriptionToSet) {
	this->itemDescription = descriptionToSet;
}

string ItemToPurchase::GetDescription() {
	return this->itemName + ": " + this->itemDescription;
}

void ItemToPurchase::SetPrice(double priceToSet) {
	this->itemPrice = priceToSet;
}

double ItemToPurchase::GetPrice() {
	return this->itemPrice;
}

void ItemToPurchase::SetQuantity(int quantityToSet) {
	this->itemQuantity = quantityToSet;
}

int ItemToPurchase::GetQuantity() {
	return this->itemQuantity;
}

string ItemToPurchase::GetCost() {
	ostringstream outString;

	outString << fixed << setprecision(2)
		<< this->itemName
		<< " " << this->itemQuantity
		<< " @ $"  << this->itemPrice
		<< " = $" << this->itemQuantity*this->itemPrice;

	return outString.str();
}