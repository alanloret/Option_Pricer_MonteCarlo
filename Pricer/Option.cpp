#include "Option.h"
#include <iostream>
Option::Option()
{
	K = 100.0;
	T = 1.0;
}

Option::Option(double const& K, double const& T)
{
	this->K = K;
	this->T = T;
}


void Option::setStrike(double const& K)
{
	this->K = K;
}

void Option::setMaturity(double const& T)
{
	this->T = T;
}

void Option::setMultiplier(double const& multiplier)
{
	this->multiplier = multiplier;
}

double Option::getStrike() const
{
	return K;
}

double Option::getMaturity() const
{
	return T;
}

double Option::getMultiplier() const
{
	return multiplier;
}

Option::~Option()
{
}

void Option::print() const
{
	std::cout << " Strike:          " << K << std::endl;
	std::cout << " Maturity:        " << T << std::endl;
	std::cout << " Multiplier:      " << multiplier << std::endl;
}