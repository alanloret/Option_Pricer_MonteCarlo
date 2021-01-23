#pragma once
#include <vector>
class PathDependentOption
{
public:
	PathDependentOption();
	PathDependentOption(double const& K, double const& T);

	void setStrike(double const& K);
	void setMaturity(double const& T);
	void setMultiplier(double const& multiplier);

	double getStrike() const;
	double getMaturity() const;
	bool isPathDependent() const;
	double getMultiplier() const;

	virtual double payoff(std::vector<double> const& prices_vector) const;
	virtual ~PathDependentOption();

	virtual void print() const;

private:
	double K;
	double T;
	bool pathDependent = true;
	double multiplier = 1.0; // 1 for long position and -1 for short
};

