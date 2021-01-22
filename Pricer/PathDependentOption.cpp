#include "PathDependentOption.h"
#include <iostream>


PathDependentOption::PathDependentOption()
{
	K = 100.0;
	T = 1.0;
}

PathDependentOption::PathDependentOption(double const& K, double const& T)
{
	this->K = K;
	this->T = T;
}

void PathDependentOption::setStrike(double const& K)
{
	this->K = K;
}

void PathDependentOption::setMaturity(double const& T)
{
	this->T = T;
}

double PathDependentOption::getStrike() const
{
	return K;
}

double PathDependentOption::getMaturity() const
{
	return T;
}


double PathDependentOption::payoff(std::vector<double> const& prices_vector) const
{
	return 0.0;
}

void PathDependentOption::print() const
{
    std::cout << " Strike:          " << K << std::endl;
    std::cout << " Maturity:        " << T << std::endl;
}

PathDependentOption::~PathDependentOption()
= default;

