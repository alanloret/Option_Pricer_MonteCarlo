#pragma once
#include "PathDependentOption.h"
#include <vector>

class AsianCall : public PathDependentOption
{
public:
    AsianCall();
    AsianCall(double const& K, double const& T);
    AsianCall(double const& K, double const& T, std::string const& M);

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
    AsianPut(double const& K, double const& T, std::string const& M);

	double payoff(std::vector<double> const& prices_vector) const;
	void print() const;
	~AsianPut();

private:
	std::vector<double> prices_vector;
	
};
