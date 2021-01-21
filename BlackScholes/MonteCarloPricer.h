#pragma once
#include "BlackScholesModel.h"
#include <iostream>
#include <cmath>

class MonteCarloPricer
{
public:
	MonteCarloPricer();
	MonteCarloPricer(int const& num_sims);

	void setNumSims(int const& num_sims);
	int getNumSims();

	template<typename T>
	double price(BlackScholesModel const& model, T const& option) const;
	template<typename T>
	void priceAndPrint(BlackScholesModel const& model, T const& option) const;
	

private:
	int num_sims;
};


// Define the template here
template<typename T>
inline double MonteCarloPricer::price(BlackScholesModel const& model, T const& option) const
{
	double payoff_sum = 0.0;
	for (int i = 0; i < num_sims; i++) {
		payoff_sum += option.payoff(model.generatePrice(option.getMaturity()));
	}
	return (payoff_sum / static_cast<double>(num_sims)) * exp(-model.getRiskFreeRate() * option.getMaturity());
}

template<typename T>
inline void MonteCarloPricer::priceAndPrint(BlackScholesModel const& model, T const& option) const
{
	model.print();
	option.print();
	std::cout << "Estimated price : " << price(model, option) << std::endl << std::endl;
}
