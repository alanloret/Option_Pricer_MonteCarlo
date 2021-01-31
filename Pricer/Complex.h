#pragma once
#include "European.h"
#include "Asian.h"
#include "Digital.h"
#include <string>
#include <iostream>
#include <vector>

class Complex
{
	/* Class to create portfolio with a collection of basic options*/
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

	// Overloading operators 
	Complex operator+ (Complex const& options) const;
	Complex& operator+= (Complex const& options);
	Complex operator- (Complex const& options) const;
	Complex& operator-= (Complex const& options);
	Complex operator* (double const& x) const;
	Complex& operator*= (double const& x);
	Complex operator/ (double const& x) const;
	Complex& operator/= (double const& x);

	Complex& operator+= (EuropeanCall const& option);
	Complex& operator+= (EuropeanPut const& option);
	Complex& operator+= (DigitalCall const& option);
	Complex& operator+= (DigitalPut const& option);
	Complex& operator+= (AsianArithmeticCall const& option);
	Complex& operator+= (AsianArithmeticPut const& option);
	Complex& operator+= (AsianGeometricCall const& option);
	Complex& operator+= (AsianGeometricPut const& option);

	Complex operator+ (EuropeanCall const& option) const;
	Complex operator+ (EuropeanPut const& option) const;
	Complex operator+ (DigitalCall const& option) const;
	Complex operator+ (DigitalPut const& option) const;
	Complex operator+ (AsianArithmeticCall const& option) const;
	Complex operator+ (AsianArithmeticPut const& option) const;
	Complex operator+ (AsianGeometricCall const& option) const;
	Complex operator+ (AsianGeometricPut const& option) const;

	Complex& operator-= (EuropeanCall const& option);
	Complex& operator-= (EuropeanPut const& option);
	Complex& operator-= (DigitalCall const& option);
	Complex& operator-= (DigitalPut const& option);
	Complex& operator-= (AsianArithmeticCall const& option);
	Complex& operator-= (AsianArithmeticPut const& option);
	Complex& operator-= (AsianGeometricCall const& option);
	Complex& operator-= (AsianGeometricPut const& option);

	Complex operator- (EuropeanCall const& option) const;
	Complex operator- (EuropeanPut const& option) const;
	Complex operator- (DigitalCall const& option) const;
	Complex operator- (DigitalPut const& option) const;
	Complex operator- (AsianArithmeticCall const& option) const;
	Complex operator- (AsianArithmeticPut const& option) const;
	Complex operator- (AsianGeometricCall const& option) const;
	Complex operator- (AsianGeometricPut const& option) const;


	double getMaturity() const;
	std::string getName() const;

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

	Complex sum(Complex const& options) const;
	void add(Complex const& options);

};

// Replicating some basic options
class BullSpreadComplex : public Complex
{
public:
	BullSpreadComplex(double const& K1, double const& K2, double const& T) {
		this->setName("BullSpread");
		this->buyOption(EuropeanCall(K1, T));
		this->buyOption(EuropeanCall(K2, T), -1.0);
	}
	~BullSpreadComplex() {}
};

class BearSpreadComplex : public Complex
{
public:
	BearSpreadComplex(double const& K1, double const& K2, double const& T) {
		this->setName("BearSpread");
		this->buyOption(EuropeanPut(K1, T), -1.0);
		this->buyOption(EuropeanPut(K2, T));
	}
	~BearSpreadComplex() {}
};

class StrangleComplex : public Complex
{
public:
	StrangleComplex(double const& K1, double const& K2, double const& T) {
		this->setName("Strangle");
		this->buyOption(EuropeanPut(K1, T));
		this->buyOption(EuropeanCall(K2, T));
	}
	~StrangleComplex() {}
};

class ButterflyComplex : public Complex
{
public:
	ButterflyComplex(double const& K1, double const& K2, double const& T) {
		this->setName("Butterfly");
		this->buyOption(EuropeanCall(K1, T));
		this->buyOption(EuropeanCall((K1 + K2) / 2.0, T), -2.0);
		this->buyOption(EuropeanCall(K2, T));
	}
	~ButterflyComplex() {}
};