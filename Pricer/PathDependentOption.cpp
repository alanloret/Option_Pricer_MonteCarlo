#include "PathDependentOption.h"
#include <iostream>

PathDependentOption::PathDependentOption()
{
	Option();
}

PathDependentOption::PathDependentOption(double const& K, double const& T)
{
	Option(K, T);
}

bool PathDependentOption::isPathDependent() const
{
	return pathDependent;
}

double PathDependentOption::payoff(std::vector<double> const& prices_vector) const
{
	return 0.0;
}

PathDependentOption::~PathDependentOption()
{
}
