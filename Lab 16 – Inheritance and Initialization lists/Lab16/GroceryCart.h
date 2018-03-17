//
//  GroceryCart.h
//  Lab 16
//

#ifndef __Lab_16__GroceryCart__
#define __Lab_16__GroceryCart__

#include <iostream>
#include <vector>
#include "GroceryItem.h"

class GroceryCart {
public:
	GroceryCart() {}  // default constructor
	~GroceryCart();

	// Rule of 3: prevent use of copy, assign
	GroceryCart(const GroceryCart&) = delete;
	GroceryCart &operator=(const GroceryCart&) = delete;
	// Rule of 5: prevent use of move and move assign
	GroceryCart(const GroceryCart&&) = delete;
	GroceryCart &operator=(const GroceryCart&&) = delete;

	void AddItemToCart(GroceryItem *i);
	std::ostream &print(std::ostream &out) const;
private:
	std::vector<GroceryItem *> items;
};

std::ostream &operator<<(std::ostream &out, const GroceryCart &c);

#endif /* defined(__Lab_16_solution__GroceryCart__) */