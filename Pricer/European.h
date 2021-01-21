#pragma once
#include "PathIndependentOption.h"

class EuropeanCall : public PathIndependentOption
{
public:
	EuropeanCall();
	EuropeanCall(double const& K, double const& T);

	double payoff(double const& S) const;
	void print() const;
	~EuropeanCall();
};

class EuropeanPut : public PathIndependentOption
{
public:
	EuropeanPut();
	EuropeanPut(double const& K, double const& T);

	double payoff(double const& S) const;
	void print() const;
	~EuropeanPut();
};

