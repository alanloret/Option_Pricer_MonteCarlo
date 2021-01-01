//
// Created by Alan Loret on 01/01/2021.
//

#ifndef PRICER_MONTECARLO_TOOLS_H
#define PRICER_MONTECARLO_TOOLS_H

double gaussian_box_muller() {
    double x;
    double y;
    double euclid_sq;

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

double heaviside(const double& val) {
    if (val >= 0) {
        return 1.0;
    } else {
        return 0.0;
    }
}

#endif //PRICER_MONTECARLO_TOOLS_H
