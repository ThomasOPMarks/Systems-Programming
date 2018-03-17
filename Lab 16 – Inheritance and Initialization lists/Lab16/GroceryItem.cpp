#define _CRT_SECURE_NO_WARNINGS
#include "GroceryItem.h"
#include <string.h>
#pragma disable(warning : 4996)


char * GroceryItem::GetDescription()
{
	char* temp = new char[strlen(this->description)];
	return strcpy(temp, this->description);
}

double GroceryItem::GetPrice()
{
	return this->price;
}

double GroceryItem::GetWeight()
{
	return this->weight;
}
