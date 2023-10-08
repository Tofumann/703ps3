#include "Bond.h"
#include <cmath>



Bond::Bond(double y, int m, double fv) {
	yield = y;
	maturity = m;
	FV = fv;
}

double Bond::price() const {
	return FV / std::pow(1 + yield, maturity);
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

