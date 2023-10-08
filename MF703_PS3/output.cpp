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
			case 'd':questionD(); break;
			case 'e':questionE(); break;
			case 'f':questionF(); break;
			case 'g':questionG(); break;
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

int questionD() {
	std::vector<Bond> bonds = {
		Bond(0.055, 1, 100, 0.05),
		Bond(0.052, 2, 100, 0.05),
		Bond(0.05, 3, 100, 0.05),
		Bond(0.047, 5, 100, 0.05),
		Bond(0.046, 10, 100, 0.05),
		Bond(0.048, 30 , 100, 0.05)
	};

	// Zero-coupon bonds for comparison
	std::vector<Bond> zeroCouponBonds = {
		Bond(0.055, 1, 100),
		Bond(0.052, 2, 100),
		Bond(0.05, 3, 100),
		Bond(0.047, 5, 100),
		Bond(0.046, 10, 100),
		Bond(0.048, 30, 100)
	};

	double deltaYield = 0.01;

	std::cout << "Modified Durations for Coupon Bonds:" << std::endl;
	for (auto& bond : bonds) {
		double duration = bond.modifiedDuration(deltaYield);
		std::cout << "Maturity: " << bond.getMaturity() << " years. "
			<< "Duration: " << duration << " years." << std::endl;
	}

	std::cout << "\nModified Durations for Zero-Coupon Bonds:" << std::endl;
	for (auto& bond : zeroCouponBonds) {
		double duration = bond.modifiedDuration(deltaYield);
		std::cout << "Maturity: " << bond.getMaturity() << " years. "
			<< "Duration: " << duration << " years." << std::endl;
	}

	std::cout << "\nIn general, all else equal, zero-coupon bonds tend to have higher durations than coupon bonds. This is because with zero-coupon bonds, all cash flows (the bond's face value) are received at maturity, making them more sensitive to interest rate changes. For coupon bonds, cash flows are received periodically, reducing their sensitivity to interest rate changes." << std::endl;

	return 0;
}

int questionE() {
	std::vector<Bond> bonds = {
	Bond(0.055, 1, 100, 0.05),
	Bond(0.052, 2, 100, 0.05),
	Bond(0.05, 3, 100, 0.05),
	Bond(0.047, 5, 100, 0.05),
	Bond(0.046, 10, 100, 0.05),
	Bond(0.048, 30 , 100, 0.05)
	};

	double deltaYield = 0.01; 

	std::cout << "Convexities:" << std::endl;
	for (auto& bond : bonds) {
		double conv = bond.convexity(deltaYield);
		std::cout << "Maturity: " << bond.getMaturity() << " years. "
			<< "Convexity: " << conv << std::endl;
	}

	std::cout << "\nTypically, the convexities of bonds are positive. This means that bond prices increase at an accelerating rate as yields fall and decrease at a decelerating rate as yields rise." << std::endl;

	return 0;
}

int questionF() {
	Bond bond1(0.055, 1, 100);  // 1-year zero-coupon bond
	Bond bond2(0.052, 2, 100);  // 2-year zero-coupon bond
	Bond bond3(0.05, 3, 100);   // 3-year zero-coupon bond

	double portfolioValue = bond1.price() - 2 * bond2.price() + bond3.price();

	std::cout << "The initial value of the portfolio is: $" << portfolioValue << std::endl;

	return 0;
}

int questionG() {
	Bond bond1(0.055, 1, 100);  // 1-year zero-coupon bond
	Bond bond2(0.052, 2, 100);  // 2-year zero-coupon bond
	Bond bond3(0.05, 3, 100);   // 3-year zero-coupon bond

	double deltaYield = 0.01;

	double value1 = bond1.price();
	double value2 = -2 * bond2.price();
	double value3 = bond3.price();

	double portfolioValue = value1 + value2 + value3;

	double weights1 = value1 / portfolioValue;
	double weights2 = value2 / portfolioValue;
	double weights3 = value3 / portfolioValue;

	double portfolioDuration = weights1 * bond1.modifiedDuration(deltaYield) + 
								weights2 * bond2.modifiedDuration(deltaYield) + 
								weights3 * bond3.modifiedDuration(deltaYield);

	double portfolioConvexity = weights1 * bond1.convexity(deltaYield) +
								weights2 * bond2.convexity(deltaYield) +
								weights3 * bond3.convexity(deltaYield);


	std::cout << "The duration of the portfolio is: " << portfolioDuration << " years." << std::endl;
	std::cout << "The convexity of the portfolio is: " << portfolioConvexity << std::endl;

	if (portfolioDuration > portfolioConvexity) {
		std::cout << "The duration is bigger than the convexity." << std::endl;
	}
	else if (portfolioDuration < portfolioConvexity) {
		std::cout << "The convexity is bigger than the duration." << std::endl;
	}
	else {
		std::cout << "The duration and convexity are equal." << std::endl;
	}

	return 0;
}