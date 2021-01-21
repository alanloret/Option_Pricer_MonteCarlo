#pragma once
#include "PathIndependentOption.h"

class DigitalCall : public PathIndependentOption
{
public:
	DigitalCall();
	DigitalCall(double const& K, double const& T);

	double payoff(double const& S) const;
	void print() const;
	~DigitalCall();
};

class DigitalPut : public PathIndependentOption
{
public:
	DigitalPut();
	DigitalPut(double const& K, double const& T);

	double payoff(double const& S) const;
	void print() const;
	~DigitalPut();
};

