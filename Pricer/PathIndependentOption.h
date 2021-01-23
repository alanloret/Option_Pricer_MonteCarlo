#pragma once
#include <vector>
class PathIndependentOption
{
public:
	PathIndependentOption();
	PathIndependentOption(double const& K, double const& T);

	void setStrike(double const& K);
	void setMaturity(double const& T);
	void setMultiplier(double const& multiplier);

	double getStrike() const;
	double getMaturity() const;
	double getMultiplier() const;

	virtual double payoff(double const& S) const;
	virtual double payoff(std::vector<double> prices_vector) const;
	virtual ~PathIndependentOption();

	virtual void print() const;

private:
	double K;
	double T;
	double multiplier = 1.0; // 1 for long position and -1 for short

};

