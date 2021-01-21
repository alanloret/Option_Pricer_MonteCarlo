#include "European.h"
#include <iostream>

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
		return S-this->getStrike();
	return 0.0;
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
		return this->getStrike() - S;
	return 0.0;
}

void EuropeanPut::print() const
{
	std::cout << "--- European Put ---" << std::endl;
	PathIndependentOption::print();
}

EuropeanPut::~EuropeanPut()
{
}
