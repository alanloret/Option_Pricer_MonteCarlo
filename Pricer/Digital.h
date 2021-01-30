#pragma once
#include "PathIndependentOption.h"

class DigitalCall : public PathIndependentOption
{
public:
	DigitalCall();
	DigitalCall(double const& K, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~DigitalCall();
};

class DigitalPut : public PathIndependentOption
{
public:
	DigitalPut();
	DigitalPut(double const& K, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~DigitalPut();
};

class DoubleDigital : public PathIndependentOption
{
public:
	DoubleDigital();
	DoubleDigital(double const& K1, double const& K2, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~DoubleDigital();
private:
	double K1;
	double K2;
};