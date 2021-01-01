//
// Created by Alan Loret on 01/01/2021.
//

#ifndef PRICER_MONTECARLO_TOOLS_H
#define PRICER_MONTECARLO_TOOLS_H

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

#endif //PRICER_MONTECARLO_TOOLS_H
