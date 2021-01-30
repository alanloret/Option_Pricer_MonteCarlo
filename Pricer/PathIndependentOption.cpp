#include "PathIndependentOption.h"
#include <iostream>

PathIndependentOption::PathIndependentOption()
{
	Option();
}

PathIndependentOption::PathIndependentOption(double const& K, double const& T)
{
	Option(K, T);
}

bool PathIndependentOption::isPathDependent() const
{
	return pathDependent;
}

double PathIndependentOption::payoff(double const& S) const
{
	return 0.0;
}

double PathIndependentOption::payoff(std::vector<double> prices_vector) const
{
	return 0.0;
}

PathIndependentOption::~PathIndependentOption()
{
}
