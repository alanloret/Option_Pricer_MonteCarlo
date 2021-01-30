#pragma once
#include "PathIndependentOption.h"

class EuropeanCall : public PathIndependentOption
{
public:
	EuropeanCall();
	EuropeanCall(double const& K, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~EuropeanCall();
};

class EuropeanPut : public PathIndependentOption
{
public:
	EuropeanPut();
	EuropeanPut(double const& K, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~EuropeanPut();
};

// Following options are not supported in Complex Class, use instead their Complex counterpart
class BullSpread : public PathIndependentOption
{
public:
	BullSpread();
	BullSpread(double const& K1, double const& K2, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~BullSpread();
private:
	double K1;
	double K2;
};

class BearSpread : public PathIndependentOption
{
public:
	BearSpread();
	BearSpread(double const& K1, double const& K2, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~BearSpread();
private:
	double K1;
	double K2;
};

class Strangle : public PathIndependentOption
{
public:
	Strangle();
	Strangle(double const& K1, double const& K2, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~Strangle();
private:
	double K1;
	double K2;
};

class Butterfly : public PathIndependentOption
{
public:
	Butterfly();
	Butterfly(double const& K1, double const& K2, double const& T);

	double payoff(double const& S) const override;
	double payoff(std::vector<double> const& prices_vector) const;
	void print() const override;
	~Butterfly();
private:
	double K1;
	double K2;
};