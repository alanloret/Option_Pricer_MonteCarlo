#pragma once
class PathIndependentOption
{
public:
	PathIndependentOption();
	PathIndependentOption(double const& K, double const& T);

	void setStrike(double const& K);
	void setMaturity(double const& T);

	double getStrike() const;
	double getMaturity() const;

	virtual double payoff(double const& S) const;
	virtual ~PathIndependentOption();

    virtual void print() const;

private:
	double K;
	double T;

};

