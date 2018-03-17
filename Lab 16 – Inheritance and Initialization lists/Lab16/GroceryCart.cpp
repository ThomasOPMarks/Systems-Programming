//
//  GroceryCart.cpp
//  Lab16
//

#include "GroceryCart.h"
#include <iomanip>

GroceryCart::~GroceryCart() {
	// Delete items in cart
	for (auto &i : items) {
		delete i;
		i = nullptr;
	}
}

void GroceryCart::AddItemToCart(GroceryItem *i)
{
	items.push_back(i);
}

std::ostream &GroceryCart::print(std::ostream &out) const
{
	double total = 0;
	for (auto x : items)
	{
		out << " " << std::fixed << std::setprecision(2)
			<< x->GetPrice() << "\t" << x->GetDescription() << "\n";
		total += x->GetPrice();
	}
	out << "-------\n$" << total << std::endl;
	return out;
}

std::ostream &operator<<(std::ostream &out, const GroceryCart &c)
{
	return c.print(out);
}