#include "Digital.h"
#include <iostream>

DigitalCall::DigitalCall()
{
	this->setStrike(100);
	this->setMaturity(1);
}

DigitalCall::DigitalCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double DigitalCall::payoff(double const& S) const
{
	if ((S - this->getStrike()) > 0)
		return 1.0;
	return 0.0;
}

void DigitalCall::print() const
{
	std::cout << "-- Digital Call --" << std::endl;
	PathIndependentOption::print();
}

DigitalCall::~DigitalCall()
{
}

DigitalPut::DigitalPut()
{
	this->setStrike(100);
	this->setMaturity(1);
}

DigitalPut::DigitalPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double DigitalPut::payoff(double const& S) const
{
	if ((S - this->getStrike()) < 0)
		return 1.0;
	return 0.0;
}

void DigitalPut::print() const
{
	std::cout << "-- Digital Put --" << std::endl;
	PathIndependentOption::print();
}

DigitalPut::~DigitalPut()
{
}
