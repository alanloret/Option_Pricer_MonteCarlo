#include "Asian.h"
#include <iostream>

AsianCall::AsianCall()
{
    this->setStrike(100);
    this->setMaturity(1);
}

AsianCall::AsianCall(double const& K, double const& T)
{
    this->setStrike(K);
    this->setMaturity(T);
}

double AsianCall::payoff(std::vector<double> const& prices_vector) const
{
    double mean = 0;
    for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
        mean += prices_vector[i];
    }
    mean /= static_cast<double>(prices_vector.size());

    if ((mean-this->getStrike()) > 0)
        return mean-this->getStrike();
    return 0.0;
}

void AsianCall::print() const
{
    std::cout << "--- Asian Arithmetic Call ---" << std::endl;
    PathDependentOption::print();
}

AsianCall::~AsianCall()
{
}

AsianPut::AsianPut()
{
	this->setStrike(100);
	this->setMaturity(1);
}

AsianPut::AsianPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianPut::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0;
	for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
		mean += prices_vector[i];
	}
	mean /= static_cast<double>(prices_vector.size());

    if ((this->getStrike()-mean) > 0)
        return this->getStrike()-mean;
    return 0.0;
}

void AsianPut::print() const
{
	std::cout << "--- Asian Arithmetic Put ---" << std::endl;
	PathDependentOption::print();
}

AsianPut::~AsianPut()
{
}
