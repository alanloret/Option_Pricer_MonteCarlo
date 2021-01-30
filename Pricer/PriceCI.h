#pragma once
class PriceCI
{
public:
    PriceCI();
    PriceCI(double const& price, double const& stdev, int const& num_sims);
    void print_CI() const;
    void set_price(double const& price) { this->price = price; };
    void set_stdev(double const& stdev) { this->stdev = stdev; };
    void set_num_sims(int const& num_sims) { this->num_sims = num_sims; };
    double get_lb() const { return compute_lb(); };
    double get_ub() const { return compute_ub(); };
    double getPrice() const { return price; };
    double getStdev() const { return stdev; };

private:
    double price;
    double stdev;
    int  num_sims;
    double compute_lb() const; // Compute lower bound of confidence interval
    double compute_ub() const; // Compute upper bound of confidence interval
};