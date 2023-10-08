#pragma once
class Bond
{
private:
	double yield;
	int maturity;
	double FV;
	double couponRate;

public:
	Bond(double y, int m, double fv = 100.0, double cRate = 0.0);

	double price() const;
	int getMaturity() const;
	double getYield() const;

	double computeSensitivity(double delta_yield) const;



};

