
#pragma once
class BlackScholesModel
{
public:
	BlackScholesModel();
	BlackScholesModel(double const& S, double const& r, double const& v);

	double generatePrice(double const& T) const;

	double getStartingPrice() const;
	double getRiskFreeRate() const;
	double getVolatility() const;
	void print() const;

private:
	double gaussian_box_muller() const;

	double S;
	double r;
	double v;
};
