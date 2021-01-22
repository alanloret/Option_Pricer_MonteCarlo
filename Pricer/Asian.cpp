#include "Asian.h"
#include <iostream>
#include <cmath>

AsianCall::AsianCall()
{
    this->setStrike(100);
    this->setMaturity(1);
    this->setMethod("Arithmetic");
}

AsianCall::AsianCall(double const& K, double const& T)
{
    this->setStrike(K);
    this->setMaturity(T);
    this->setMethod("Arithmetic");
}

AsianCall::AsianCall(double const& K, double const& T, std::string const& M)
{
    this->setStrike(K);
    this->setMaturity(T);
    this->setMethod(M);
}

double AsianCall::payoff(std::vector<double> const& prices_vector) const
{
    double mean = 0;

    if (this->getMethod() == "Arithmetic"){
        for (double i : prices_vector) {
            mean += i;
        }
        mean /= static_cast<double>(prices_vector.size());
    } else if (this->getMethod() == "Geometric") {
        for (double i : prices_vector) {
            mean += log(i);
        }
        mean = exp(mean / static_cast<double>(prices_vector.size()));
    } else {
        return 0.0;
    }

    if ((mean - this->getStrike()) > 0)
        return mean - this->getStrike();
    return 0.0;
}

void AsianCall::print() const
{
    std::cout << "--- Asian " << this->getMethod() << " Call ---" << std::endl;
    PathDependentOption::print();
}

AsianCall::~AsianCall()
{
}

AsianPut::AsianPut()
{
	this->setStrike(100);
	this->setMaturity(1);
    this->setMethod("Arithmetic");
}

AsianPut::AsianPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
    this->setMethod("Arithmetic");
}

AsianPut::AsianPut(double const& K, double const& T, std::string const& M)
{
    this->setStrike(K);
    this->setMaturity(T);
    this->setMethod(M);
}

double AsianPut::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0;
    if (this->getMethod() == "Arithmetic"){
        for (double i : prices_vector) {
            mean += i;
        }
        mean /= static_cast<double>(prices_vector.size());
    } else if (this->getMethod() == "Geometric") {
        for (double i : prices_vector) {
            mean += log(i);
        }
        mean = exp(mean / static_cast<double>(prices_vector.size()));
    } else {
        return 0.0;
    }

    if ((this->getStrike() - mean) > 0)
        return this->getStrike() - mean;
    return 0.0;
}

void AsianPut::print() const
{
	std::cout << "--- Asian " << this->getMethod() << " Put ---" << std::endl;
	PathDependentOption::print();
}

AsianPut::~AsianPut()
{
}
