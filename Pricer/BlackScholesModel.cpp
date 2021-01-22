#include "BlackScholesModel.h"
#include <iostream>
#include <cmath>

BlackScholesModel::BlackScholesModel()
{
    this->S = 100;
    this->r = 0.05;
    this->v = 0.2;
}

BlackScholesModel::BlackScholesModel(double const& S, double const& r, double const& v)
{
	this->S = S;
	this->r = r;
	this->v = v;
}

double BlackScholesModel::generatePrice(double const& T) const
{
    double S_adjust = S * exp(T * (r - 0.5 * v * v));
    double gauss_bm = gaussian_box_muller();
    return S_adjust * exp(sqrt(v * v * T) * gauss_bm);
}

void BlackScholesModel::generatePath(double const& T, std::vector<double>& prices) const
{
    double dt = T / static_cast<double>(prices.size());
    double drift = exp(dt * (r - 0.5 * v * v));
    double vol = sqrt(v * v * dt);

    prices[0] = this->getStartingPrice();

    for (int i = 1; i < prices.size(); i++) {
        double gauss_bm = gaussian_box_muller();
        prices[i] = prices[i - 1] * drift * exp(vol * gauss_bm);
    }
}

double BlackScholesModel::getStartingPrice() const
{
    return S;
}

double BlackScholesModel::getRiskFreeRate() const
{
    return r;
}

double BlackScholesModel::getVolatility() const
{
    return v;
}

void BlackScholesModel::print() const
{
    std::cout << "--- Black Scholes Model ---" << std::endl;
    std::cout << " Starting price:  " << S << std::endl;
    std::cout << " Risk Free Rate:  " << r << std::endl;
    std::cout << " Volatility:      " << v << std::endl;
}

double BlackScholesModel::gaussian_box_muller() const
{
    double x;
    double y;
    double euclid_sq;

    // Continue generating two uniform random variables
    // until the square of their "euclidean distance"
    // is less than unity
    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        euclid_sq = x * x + y * y;
    } while (euclid_sq >= 1.0 || euclid_sq == 0);

    return x * sqrt(-2 * log(euclid_sq) / euclid_sq);
}
