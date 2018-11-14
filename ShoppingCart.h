#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
	public:
		//Default constructor
		ShoppingCart(string customerName = "none", string cartDate = "none");
		string GetCustomer();
		string GetDate();
		void AddItem(ItemToPurchase newItem);
		void RemoveItem(string nameToRemove);
		void UpdateItem(string nameToUpdate, int newQuantity);
		int GetNumItems();
		double GetTotCost();
		void PrintDescriptions();
		void PrintCart();

	private:
		string customerName;
		string cartDate;
		vector<ItemToPurchase> itemsList;
};

#endif
