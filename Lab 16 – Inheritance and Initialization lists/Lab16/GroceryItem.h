#pragma once

class GroceryItem {
public:
	GroceryItem(double p, double w, const char* d) : price(p), weight(w), description(d) {}
	char* GetDescription();
	double GetPrice();
	double GetWeight();
private:
	double weight;
	double price;
	const char* description;
};
