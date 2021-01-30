#pragma once
#include "Option.h"
#include <vector>
class PathIndependentOption : public Option
{
public:
	PathIndependentOption();
	PathIndependentOption(double const& K, double const& T);


	bool isPathDependent() const;


	virtual double payoff(double const& S) const;
	virtual double payoff(std::vector<double> prices_vector) const;
	virtual ~PathIndependentOption();

private:
	bool pathDependent = false;

};