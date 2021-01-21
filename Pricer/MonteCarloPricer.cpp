#include "MonteCarloPricer.h"

MonteCarloPricer::MonteCarloPricer()
{
	MonteCarloPricer(1e6);
}

MonteCarloPricer::MonteCarloPricer(int const& num_sims)
{
	this->num_sims = num_sims;
}

void MonteCarloPricer::setNumSims(int const& num_sims)
{
	this->num_sims = 1e6;
}

int MonteCarloPricer::getNumSims()
{
	return num_sims;
}

