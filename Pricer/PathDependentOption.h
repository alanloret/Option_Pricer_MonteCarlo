#pragma once
#include <vector>

class PathDependentOption
{
public:
    PathDependentOption();
	PathDependentOption(double const& K, double const& T);

	void setStrike(double const& K);
	void setMaturity(double const& T);

	double getStrike() const;
	double getMaturity() const;

	virtual double payoff(std::vector<double> const& prices_vector) const;
	virtual ~PathDependentOption();

    virtual void print() const;

private:
	double K;
	double T;
};

