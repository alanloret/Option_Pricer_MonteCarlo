#include "Complex.h"

Complex::Complex()
{
	max_T = 0;
}

Complex::Complex(std::string const& name)
{
	this->name = name;
    max_T = 0;
}

void Complex::buyOption(EuropeanCall const& option)
{
	european_call.push_back(EuropeanCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(EuropeanPut const& option)
{
	european_put.push_back(EuropeanPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(DigitalCall const& option)
{
	digital_call.push_back(DigitalCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(DigitalPut const& option)
{
	digital_put.push_back(DigitalPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianArithmeticCall const& option)
{
	asian_arithmetic_call.push_back(AsianArithmeticCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianArithmeticPut const& option)
{
	asian_arithmetic_put.push_back(AsianArithmeticPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianGeometricCall const& option)
{
	asian_geometric_call.push_back(AsianGeometricCall(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(AsianGeometricPut const& option)
{
	asian_geometric_put.push_back(AsianGeometricPut(option));
	max_T = std::max(max_T, option.getMaturity());
}

void Complex::buyOption(EuropeanCall const& option, double const& multiplier)
{
	EuropeanCall new_option = EuropeanCall(option);
	new_option.setMultiplier(multiplier);
	european_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());

}

void Complex::buyOption(EuropeanPut const& option, double const& multiplier)
{
	EuropeanPut new_option = EuropeanPut(option);
	new_option.setMultiplier(multiplier);
	european_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(DigitalCall const& option, double const& multiplier)
{
	DigitalCall new_option = DigitalCall(option);
	new_option.setMultiplier(multiplier);
	digital_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(DigitalPut const& option, double const& multiplier)
{
	DigitalPut new_option = DigitalPut(option);
	new_option.setMultiplier(multiplier);
	digital_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianArithmeticCall const& option, double const& multiplier)
{
	AsianArithmeticCall new_option = AsianArithmeticCall(option);
	new_option.setMultiplier(multiplier);
	asian_arithmetic_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianArithmeticPut const& option, double const& multiplier)
{
	AsianArithmeticPut new_option = AsianArithmeticPut(option);
	new_option.setMultiplier(multiplier);
	asian_arithmetic_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianGeometricCall const& option, double const& multiplier)
{
	AsianGeometricCall new_option = AsianGeometricCall(option);
	new_option.setMultiplier(multiplier);
	asian_geometric_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianGeometricPut const& option, double const& multiplier)
{
	AsianGeometricPut new_option = AsianGeometricPut(option);
	new_option.setMultiplier(multiplier);
	asian_geometric_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

double Complex::getMaturity() const
{
	return max_T;
}

void Complex::setName(std::string const& name)
{
	this->name = name;
}

void Complex::setMultiplier(double const& multiplier)
{
	for (auto & i : european_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : european_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : digital_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : digital_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : asian_arithmetic_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : asian_arithmetic_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : asian_geometric_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto & i : asian_geometric_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
}

double Complex::payoff(std::vector<double> const& prices_vector) const
{
	double sum = 0.0;
	for (const auto & i : european_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : european_put) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : digital_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : digital_put) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : asian_arithmetic_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : asian_arithmetic_put) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : asian_geometric_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto & i : asian_geometric_put) {
		sum += i.payoff(prices_vector);
	}
	return sum;
}

void Complex::print() const
{
	std::cout << "** Complex Option : "<< name << " ** "<< std::endl;
	std::cout << " Max maturity: " << max_T << std::endl;
	std::cout << " Composed of " << std::endl;
	for (const auto & i : european_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : european_put) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : digital_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : digital_put) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : asian_arithmetic_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : asian_arithmetic_put) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : asian_geometric_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto & i : asian_geometric_put) {
		std::cout << "* ";
		i.print();
	}
}

Complex::~Complex()
{
}
