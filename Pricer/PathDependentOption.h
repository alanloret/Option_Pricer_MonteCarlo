#pragma once
#include "Option.h"
#include <vector>
class PathDependentOption : public Option
{
public:
	PathDependentOption();
	PathDependentOption(double const& K, double const& T);

	bool isPathDependent() const;

	virtual double payoff(std::vector<double> const& prices_vector) const;
	virtual ~PathDependentOption();

private:
	bool pathDependent = true;
	
};