#include "Bond.h"
#include <cmath>
#include <vector>



Bond::Bond(double y, int m, double fv, double cRate, bool isAmortizing, double principalRepayment) {
	yield = y;
	maturity = m;
	FV = fv;
	couponRate = cRate;
	isAmortizing_ = isAmortizing;
	principleRepayment_ = principalRepayment;
}

std::vector<double> Bond::getAmortizingCashflows() const {
	std::vector<double> cashflows;

	if (!isAmortizing_) {
		return cashflows;
	}

	double remainingPrincipal = FV;
	for (int i = 1; i <= maturity; i++) {
		double couponPayment = couponRate * FV;
		double principalPayment = std::min(remainingPrincipal, FV * principleRepayment_);

		cashflows.push_back(couponPayment + principalPayment);

		remainingPrincipal -= principalPayment;
	}
	return cashflows;

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

double Bond::computeSensitivity(double deltaYield) const {
	Bond bondDecreasedYield(yield - deltaYield, maturity, FV);
	Bond bondIncreasedYield(yield + deltaYield, maturity, FV);

	double priceDecreasedYield = bondDecreasedYield.price();
	double priceIncreasedYield = bondIncreasedYield.price();

	return (priceDecreasedYield - priceIncreasedYield) / (2.0 * deltaYield);
}

double Bond::modifiedDuration(double deltaYield) const {
	Bond bondUp(yield + deltaYield, maturity, FV, couponRate);
	Bond bondDown(yield - deltaYield, maturity, FV, couponRate);

	double priceUp = bondUp.price(); 
	double priceDown = bondDown.price();

	return (priceDown - priceUp) / (2 * this->price() * deltaYield);

}

double Bond::convexity(double deltaYield) const {
	Bond bondUp(yield + deltaYield, maturity, FV, couponRate);
	Bond bondDown(yield - deltaYield, maturity, FV, couponRate);

	double priceUp = bondUp.price();
	double priceDown = bondDown.price();
	double inititalPrice = this-> price();

	return (priceDown + priceUp - 2 * inititalPrice) / (inititalPrice * std::pow(deltaYield, 2));
}

int Bond::getMaturity() const {
	return maturity;
}

double Bond::getYield() const {
	return yield;
}

