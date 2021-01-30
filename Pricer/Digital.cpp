#include "Digital.h"
#include <iostream>

DigitalCall::DigitalCall()
{
	this->setStrike(100.0);
	this->setMaturity(1.0);
}

DigitalCall::DigitalCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double DigitalCall::payoff(double const& S) const
{
	if ((S - this->getStrike()) > 0)
		return 1.0 * getMultiplier();
	return 0.0;
}

double DigitalCall::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void DigitalCall::print() const
{
	std::cout << "--- Digital Call ---" << std::endl;
	PathIndependentOption::print();
}

DigitalCall::~DigitalCall()
{
}

DigitalPut::DigitalPut()
{
	this->setStrike(100.0);
	this->setMaturity(1.0);
}

DigitalPut::DigitalPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double DigitalPut::payoff(double const& S) const
{
	if ((S - this->getStrike()) < 0)
		return 1.0 * getMultiplier();
	return 0.0;
}

double DigitalPut::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void DigitalPut::print() const
{
	std::cout << "--- Digital Put ---" << std::endl;
	PathIndependentOption::print();
}

DigitalPut::~DigitalPut()
{
}

DoubleDigital::DoubleDigital()
{
	this->K1 = 90.0;
	this->K2 = 100.0;
	this->setMaturity(1.0);
}
DoubleDigital::DoubleDigital(double const& K1, double const& K2, double const& T)
{
	this->K1 = K1;
	this->K2 = K2;
	this->setMaturity(T);
}

double DoubleDigital::payoff(double const& S) const
{
	if (K1 < S && K2 > S)
		return 1.0 * getMultiplier();
	return 0.0;
}

double DoubleDigital::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void DoubleDigital::print() const
{
	std::cout << "--- Double Digital ---" << std::endl;
	std::cout << " Low Strike:      " << K1 << std::endl;
	std::cout << " High Strike:     " << K2 << std::endl;
	std::cout << " Maturity:        " << this->getMaturity() << std::endl;
}

DoubleDigital::~DoubleDigital()
{
}