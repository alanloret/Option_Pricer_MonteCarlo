#include "Complex.h"

Complex::Complex()
{
	max_T = 0.0;
	name = "Complex Option";
}

Complex::Complex(std::string const& name)
{
	max_T = 0.0;
	this->name = name;
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
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	european_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());

}

void Complex::buyOption(EuropeanPut const& option, double const& multiplier)
{
	EuropeanPut new_option = EuropeanPut(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	european_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(DigitalCall const& option, double const& multiplier)
{
	DigitalCall new_option = DigitalCall(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	digital_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(DigitalPut const& option, double const& multiplier)
{
	DigitalPut new_option = DigitalPut(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	digital_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianArithmeticCall const& option, double const& multiplier)
{
	AsianArithmeticCall new_option = AsianArithmeticCall(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	asian_arithmetic_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianArithmeticPut const& option, double const& multiplier)
{
	AsianArithmeticPut new_option = AsianArithmeticPut(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	asian_arithmetic_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianGeometricCall const& option, double const& multiplier)
{
	AsianGeometricCall new_option = AsianGeometricCall(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	asian_geometric_call.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

void Complex::buyOption(AsianGeometricPut const& option, double const& multiplier)
{
	AsianGeometricPut new_option = AsianGeometricPut(option);
	new_option.setMultiplier(multiplier * new_option.getMultiplier());
	asian_geometric_put.push_back(new_option);
	max_T = std::max(max_T, new_option.getMaturity());
}

Complex Complex::operator+(Complex const& options) const
{
	Complex res(*this);
	res += options;
	return res;
}

Complex& Complex::operator+=(Complex const& options)
{
	add(options);
	name += " + " + options.getName();
	return *this;
}

Complex Complex::operator-(Complex const& options) const
{
	Complex res = Complex(options);
	res -= options;
	return res;
}

Complex& Complex::operator-=(Complex const& options)
{
	Complex copy(options);
	copy.setMultiplier(-1);
	add(copy);
	name += " - " + copy.getName();

	return *this;
}

Complex Complex::operator*(double const& x) const
{
	Complex res(*this);
	res *= x;
	return res;
}

Complex& Complex::operator*=(double const& x)
{
	this->setMultiplier(x);
	return *this;
}

Complex& Complex::operator/=(double const& x)
{
	this->setMultiplier(1 / x);
	return *this;
}

Complex Complex::operator/(double const& x) const
{
	Complex res(*this);
	res /= x;
	return res;
}

Complex& Complex::operator+=(EuropeanCall const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(EuropeanPut const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(DigitalCall const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(DigitalPut const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(AsianArithmeticCall const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(AsianArithmeticPut const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(AsianGeometricCall const& option)
{
	this->buyOption(option);
	return *this;
}

Complex& Complex::operator+=(AsianGeometricPut const& option)
{
	this->buyOption(option);
	return *this;
}

Complex Complex::operator+(EuropeanCall const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(EuropeanPut const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(DigitalCall const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(DigitalPut const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(AsianArithmeticCall const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(AsianArithmeticPut const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(AsianGeometricCall const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex Complex::operator+(AsianGeometricPut const& option) const
{
	Complex res(*this);
	return res += option;
}

Complex& Complex::operator-=(EuropeanCall const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(EuropeanPut const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(DigitalCall const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(DigitalPut const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(AsianArithmeticCall const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(AsianArithmeticPut const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(AsianGeometricCall const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex& Complex::operator-=(AsianGeometricPut const& option)
{
	this->buyOption(option, -1);
	return *this;
}

Complex Complex::operator-(EuropeanCall const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(EuropeanPut const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(DigitalCall const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(DigitalPut const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(AsianArithmeticCall const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(AsianArithmeticPut const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(AsianGeometricCall const& option) const
{
	Complex res(*this);
	return res -= option;
}

Complex Complex::operator-(AsianGeometricPut const& option) const
{
	Complex res(*this);
	return res -= option;
}

double Complex::getMaturity() const
{
	return max_T;
}

std::string Complex::getName() const
{
	return name;
}

void Complex::setName(std::string const& name)
{
	this->name = name;
}

void Complex::setMultiplier(double const& multiplier)
{
	for (auto& i : european_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : european_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : digital_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : digital_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : asian_arithmetic_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : asian_arithmetic_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : asian_geometric_call) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
	for (auto& i : asian_geometric_put) {
		i.setMultiplier(i.getMultiplier() * multiplier);
	}
}

double Complex::payoff(std::vector<double> const& prices_vector) const
{
	double sum = 0.0;
	for (const auto& i : european_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : european_put) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : digital_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : digital_put) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : asian_arithmetic_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : asian_arithmetic_put) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : asian_geometric_call) {
		sum += i.payoff(prices_vector);
	}
	for (const auto& i : asian_geometric_put) {
		sum += i.payoff(prices_vector);
	}
	return sum;
}

void Complex::print() const
{
	std::cout << "** Complex Option : " << name << " ** " << std::endl;
	std::cout << " Max maturity: " << max_T << std::endl;
	std::cout << " Composed of " << std::endl;
	for (const auto& i : european_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : european_put) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : digital_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : digital_put) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : asian_arithmetic_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : asian_arithmetic_put) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : asian_geometric_call) {
		std::cout << "* ";
		i.print();
	}
	for (const auto& i : asian_geometric_put) {
		std::cout << "* ";
		i.print();
	}
	std::cout << std::endl;
}

Complex::~Complex()
{
}

Complex Complex::sum(Complex const& options) const
{
	Complex res = Complex(options);
	res.european_call.insert(res.european_call.end(), european_call.begin(), european_call.end());
	res.european_put.insert(res.european_put.end(), european_put.begin(), european_put.end());
	res.digital_call.insert(res.digital_call.end(), digital_call.begin(), digital_call.end());
	res.digital_put.insert(res.digital_put.end(), digital_put.begin(), digital_put.end());
	res.asian_arithmetic_call.insert(res.asian_arithmetic_call.end(), asian_arithmetic_call.begin(), asian_arithmetic_call.end());
	res.asian_arithmetic_put.insert(res.asian_arithmetic_put.end(), asian_arithmetic_put.begin(), asian_arithmetic_put.end());
	res.asian_geometric_call.insert(res.asian_geometric_call.end(), asian_geometric_call.begin(), asian_geometric_call.end());
	res.asian_geometric_put.insert(res.asian_geometric_put.end(), asian_geometric_put.begin(), asian_geometric_put.end());

	res.max_T = std::max(res.max_T, max_T);

	return res;
}

void Complex::add(Complex const& options)
{
	european_call.insert(european_call.end(), options.european_call.begin(), options.european_call.end());
	european_put.insert(european_put.end(), options.european_put.begin(), options.european_put.end());
	digital_call.insert(digital_call.end(), options.digital_call.begin(), options.digital_call.end());
	digital_put.insert(digital_put.end(), options.digital_put.begin(), options.digital_put.end());
	asian_arithmetic_call.insert(asian_arithmetic_call.end(), options.asian_arithmetic_call.begin(), options.asian_arithmetic_call.end());
	asian_arithmetic_put.insert(asian_arithmetic_put.end(), options.asian_arithmetic_put.begin(), options.asian_arithmetic_put.end());
	asian_geometric_call.insert(asian_geometric_call.end(), options.asian_geometric_call.begin(), options.asian_geometric_call.end());
	asian_geometric_put.insert(asian_geometric_put.end(), options.asian_geometric_put.begin(), options.asian_geometric_put.end());

	max_T = std::max(max_T, options.max_T);
}