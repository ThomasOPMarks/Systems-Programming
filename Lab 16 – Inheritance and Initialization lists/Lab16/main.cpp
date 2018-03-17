//
//  main.cpp
//  Lab 16
//

#include <iostream>
#include "GroceryCart.h"


#include "Onions.h"
#include "Apples.h"
#include "Poptarts.h"

int main(int argc, const char * argv[])
{
	GroceryCart c;
	c.AddItemToCart(new Apples(.2)); // Weight in lbs (Apples is $9.89/lb)
	c.AddItemToCart(new Onions(4.3));  // Weight in lbs (Celery is $9.09/lb)
	c.AddItemToCart(new Poptarts);
	std::cout << c;
	return 0;
}
