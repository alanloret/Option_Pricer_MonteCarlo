#include "MonteCarloPricer.h"
#include <iostream>

MonteCarloPricer::MonteCarloPricer()
{
	this->num_sims = 1e6;
	this->n_steps = 252;
	this->prices_vector = new std::vector<double>(252, 0);
}

MonteCarloPricer::MonteCarloPricer(int const& num_sims)
{
	this->num_sims = num_sims;
	this->n_steps = 252;
	this->prices_vector = new std::vector<double>(252, 0);
}

MonteCarloPricer::MonteCarloPricer(int const& num_sims, int const& n_steps)
{
	this->num_sims = num_sims;
	this->n_steps = n_steps;
	this->prices_vector = new std::vector<double>(n_steps, 0);
}

void MonteCarloPricer::setNumSims(int const& num_sims)
{
	this->num_sims = 1e6;
}

int MonteCarloPricer::getNumSims()
{
	return num_sims;
}

double MonteCarloPricer::priceAsian(BlackScholesModel const& model, AsianCall const& option)
{
	model.generatePath(option.getMaturity(), *prices_vector);
	
	double payoff_sum = 0.0;
	for (int i = 0; i < num_sims; i++) {
		model.generatePath(option.getMaturity(), *prices_vector);
		payoff_sum += option.payoff(*prices_vector);
		}
		return (payoff_sum / static_cast<double>(num_sims)) * exp(-model.getRiskFreeRate() * option.getMaturity());
}

void MonteCarloPricer::priceAndShowAsian(BlackScholesModel const& model, AsianCall const& option)
{
	model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
	option.print();
    if (option.getMethod() != "Arithmetic" && option.getMethod() != "Geometric") {
        std::cout << " Notimplemented - Unknown Method : " << option.getMethod() << std::endl;
        std::cout << " Method should be Arithmetic or Geometric"<< std::endl << std::endl;
    } else {
        std::cout << " Estimated price: " << priceAsian(model, option) << std::endl << std::endl;
    }
}

double MonteCarloPricer::priceAsian(BlackScholesModel const& model, AsianPut const& option)
{
    model.generatePath(option.getMaturity(), *prices_vector);

    double payoff_sum = 0.0;
    for (int i = 0; i < num_sims; i++) {
        model.generatePath(option.getMaturity(), *prices_vector);
        payoff_sum += option.payoff(*prices_vector);
    }
    return (payoff_sum / static_cast<double>(num_sims)) * exp(-model.getRiskFreeRate() * option.getMaturity());
}

void MonteCarloPricer::priceAndShowAsian(BlackScholesModel const& model, AsianPut const& option)
{
    model.print();
    std::cout << " Number of paths: " << num_sims << std::endl;
    option.print();
    if (option.getMethod() != "Arithmetic" && option.getMethod() != "Geometric") {
        std::cout << " Notimplemented - Unknown Method : " << option.getMethod() << std::endl;
        std::cout << " Method should be Arithmetic or Geometric"<< std::endl << std::endl;
    } else {
        std::cout << " Estimated price: " << priceAsian(model, option) << std::endl << std::endl;
    }
}

void MonteCarloPricer::showPrices()
{
	for (int i = 0; i < n_steps; i++) {
		std::cout << (*prices_vector)[i] << " ";
	}
	std::cout << std::endl;
}

MonteCarloPricer::~MonteCarloPricer()
{
	delete prices_vector;
}


