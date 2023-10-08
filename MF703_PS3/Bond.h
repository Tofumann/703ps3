#pragma once
class Bond
{
private:
	double yield;
	int maturity;
	double FV;

public:
	Bond(double y, int m, double fv);

	double price() const;
	int getMaturity() const;
	double getYield() const;
};

