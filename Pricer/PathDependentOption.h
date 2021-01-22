#pragma once
#include <vector>
#include <string>

class PathDependentOption
{
public:
	PathDependentOption();
	PathDependentOption(double const& K, double const& T);
    PathDependentOption(double const& K, double const& T, std::string const& M);

	void setStrike(double const& K);
	void setMaturity(double const& T);
	void setMethod(std::string const& M);

	double getStrike() const;
	double getMaturity() const;
	std::string getMethod() const;

	virtual double payoff(std::vector<double> const& prices_vector) const;
	virtual ~PathDependentOption();

	void print() const;

private:
	double K;
	double T;
	std::string M;
};

