#pragma once
#include <vector>
#include "European.h"
#include "Asian.h"
#include "Digital.h"
#include <string>
#include <iostream>

class Complex
{
public:
	Complex();
	Complex(std::string const& name);

	void buyOption(EuropeanCall const& option);
	void buyOption(EuropeanPut const& option);
	void buyOption(DigitalCall const& option);
	void buyOption(DigitalPut const& option);
	void buyOption(AsianArithmeticCall const& option);
	void buyOption(AsianArithmeticPut const& option);
	void buyOption(AsianGeometricCall const& option);
	void buyOption(AsianGeometricPut const& option);

	void buyOption(EuropeanCall const& option, double const& multiplier);
	void buyOption(EuropeanPut const& option, double const& multiplier);
	void buyOption(DigitalCall const& option, double const& multiplier);
	void buyOption(DigitalPut const& option, double const& multiplier);
	void buyOption(AsianArithmeticCall const& option, double const& multiplier);
	void buyOption(AsianArithmeticPut const& option, double const& multiplier);
	void buyOption(AsianGeometricCall const& option, double const& multiplier);
	void buyOption(AsianGeometricPut const& option, double const& multiplier);

	double getMaturity() const;

	void setName(std::string const& name);
	void setMultiplier(double const& multiplier);

	double payoff(std::vector<double> const& prices_vector) const;

	void print() const;

	~Complex();

private:
	std::string name;
	double max_T;

	std::vector<EuropeanCall> european_call;
	std::vector<EuropeanPut> european_put;
	std::vector<DigitalCall> digital_call;
	std::vector<DigitalPut> digital_put;
	std::vector<AsianArithmeticCall> asian_arithmetic_call;
	std::vector<AsianArithmeticPut> asian_arithmetic_put;
	std::vector<AsianGeometricCall> asian_geometric_call;
	std::vector<AsianGeometricPut> asian_geometric_put;

};

class BullSpread2 : public Complex
{
public:
	BullSpread2(double const& K1, double const& K2, double const& T) {
		this->setName("BullSpread2");
		this->buyOption(EuropeanCall(K1, T));
		this->buyOption(EuropeanCall(K2, T), -1);
	}
	~BullSpread2() {}
};

class BearSpread2 : public Complex
{
public:
	BearSpread2(double const& K1, double const& K2, double const& T) {
		this->setName("BearSpread2");
		this->buyOption(EuropeanCall(K1, T), -1);
		this->buyOption(EuropeanPut(K2, T));
	}
	~BearSpread2() {}
};

class Strangle2 : public Complex
{
public:
	Strangle2(double const& K1, double const& K2, double const& T) {
		this->setName("Strangle2");
		this->buyOption(EuropeanPut(K1, T));
		this->buyOption(EuropeanCall(K2, T));
	}
	~Strangle2() {}
};

class Butterfly2 : public Complex
{
public:
	Butterfly2(double const& K1, double const& K2, double const& T) {
		this->setName("Butterfly2");
		this->buyOption(EuropeanCall(K1, T));
		this->buyOption(EuropeanPut((K1 + K2) / 2, T), 2);
		this->buyOption(EuropeanCall(K2, T));
	}
	~Butterfly2() {}
};
