#pragma once
#include "PathDependentOption.h"
#include <vector>

class AsianArithmeticCall : public PathDependentOption
{
public:
    AsianArithmeticCall();
    AsianArithmeticCall(double const& K, double const& T);

    double payoff(std::vector<double> const& prices_vector) const;
    void print() const;
    ~AsianArithmeticCall();

};

class AsianArithmeticPut : public PathDependentOption
{
public:
    AsianArithmeticPut();
    AsianArithmeticPut(double const& K, double const& T);

    double payoff(std::vector<double> const& prices_vector) const;
    void print() const;
    ~AsianArithmeticPut();

};

class AsianGeometricCall : public PathDependentOption
{
public:
    AsianGeometricCall();
    AsianGeometricCall(double const& K, double const& T);

    double payoff(std::vector<double> const& prices_vector) const;
    void print() const;
    ~AsianGeometricCall();

};

class AsianGeometricPut : public PathDependentOption
{
public:
    AsianGeometricPut();
    AsianGeometricPut(double const& K, double const& T);

    double payoff(std::vector<double> const& prices_vector) const;
    void print() const;
    ~AsianGeometricPut();

};