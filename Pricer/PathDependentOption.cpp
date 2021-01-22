#include "PathDependentOption.h"
#include <iostream>
#include <string>

PathDependentOption::PathDependentOption()
{
	K = 100.0;
	T = 1.0;
	M = "Arithmetic";
}

PathDependentOption::PathDependentOption(double const& K, double const& T)
{
	this->K = K;
	this->T = T;
    M = "Arithmetic";
}

PathDependentOption::PathDependentOption(double const& K, double const& T, std::string const& M)
{
    this->K = K;
    this->T = T;
    this->M = M;
}

void PathDependentOption::setStrike(double const& K)
{
	this->K = K;
}

void PathDependentOption::setMaturity(double const& T)
{
	this->T = T;
}

void PathDependentOption::setMethod(std::string const& M)
{
    this->M = M;
}

double PathDependentOption::getStrike() const
{
	return K;
}

double PathDependentOption::getMaturity() const
{
	return T;
}

std::string PathDependentOption::getMethod() const
{
    return M;
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

