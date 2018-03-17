#pragma once
#include "GroceryItem.h"
class Produce : public GroceryItem {
public:
	Produce(double weight, const char * description, double costPerPound) : GroceryItem(weight * costPerPound, weight
		, description) {}
};