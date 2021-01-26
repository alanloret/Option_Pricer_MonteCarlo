#include "BlackScholesModel.h"
#include <random>
#include <iostream>
#include <cmath>

// Define our Uniform random generator on [-1,1]
std::random_device rd; // Define our seed rd
std::mt19937 mt(rd()); // Seed the random number generator mt
std::uniform_real_distribution<double> dist(-1.0, 1.0); // Create our random variable

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

    for (int i = 1; i < static_cast<int>(prices.size()); i++) {
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

double BlackScholesModel::gaussian_box_muller()
{
    double x;
    double y;
    double euclid_sq;

    // Continue generating two uniform random variables
    // until the square of their "euclidean distance"
    // is less than unity
    do {
        x = dist(mt);
        y = dist(mt);
        euclid_sq = x * x + y * y;
    } while (euclid_sq >= 1.0);

    return x * sqrt(-2 * log(euclid_sq) / euclid_sq);
}