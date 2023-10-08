#pragma once
#include "Bond.h"
#include <iostream>
#include <vector>

int main() {
	std::vector<Bond> bonds = {
		Bond(0.055, 1, 100),
		Bond(0.052, 2, 100),
		Bond(0.05, 3, 100),
		Bond(0.047, 5, 100),
		Bond(0.046, 10, 100),
		Bond(0.048, 30 , 100)
	};

	double highest_price = 0;
	Bond* highest_bond = nullptr;

	for (auto& bond : bonds) {
		double current_price = bond.price();
		std::cout << "Maturity: " << bond.getMaturity() << " years. "
				<< "Yield: " << bond.getYield() << ". "
				<< "Bond Price: $" << current_price << std::endl;

		if (current_price > highest_price) {
			highest_price = current_price;
			highest_bond = &bond;
		}
	}
	std::cout << "\nHighest bond price is for " << highest_bond->getMaturity()
		<< " years at $" << highest_price << std::endl;

	std::cout << "\nYes, it's reasonable. Shorter maturity typically results in a higher bond price due to less discounting from the yield. Hence, the 1-year bond has the highest price." << std::endl;


	return 0;
}


