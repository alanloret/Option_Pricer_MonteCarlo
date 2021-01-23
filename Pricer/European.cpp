#include "European.h"
#include <iostream>
#include <cmath>

EuropeanCall::EuropeanCall()
{
	this->setStrike(100);
	this->setMaturity(1);
}

EuropeanCall::EuropeanCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double EuropeanCall::payoff(double const& S) const
{
	if ((S-this->getStrike()) > 0)
		return (S-this->getStrike()) * getMultiplier();
	return 0.0;
}

double EuropeanCall::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void EuropeanCall::print() const
{
	std::cout << "--- European Call ---" << std::endl;
	PathIndependentOption::print();
}

EuropeanCall::~EuropeanCall()
{
}

EuropeanPut::EuropeanPut()
{
	this->setStrike(100);
	this->setMaturity(1);
}

EuropeanPut::EuropeanPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double EuropeanPut::payoff(double const& S) const
{
	if ((this->getStrike() - S) > 0)
		return (this->getStrike() - S) * getMultiplier();
	return 0.0;
}

double EuropeanPut::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void EuropeanPut::print() const
{
	std::cout << "--- European Put ---" << std::endl;
	PathIndependentOption::print();
}

EuropeanPut::~EuropeanPut()
{
}

BullSpread::BullSpread()
{
	this->K1 = 90;
	this->K2 = 110;
	this->setMaturity(1);
}
BullSpread::BullSpread(double const& K1, double const& K2, double const& T)
{
	this->K1 = K1;
	this->K2 = K2;
	this->setMaturity(T);
}

double BullSpread::payoff(double const& S) const
{
	if (K1 < S && K2 > S)
		return (S - K1) * getMultiplier();
	else if (K2 < S)
		return (K2 - K1) * getMultiplier();
	return 0.0;
}

double BullSpread::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void BullSpread::print() const
{
	std::cout << "--- Bull Spread ---" << std::endl;
	std::cout << " Low Strike:      " << K1 << std::endl;
	std::cout << " High Strike:     " << K2 << std::endl;
	std::cout << " Maturity:        " << this->getMaturity() << std::endl;
}

BullSpread::~BullSpread()
{
}

BearSpread::BearSpread()
{
	this->K1 = 90;
	this->K2 = 110;
	this->setMaturity(1);
}
BearSpread::BearSpread(double const& K1, double const& K2, double const& T)
{
	this->K1 = K1;
	this->K2 = K2;
	this->setMaturity(T);
}

double BearSpread::payoff(double const& S) const
{
	if (K1 < S && K2 > S)
		return (K2 - S) * getMultiplier();
	else if (S < K1)
		return (K2 - K1) * getMultiplier();
	return 0.0;
}

double BearSpread::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void BearSpread::print() const
{
	std::cout << "--- Bear Spread ---" << std::endl;
    std::cout << " Low Strike:      " << K1 << std::endl;
    std::cout << " High Strike:     " << K2 << std::endl;
    std::cout << " Maturity:        " << this->getMaturity() << std::endl;
}

BearSpread::~BearSpread()
{
}

Strangle::Strangle()
{
	this->K1 = 90;
	this->K2 = 110;
	this->setMaturity(1);
}
Strangle::Strangle(double const& K1, double const& K2, double const& T)
{
	this->K1 = K1;
	this->K2 = K2;
	this->setMaturity(T);
}

double Strangle::payoff(double const& S) const
{
	if (S < K1)
		return (K1 - S) * getMultiplier();
	else if (S > K2)
		return (S - K2) * getMultiplier();
	return 0.0;
}

double Strangle::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void Strangle::print() const
{
	std::cout << "--- Strangle ---" << std::endl;
    std::cout << " Low Strike:      " << K1 << std::endl;
    std::cout << " High Strike:     " << K2 << std::endl;
    std::cout << " Maturity:        " << this->getMaturity() << std::endl;
}

Strangle::~Strangle()
{
}

Butterfly::Butterfly()
{
	this->K1 = 90;
	this->K2 = 110;
	this->setMaturity(1);
}
Butterfly::Butterfly(double const& K1, double const& K2, double const& T)
{
	this->K1 = K1;
	this->K2 = K2;
	this->setMaturity(T);
}

double Butterfly::payoff(double const& S) const
{
	if (K1 < S && S < (K1+K2)/2)
		return (S - K1) * getMultiplier();
	else if ((K1+K2)/2 < S && S < K2)
		return (K2 - S) * getMultiplier();
	return 0.0;
}

double Butterfly::payoff(std::vector<double> const& prices_vector) const
{
	return payoff(prices_vector.back());
}

void Butterfly::print() const
{
	std::cout << "--- Butterfly ---" << std::endl;
    std::cout << " Low Strike:      " << K1 << std::endl;
    std::cout << " High Strike:     " << K2 << std::endl;
    std::cout << " Maturity:        " << this->getMaturity() << std::endl;
}

Butterfly::~Butterfly()
{
}
