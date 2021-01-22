#pragma once
#include "BlackScholesModel.h"
#include "Asian.h"
#include <iostream>
#include <cmath>

class MonteCarloPricer
{
public:
	MonteCarloPricer();
	explicit MonteCarloPricer(int const& num_sims);
	MonteCarloPricer(int const& num_sims, int const& n_steps);

	void setNumSims(int const& num_sims);
	int getNumSims() const;
    void setNumSteps(int const& n_steps);
    int getNumSteps() const;
    void showPrices();

    template<typename T>
    double price(BlackScholesModel const& model, T const& option);
    template<typename T>
    void priceAndPrint(BlackScholesModel const& model, T const& option);

    // Price Path Dependent Option
    template<typename pathDependentOption>
    double priceComplex(BlackScholesModel const& model, pathDependentOption const& option);
    template<typename pathDependentOption>
    void priceAndPrintComplex(BlackScholesModel const& model, pathDependentOption const& option);

    // Price Path Independent Option
    template<typename pathIndependentOption>
    double priceClassic(BlackScholesModel const& model, pathIndependentOption const& option) const;
    template<typename pathIndependentOption>
    void priceAndPrintClassic(BlackScholesModel const& model, pathIndependentOption const& option) const;

    ~MonteCarloPricer();

private:
	int num_sims;
	int n_steps;
	std::vector<double>* prices_vector;
	
};

// Define the templates here

template<typename T>
inline double MonteCarloPricer::price(BlackScholesModel const& model, T const& option)
{
    if (option.isPathDependent()) {
        std::cout << "Path Dependent" << std::endl;
    }
    else {
        std::cout << "Path Independent" << std::endl;
    }
    return 0.0;
}

template<typename T>
inline void MonteCarloPricer::priceAndPrint(BlackScholesModel const& model, T const& option)
{
    if (option.isPathDependent())
        priceAndPrintAsian(model, option);
    else
        priceAndPrintClassic(model, option);
}

//Price Path Dependent Option
template<typename pathDependentOption>
inline double MonteCarloPricer::priceComplex(BlackScholesModel const& model, pathDependentOption const& option)
{
    model.generatePath(option.getMaturity(), *prices_vector);

    double payoff_sum = 0.0;
    for (int i = 0; i < num_sims; i++) {
        model.generatePath(option.getMaturity(), *prices_vector);
        payoff_sum += option.payoff(*prices_vector);
    }
    return (payoff_sum / static_cast<double>(num_sims)) * exp(-model.getRiskFreeRate() * option.getMaturity());
}

template<typename pathDependentOption>
inline void MonteCarloPricer::priceAndPrintComplex(BlackScholesModel const& model, pathDependentOption const& option)
{
    model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
    std::cout << " Number of steps: " << n_steps << std::endl;
    option.print();
    std::cout << " Estimated price: " << priceComplex(model, option) << std::endl << std::endl;
}

// Price Path Independent Option
template<typename pathIndependentOption>
inline double MonteCarloPricer::priceClassic(BlackScholesModel const& model, pathIndependentOption const& option) const
{
    double payoff_sum = 0.0;
    for (int i = 0; i < num_sims; i++) {
        payoff_sum += option.payoff(model.generatePrice(option.getMaturity()));
    }
    return (payoff_sum / static_cast<double>(num_sims)) * exp(-model.getRiskFreeRate() * option.getMaturity());
}

template<typename pathIndependentOption>
inline void MonteCarloPricer::priceAndPrintClassic(BlackScholesModel const& model, pathIndependentOption const& option) const
{
    model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
    option.print();
    std::cout << " Estimated price: " << priceClassic(model, option) << std::endl << std::endl;
}