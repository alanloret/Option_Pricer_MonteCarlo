#pragma once
#include <vector>
class BlackScholesModel
{
public:
	BlackScholesModel();
	BlackScholesModel(double const& S, double const& r, double const& v);

	double generatePrice(double const& T) const;
	void generatePath(double const& T, std::vector<double>& prices) const;

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

