#pragma once
#include "BlackScholesModel.h"
#include "Asian.h"
#include "PriceCI.h"
#include <iostream>
#include <cmath>

/*
Methods price, priceComplex and priceClassic now return Price_CI objects to allow
to display confidence intervals as well as the price estimate.
 */

class MonteCarloPricer
{
public:
	MonteCarloPricer();
	MonteCarloPricer(int const& num_sims);
	MonteCarloPricer(int const& num_sims, int const& n_steps);

	void setNumSims(int const& num_sims);
	int getNumSims() const;
	void setNumSteps(int const& n_steps);
	int getNumSteps() const;
	void showPrices() const;

	// Price any option NOT WORKING
	template<typename T>
	PriceCI price(BlackScholesModel const& model, T const& option);
	template<typename T>
	void priceAndPrint(BlackScholesModel const& model, T const& option);

	// Price Path Dependent Option
	template<typename pathDependentOption>
	PriceCI priceComplex(BlackScholesModel const& model, pathDependentOption const& option);
	template<typename pathDependentOption>
	void priceAndPrintComplex(BlackScholesModel const& model, pathDependentOption const& option);
	
	// Price Path Independent Option | Quick method
	template<typename pathIndependentOption>
	PriceCI priceClassic(BlackScholesModel const& model, pathIndependentOption const& option) const;
	template<typename pathIndependentOption>
	void priceAndPrintClassic(BlackScholesModel const& model, pathIndependentOption const& option) const;

	~MonteCarloPricer();
	

private:
	int num_sims;
	int n_steps;
	std::vector<double>* prices_vector;
	
};

// Price Any Option
template<typename T>
inline PriceCI MonteCarloPricer::price(BlackScholesModel const& model, T const& option)
{
	model.generatePath(option.getMaturity(), *prices_vector);

	double payoff, payoff_sum=0.0, payoff_sq_sum=0.0;
	for (int i = 0; i < num_sims; i++) {
		model.generatePath(option.getMaturity(), *prices_vector);
		payoff = option.payoff(*prices_vector);
		payoff_sum += payoff;
		payoff_sq_sum += payoff * payoff;
	}
	double payoff_mean = payoff_sum / static_cast<double>(num_sims);
	double payoff_std = (payoff_sq_sum / static_cast<double>(num_sims)) - payoff_mean * payoff_mean;
	payoff_mean *= exp(-model.getRiskFreeRate() * option.getMaturity());
	payoff_std *= exp(-2 * model.getRiskFreeRate() * option.getMaturity());
	return {payoff_mean, payoff_std, num_sims};
}

template<typename T>
inline void MonteCarloPricer::priceAndPrint(BlackScholesModel const& model, T const& option)
{
	model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
	option.print();
	price(model, option).print_CI();
}

//Price Path Dependent Option
template<typename pathDependentOption>
inline PriceCI MonteCarloPricer::priceComplex(BlackScholesModel const& model, pathDependentOption const& option)
{
	model.generatePath(option.getMaturity(), *prices_vector);

    double payoff, payoff_sum=0.0, payoff_sq_sum=0.0;
	for (int i = 0; i < num_sims; i++) {
		model.generatePath(option.getMaturity(), *prices_vector);
		payoff = option.payoff(*prices_vector);
		payoff_sum += payoff;
        payoff_sq_sum += payoff * payoff;
	}
    double payoff_mean = payoff_sum / static_cast<double>(num_sims);
    double payoff_std = (payoff_sq_sum / static_cast<double>(num_sims)) - payoff_mean * payoff_mean;
    payoff_mean *= exp(-model.getRiskFreeRate() * option.getMaturity());
    payoff_std *= exp(-2 * model.getRiskFreeRate() * option.getMaturity());
    return {payoff_mean, payoff_std, num_sims};
}

template<typename pathDependentOption>
inline void MonteCarloPricer::priceAndPrintComplex(BlackScholesModel const& model, pathDependentOption const& option)
{
	model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
    std::cout << " Steps:           " << n_steps << std::endl;
	option.print();
	priceComplex(model, option).print_CI();
}

// Price Path Independent Option
template<typename pathIndependentOption>
inline PriceCI MonteCarloPricer::priceClassic(BlackScholesModel const& model, pathIndependentOption const& option) const
{
    double payoff, payoff_sum=0.0, payoff_sq_sum=0.0;
	for (int i = 0; i < num_sims; i++) {
		payoff = option.payoff(model.generatePrice(option.getMaturity()));
        payoff_sum += payoff;
        payoff_sq_sum += payoff * payoff;
	}
    double payoff_mean = payoff_sum / static_cast<double>(num_sims);
    double payoff_std = (payoff_sq_sum / static_cast<double>(num_sims)) - payoff_mean * payoff_mean;
    payoff_mean *= exp(-model.getRiskFreeRate() * option.getMaturity());
    payoff_std *= exp(-2 * model.getRiskFreeRate() * option.getMaturity());
    return {payoff_mean, payoff_std, num_sims};
}

template<typename pathIndependentOption>
inline void MonteCarloPricer::priceAndPrintClassic(BlackScholesModel const& model, pathIndependentOption const& option) const
{
	model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
	option.print();
	priceClassic(model, option).print_CI();
}
