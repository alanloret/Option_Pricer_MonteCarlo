#include "Asian.h"
#include <iostream>
#include <cmath>

AsianArithmeticCall::AsianArithmeticCall()
{
	this->setStrike(100.0);
	this->setMaturity(1.0);
}

AsianArithmeticCall::AsianArithmeticCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianArithmeticCall::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0.0;
	for (double i : prices_vector) {
		mean += i;
	}
	mean /= static_cast<double>(prices_vector.size());

	if ((mean - this->getStrike()) > 0)
		return (mean - this->getStrike()) * getMultiplier();
	return 0.0;
}

void AsianArithmeticCall::print() const
{
	std::cout << "--- Asian Arithmethic Call ---" << std::endl;
	PathDependentOption::print();
}

AsianArithmeticCall::~AsianArithmeticCall()
{
}

AsianArithmeticPut::AsianArithmeticPut()
{
	this->setStrike(100.0);
	this->setMaturity(1.0);
}

AsianArithmeticPut::AsianArithmeticPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianArithmeticPut::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0.0;
	for (double i : prices_vector) {
		mean += i;
	}
	mean /= static_cast<double>(prices_vector.size());

	if ((this->getStrike()) - mean > 0)
		return (this->getStrike() - mean) * getMultiplier();
	return 0.0;
}

void AsianArithmeticPut::print() const
{
	std::cout << "--- Asian Arithmethic Put ---" << std::endl;
	PathDependentOption::print();
}

AsianArithmeticPut::~AsianArithmeticPut()
{
}

AsianGeometricCall::AsianGeometricCall()
{
	this->setStrike(100.0);
	this->setMaturity(1.0);
}

AsianGeometricCall::AsianGeometricCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianGeometricCall::payoff(std::vector<double> const& prices_vector) const
{
	double geometric_mean = 0.0;
	for (double i : prices_vector) {
		geometric_mean += log(i);
	}
	geometric_mean = exp(geometric_mean / static_cast<double>(prices_vector.size()));

	if ((geometric_mean - this->getStrike()) > 0)
		return (geometric_mean - this->getStrike()) * getMultiplier();
	return 0.0;
}

void AsianGeometricCall::print() const
{
	std::cout << "--- Asian Geometric Call ---" << std::endl;
	PathDependentOption::print();
}

AsianGeometricCall::~AsianGeometricCall()
{
}

AsianGeometricPut::AsianGeometricPut()
{
	this->setStrike(100.0);
	this->setMaturity(1.0);
}

AsianGeometricPut::AsianGeometricPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianGeometricPut::payoff(std::vector<double> const& prices_vector) const
{
	double geometric_mean = 0.0;
	for (double i : prices_vector) {
		geometric_mean += log(i);
	}
	geometric_mean = exp(geometric_mean / static_cast<double>(prices_vector.size()));

	if ((this->getStrike()) - geometric_mean > 0)
		return (this->getStrike() - geometric_mean) * getMultiplier();
	return 0.0;
}

void AsianGeometricPut::print() const
{
	std::cout << "--- Asian Geometric Put ---" << std::endl;
	PathDependentOption::print();
}

AsianGeometricPut::~AsianGeometricPut()
{
}