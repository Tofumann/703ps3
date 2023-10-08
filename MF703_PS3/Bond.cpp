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

int Bond::getMaturity() const {
	return maturity;
}

double Bond::getYield() const {
	return yield;

}

