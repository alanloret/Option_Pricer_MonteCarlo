#include <iostream>
#include "vanilla.h"
#include "digital.h"

int main(int argc, char **argv) {
    // First we create the parameter list
    int num_sims = 1e7;   // Number of simulated asset paths
    double S = 100.0;  // Option price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate
    double v = 0.2;    // Volatility of the underlying
    double T = 1.0;    // Number of year until expiry

    // Then we calculate the call/put values via Monte Carlo
    double call = 0.0;
    double put = 0.0;
    /*
    double call = monte_carlo_call_price(num_sims, S, K, r, v, T);
    double put = monte_carlo_put_price(num_sims, S, K, r, v, T);

    double call = monte_carlo_digital_call_price(num_sims, S, K, r, v, T);
    double put = monte_carlo_digital_put_price(num_sims, S, K, r, v, T);
    */

    // Finally we output the parameters and prices
    std::cout << "Number of Paths: " << num_sims << std::endl;
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << v << std::endl;
    std::cout << "Maturity:        " << T << std::endl;

    std::cout << "Call Price:      " << call << std::endl;
    std::cout << "Put Price:       " << put << std::endl;

    return 0;
}
