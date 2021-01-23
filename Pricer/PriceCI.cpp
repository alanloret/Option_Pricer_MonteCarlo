#include "PriceCI.h"
#include <iostream>
#include <cmath>


PriceCI::PriceCI() {
    this->price = 0.0;
    this->stdev = 0.0;
    this->num_sims = 1;
}
PriceCI::PriceCI(const double& price, const double& stdev, const int& num_sims) {
    this->price = price;
    this->stdev = stdev;
    this->num_sims = num_sims;
}

double PriceCI::compute_lb() const {
    return price - sqrt(stdev / static_cast<double>(num_sims)) * 1.960;
}

double PriceCI::compute_ub() const {
    return price + sqrt(stdev / static_cast<double>(num_sims)) * 1.960;
}

void PriceCI::print_CI() const {
    double lb = compute_lb();
    double ub = compute_ub();
    std::cout << " Estimated price: " << price << std::endl;
    std::cout << " Confidence Interval at level 95% : ";
    std::cout << "[" << lb << " , " << ub << "]" << std::endl << std::endl;
}