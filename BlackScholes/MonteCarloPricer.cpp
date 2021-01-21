#include "MonteCarloPricer.h"
#include <iostream>


MonteCarloPricer::MonteCarloPricer()
{
	MonteCarloPricer(1000);
}

MonteCarloPricer::MonteCarloPricer(int const& num_sims)
{
	this->num_sims = num_sims;
}

void MonteCarloPricer::setNumSims(int const& num_sims)
{
	this->num_sims = 1000;
}

int MonteCarloPricer::getNumSims()
{
	return num_sims;
}


