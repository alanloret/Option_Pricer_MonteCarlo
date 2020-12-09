//
// Created by Alan Loret on 10/12/2020.
//

#ifndef PRICER_MONTECARLO_VANILLA_H
#define PRICER_MONTECARLO_VANILLA_H

#include <algorithm>    // Needed for the "max" function
#include <cmath>

// A simple implementation of the Box-Muller algorithm, used to generate
// gaussian random numbers - necessary for the Monte Carlo method below
// Note that C++11 actually provides std::normal_distribution<> in
// the <random> library, which can be used instead of this function

double gaussian_box_muller() {
    double x = 0.0;
    double y = 0.0;
    double euclid_sq = 0.0;

    // Continue generating two uniform random variables
    // until the square of their "euclidean distance"
    // is less than unity
    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        euclid_sq = x*x + y*y;
    } while (euclid_sq >= 1.0);

    return x*sqrt(-2*log(euclid_sq)/euclid_sq);
}

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
