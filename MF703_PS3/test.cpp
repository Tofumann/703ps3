#pragma once
#include "Bond.h"
#include <iostream>
#include <vector>


int questionA();
int questionB();
int questionC();
int questionD();
int questionE();
int questionF();
int questionG();
int questionH();
int questionI();
int questionJ();
int questionK();
int questionL();

int main() {
	int choice;

	while (true) {
		std::cout << "run (a-l) question or 0 to quit: ";
		char option;
		std::cin >> option;


		switch (option) {
			case 'a':questionA(); break;
			case 'b':questionB(); break;
			case 'c':questionC(); break;
			case '0': return 0;
			default:std::cout << "Invalid option. Try again." << std::endl;
		}
	}
}

int questionA() {
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

int questionB() {
	std::vector<Bond> bonds = {
		Bond(0.055, 1, 100),
		Bond(0.052, 2, 100),
		Bond(0.05, 3, 100),
		Bond(0.047, 5, 100),
		Bond(0.046, 10, 100),
		Bond(0.048, 30 , 100)
	};

	double delta_yield = 0.0001;

	for (const auto& bond : bonds) {
		double sensitivity = bond.computeSensitivity(delta_yield);
		std::cout << "Maturity: " << bond.getMaturity() << " years. "
			<< "Yield: " << bond.getYield() << ". "
			<< "Sensitivity: " << sensitivity << std::endl;
	}

	std::cout << "\nBond Prices and bond yields have an inverse relationship. As yields rise, bond prices fall and vice versa." << std::endl;
	return 0;
}

int questionC() {
	std::vector<Bond> bonds = {
		Bond(0.055, 1, 100, 0.05),
		Bond(0.052, 2, 100, 0.05),
		Bond(0.05, 3, 100, 0.05),
		Bond(0.047, 5, 100, 0.05),
		Bond(0.046, 10, 100, 0.05),
		Bond(0.048, 30 , 100, 0.05)
	};

	std::vector<Bond> above100;
	std::vector<Bond> below100;

	for (const auto& bond : bonds) {
		double current_price = bond.price();
		std::cout << "Maturity: " << bond.getMaturity() << " years. "
			<< "Yield: " << bond.getYield() << ". "
			<< "Bond Price: $" << current_price << std::endl;
		if (current_price > 100) {
			above100.push_back(bond);
		}
		else {
			below100.push_back(bond);
		}
	}

	std::cout << "\nBonds priced above $100:" << std::endl;
	for (auto& bond : above100) {
		std::cout << "Maturity: " << bond.getMaturity() << " years." << std::endl;
	}

	std::cout << "\nBonds priced below $100:" << std::endl;
	for (auto& bond : below100) {
		std::cout << "Maturity: " << bond.getMaturity() << " years." << std::endl;
	}

	std::cout << "\nPrices differ based on the present value of future cash flows. Bonds yielding closer to the coupon rate tend to be priced near par ($100). Bonds with a yield greater than the coupon rate will be priced below par and vice versa." << std::endl;

	return 0;
}