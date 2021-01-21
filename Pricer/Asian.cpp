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

double AsianCall::payoff(double const& S) const
{
    if ((S - this->getStrike()) > 0)
        return 1.0;
    return 0.0;
}

void AsianCall::print() const
{
    std::cout << "--- Asian Call ---" << std::endl;
    PathIndependentOption::print();
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

double AsianPut::payoff(double const& S) const
{
    if ((S - this->getStrike()) < 0)
        return 1.0;
    return 0.0;
}

void AsianPut::print() const
{
    std::cout << "--- Asian Put ---" << std::endl;
    PathIndependentOption::print();
}

AsianPut::~AsianPut()
{
}

