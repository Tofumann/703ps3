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
			case 'h':questionH(); break;
			case 'i':questionI(); break;
			case 'j':questionJ(); break;
			case 'k':questionK(); break;
			case 'l':questionL(); break;
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
	Bond bond1(0.055, 1, 100);  
	Bond bond2(0.052, 2, 100);  
	Bond bond3(0.05, 3, 100);   

	double portfolioValue = bond1.price() - 2 * bond2.price() + bond3.price();

	std::cout << "The initial value of the portfolio is: $" << portfolioValue << std::endl;

	return 0;
}

int questionG() {
	Bond bond1(0.055, 1, 100);  
	Bond bond2(0.052, 2, 100);  
	Bond bond3(0.05, 3, 100);   

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

int questionH() {
	Bond bond1(0.055, 1, 100);
	Bond bond2(0.052, 2, 100);
	Bond bond3(0.05, 3, 100);

	double deltaYield = 0.01;  

	double value1 = bond1.price();
	double value3 = bond3.price();

	double D1 = bond1.modifiedDuration(deltaYield);
	double D3 = bond3.modifiedDuration(deltaYield);
	double D2 = bond2.modifiedDuration(deltaYield);

	// Solve for x (number of units of bond2) such that portfolio duration is zero
	// Dp = w1*D1 + x*w2*D2 + w3*D3 = 0
	double x = (-value1 * D1 - value3 * D3) / (bond2.price() * D2);

	std::cout << "To make the portfolio duration neutral, " << x << " units of the 2-year zero-coupon bond are required." << std::endl;

	return 0;
}

int questionI() {

	int basisPoints = 100;

	double yieldChanged = static_cast<double>(basisPoints) / 10000.0;

	Bond bond1(0.055 + yieldChanged, 1, 100);
	Bond bond2(0.052 + yieldChanged, 2, 100);
	Bond bond3(0.05 + yieldChanged, 3, 100);

	Bond prevBond1(0.055, 1, 100);
    Bond prevBond3(0.05, 3, 100);
    Bond prevBond2(0.052, 2, 100);

	double value1 = prevBond1.price();
	double value3 = prevBond3.price();
	
	double Duration1 = prevBond1.modifiedDuration(yieldChanged);
	double Duration3 = prevBond3.modifiedDuration(yieldChanged);
	double Duration2 = prevBond2.modifiedDuration(yieldChanged);

	double x = (-value1 * Duration1 - value3 * Duration3) / 
					(prevBond2.price() * Duration2);

	double initialValue = value1 + value3 - x* prevBond2.price();

	double adjustedValue1 = bond1.price();
	double adjustedValue2 = bond2.price() * x;
	double adjustedValue3 = bond3.price();

	double finalPortfolioValue = adjustedValue1 - adjustedValue2 + adjustedValue3;

	std::cout << "Initial portfolio value: $" << initialValue << std::endl;
	std::cout << "Final portfolio value after the rates sell off by " << basisPoints << " basis points: $" << finalPortfolioValue << std::endl;
	std::cout << "Change in portfolio value: $" << (finalPortfolioValue - initialValue) << std::endl;

	return 0;
}

int questionJ() {
	int basisPoints = 100;

	double yieldChanged = -static_cast<double>(basisPoints) / 10000.0;

	Bond bond1(0.055 + yieldChanged, 1, 100);
	Bond bond2(0.052 + yieldChanged, 2, 100);
	Bond bond3(0.05 + yieldChanged, 3, 100);

	Bond prevBond1(0.055, 1, 100);
	Bond prevBond3(0.05, 3, 100);
	Bond prevBond2(0.052, 2, 100);

	double value1 = prevBond1.price();
	double value3 = prevBond3.price();

	double Duration1 = prevBond1.modifiedDuration(yieldChanged);
	double Duration3 = prevBond3.modifiedDuration(yieldChanged);
	double Duration2 = prevBond2.modifiedDuration(yieldChanged);

	double x = (-value1 * Duration1 - value3 * Duration3) /
		(prevBond2.price() * Duration2);

	double initialValue = value1 + value3 - x * prevBond2.price();

	double adjustedValue1 = bond1.price();
	double adjustedValue2 = bond2.price() * x;
	double adjustedValue3 = bond3.price();

	double finalPortfolioValue = adjustedValue1 - adjustedValue2 + adjustedValue3;

	std::cout << "Initial portfolio value: $" << initialValue << std::endl;
	std::cout << "Final portfolio value after the rates rally by " << basisPoints <<" basis points: $" << finalPortfolioValue << std::endl;
	std::cout << "Change in portfolio value: $" << (finalPortfolioValue - initialValue) << std::endl;

	// Answer to "Is this a portfolio you would want to own?"
	std::cout << "\nOwning this portfolio depends on one's risk appetite and market expectations. If one expects rates to decrease, this portfolio might be beneficial. However, any unexpected rise in rates can result in losses.";

	// Risks of owning this portfolio
	std::cout << "\nRisks of owning this portfolio include interest rate risk, reinvestment risk, and potential opportunity cost if the market doesn't move as anticipated." << std::endl;

	return 0;
}

int questionK() {

	Bond bond(0.047, 5, 100, 0.05, true, 0.20);

	std::vector<double> cashflows = bond.getAmortizingCashflows();

	std::cout << "Cashflows for a 5-year amortizing bond:" << std::endl;
	for (size_t i = 0; i < cashflows.size(); i++) {
		std::cout << "Year " << (i + 1) << ": $" << cashflows[i] << std::endl;
	}

	return 0;
}

int questionL() {
	Bond zeroCouponBond(0.047, 5, 100);
	Bond couponBond(0.047, 5, 100, 0.05);
	Bond amortizingBond(0.047, 5, 100, 0.05, true, 0.20);

	double deltaYield = 0.01;

	double zeroCouponPrice = zeroCouponBond.price();
	double couponBondPrice = couponBond.price();
	double amortizingBondPrice = amortizingBond.price();

	double zeroCouponDuration = zeroCouponBond.modifiedDuration(deltaYield);
	double couponBondDuration = couponBond.modifiedDuration(deltaYield);
	double amortizingBondDuration = amortizingBond.modifiedDuration(deltaYield);

	std::cout << "Zero Coupon Bond - Price: $" << zeroCouponPrice << ", Duration: " << zeroCouponDuration << " years" << std::endl;
	std::cout << "Coupon Bond - Price: $" << couponBondPrice << ", Duration: " << couponBondDuration << " years" << std::endl;
	std::cout << "Amortizing Bond - Price: $" << amortizingBondPrice << ", Duration: " << amortizingBondDuration << " years" << std::endl;

	std::cout << "\nComments:" << std::endl;
	std::cout << "1. The zero-coupon bond has its entire cash flow at maturity, so its duration is simply its maturity." << std::endl;
	std::cout << "2. The coupon bond has intermediate cash flows in the form of coupons, which causes its duration to be less than its maturity." << std::endl;
	std::cout << "3. The amortizing bond repays principal over time. Its duration will be between the zero-coupon and coupon bonds, as it has both intermediate and maturity cash flows." << std::endl;



	return 0;
}