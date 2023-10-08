#include "Bond.h"
#include <cmath>



Bond::Bond(double y, int m, double fv, double cRate) {
	yield = y;
	maturity = m;
	FV = fv;
	couponRate = cRate;
}

double Bond::price() const {

	double couponPayment = couponRate * FV;
	double totalValue = 0;

	for (int i = 1; i <= maturity; i++) {
		totalValue += couponPayment / std::pow(1 + yield, i);
	}

	totalValue += FV / std::pow(1 + yield, maturity);

	return totalValue;
}

double Bond::computeSensitivity(double delta_yield) const {
	Bond bondDecreasedYield(yield - delta_yield, maturity, FV);
	Bond bondIncreasedYield(yield + delta_yield, maturity, FV);

	double priceDecreasedYield = bondDecreasedYield.price();
	double priceIncreasedYield = bondIncreasedYield.price();

	return (priceDecreasedYield - priceIncreasedYield) / (2.0 * delta_yield);
}




int Bond::getMaturity() const {
	return maturity;
}

double Bond::getYield() const {
	return yield;

}

