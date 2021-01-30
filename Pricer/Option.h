#pragma once
class Option
{
public:
	Option();
	Option(double const& K, double const& T);
	void setStrike(double const& K);
	void setMaturity(double const& T);
	void setMultiplier(double const& multiplier);

	double getStrike() const;
	double getMaturity() const;
	double getMultiplier() const;

	virtual void print() const;
	~Option();

private:
	double K;
	double T;
	double multiplier = 1.0; // 1 for long position and -1 for short
};

