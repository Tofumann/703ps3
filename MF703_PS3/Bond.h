#pragma once
#include <vector>
class Bond
{
private:
	double yield;
	int maturity;
	double FV;
	double couponRate;
	bool isAmortizing_;
	double principleRepayment_;

public:
	Bond(double y, int m, double fv = 100.0, double cRate = 0.0, bool isAmortizing = false, double principleRepayment = 0.0);


	double price() const;
	int getMaturity() const;
	double getYield() const;
	

	double computeSensitivity(double deltaYield) const;
	double modifiedDuration(double deltaYield) const;

	double convexity(double deltaYield) const;

	std::vector<double> getAmortizingCashflows() const;



};

