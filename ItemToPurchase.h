#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
	public:
		//Default constructor
		ItemToPurchase(string itemName = "none", string itemDescription = "none", double itemPrice = 0.0, int itemQuantity = 0);
		void SetName(string nameToSet);
		string GetName();
		void SetDescription(string descriptionToSet);
		string GetDescription();
		void SetPrice(double priceToSet);
		double GetPrice();
		void SetQuantity(int quantityToSet);	
		int GetQuantity();
		string GetCost();
	private:
		string itemName;
		string itemDescription;
		double itemPrice;
		int itemQuantity;
};

#endif
