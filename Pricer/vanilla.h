//
// Created by Alan Loret on 10/12/2020.
//

#ifndef PRICER_MONTECARLO_VANILLA_H
#define PRICER_MONTECARLO_VANILLA_H

#include <algorithm>    // Needed for the "max" function
#include <cmath>
#include"tools.h"

// Pricing a European vanilla call option with a Monte Carlo method
double monte_carlo_call_price(const int& num_sims, const double& S, const double& K, const double& r, const double& v, const double& T) {
    double S_adjust = S * exp(T*(r-0.5*v*v));
    double S_cur = 0.0;
    double payoff_sum = 0.0;

    for (int i=0; i<num_sims; i++) {
        double gauss_bm = gaussian_box_muller();
        S_cur = S_adjust * exp(sqrt(v*v*T)*gauss_bm);
        payoff_sum += std::max(S_cur - K, 0.0);
    }

    return (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);
}

// Pricing a European vanilla put option with a Monte Carlo method
double monte_carlo_put_price(const int& num_sims, const double& S, const double& K, const double& r, const double& v, const double& T) {
    double S_adjust = S * exp(T*(r-0.5*v*v));
    double S_cur = 0.0;
    double payoff_sum = 0.0;

    for (int i=0; i<num_sims; i++) {
        double gauss_bm = gaussian_box_muller();
        S_cur = S_adjust * exp(sqrt(v*v*T)*gauss_bm);
        payoff_sum += std::max(K - S_cur, 0.0);
    }

    return (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);
}

#endif //PRICER_MONTECARLO_VANILLA_H
