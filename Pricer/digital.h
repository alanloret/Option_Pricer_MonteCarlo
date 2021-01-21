//
// Created by Alan Loret on 01/01/2021.
//

#ifndef PRICER_MONTECARLO_DIGITAL_H
#define PRICER_MONTECARLO_DIGITAL_H

#include <cmath>
#include <iostream>
#include"tools.h"

// This is the Heaviside step function, named after English
// mathematician Oliver Heaviside. It returns unity when val
// is greater than or equal to zero and returns zero otherwise
double heaviside(const double& val) {
    if (val >= 0) {
        return 1.0;
    } else {
        return 0.0;
    }
}

// Pricing a digital call option with a Monte Carlo method
double monte_carlo_digital_call_price(const int& num_sims, const double& S, const double& K, const double& r, const double& v, const double& T) {
    double S_adjust = S * exp(T*(r-0.5*v*v));
    double S_cur = 0.0;
    double payoff_sum = 0.0;

    for (int i=0; i<num_sims; i++) {
        double gauss_bm = gaussian_box_muller();
        S_cur = S_adjust * exp(sqrt(v*v*T)*gauss_bm);
        payoff_sum += heaviside(S_cur - K);
    }

    return (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);
}

// Pricing a digital put option with a Monte Carlo method
double monte_carlo_digital_put_price(const int& num_sims, const double& S, const double& K, const double& r, const double& v, const double& T) {
    double S_adjust = S * exp(T*(r-0.5*v*v));
    double S_cur = 0.0;
    double payoff_sum = 0.0;

    for (int i=0; i<num_sims; i++) {
        double gauss_bm = gaussian_box_muller();
        S_cur = S_adjust * exp(sqrt(v*v*T)*gauss_bm);
        payoff_sum += heaviside(K - S_cur);
    }

    return (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);
}

#endif //PRICER_MONTECARLO_DIGITAL_H
