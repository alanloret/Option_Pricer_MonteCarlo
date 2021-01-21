#pragma once
#include "PathDependentOption.h"
#include <vector>

class AsianCall : public PathDependentOption
{
public:
    AsianCall();
    AsianCall(double const& K, double const& T);

    double payoff(std::vector<double> const& prices_vector) const;
    void print() const;
    ~AsianCall();

private:
    std::vector<double> prices_vector;

};


class AsianPut : public PathDependentOption
{
public:
	AsianPut();
	AsianPut(double const& K, double const& T);

	double payoff(std::vector<double> const& prices_vector) const;
	void print() const;
	~AsianPut();

private:
	std::vector<double> prices_vector;
	
};
