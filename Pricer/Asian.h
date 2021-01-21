#pragma once
#include "PathIndependentOption.h"

class AsianCall : public PathIndependentOption
{
public:
    AsianCall();
    AsianCall(double const& K, double const& T);

    double payoff(double const& S) const;
    void print() const;
    ~AsianCall();
};

class AsianPut : public PathIndependentOption
{
public:
    AsianPut();
    AsianPut(double const& K, double const& T);

    double payoff(double const& S) const;
    void print() const;
    ~AsianPut();
};

