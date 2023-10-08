#pragma once
class Bond
{
private:
	double yield;
	int maturity;
	double FV;

public:
	Bond(double y, int m, double fv = 100.0);

	double price() const;
	int getMaturity() const;
	double getYield() const;

	double computeSensitivity(double delta_yield) const;


};

