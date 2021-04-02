# Option_Pricer_MonteCarlo

**Author** : Alan Loret

**Team** : ENSAE 2020-2021 C++ Group

**Reviewer** : Alan Loret

**Created on** : 10/12/2020

**Updated on** : 26/01/2020

# Problem

The objective of this project is to develop an option pricer.
There are many ways to evaluate options: the tree approach, the partial differential equation approach, ... 
Here, we focus on the Monte-Carlo approach. It consists in simulating a large number of realizations and deducing from them an approximation of the price by the law of large numbers. We place ourselves in the Black-Scholes model, which according to an interest rate parameter and a volatility parameter proposes a generation of the price trajectory. 
We use this model to simulate the evolution of the price of a fictitious underlying asset and to determine the price of an option derived from it.

# I - Program

## Structure

The program is composed of 21 files. 
We distinguish the files coding the simulation methods from the files coding the options.

Thus, 7 files are intended for the mechanics of simulation and price calculation:

- **main.cpp** is the main file containing the *main* function with some examples of use of the program.
- **BlackScholesModel.h**, **BlackScholesModel.cpp**, is a class containing the *BlackScholesModel* object allowing to generate prices, or price paths according to the Black-Scholes model.
- **MonteCarloPricer.h**, **MonteCarloPricer.cpp**, is a class containing the *MonteCarloPricer* object allowing to apply the Monte-Carlo method to estimate the option price.
- **PriceCI.h**, **PriceCI.cpp**, is a class containing the *PriceCI* object gathering the methods and attributes necessary to compute the asymptotic variance and the price.

The remaining files code the options:
- **Option.h**, **Option.cpp**, is a virtual class gathering the common methods and attributes of basic options.
- **PathIndependent.h**, **PathIndependent.cpp** , is a virtual class containing the basic structure of the options whose payoff does not depend on the path of the price.
- **PathDependent.h**, **PathDependent.cpp**, is a virtual class containing the basic structure of options whose payoff depends on the price path.
- **European.h**, **European.cpp**, is a class containing the options *EuropeanCall*, *EuropeanPut*, *BullSpread*, *BearSpread*, *Strangle* and *Butterfly*.
- **Digital.h**, **Digital.cpp**, is a class containing the options *DigitalCall*, *DigitalPut* and *DoubleDigital*.
- **Asian.h**, **Asian.cpp**, is a class containing the options *AsianArithmeticCall*, *AsianArithmeticPut*, *AsianGeometricCall* and *AsianGeometricPut*.
- **Complex.h**, **Complex.cpp**, class to generate custom options by combining ***only*** the following options *EuropeanCall*, *EuropeanPut*, *DigitalCall*, *DigitalPut*, *AsianArithmeticCall*, *AsianArithmeticPut*, *AsianGeometricCall* and *AsianGeometricPut*. We replicate, thanks to this new class, some classical options like BullSpread or BearSpread.

## Usage 

The user must specify several values to make the program work:
1. Creation of the Black Scholes model
- *S*, the current price of the underlying asset.
- *r*, the risk-free interest rate.
- *v*, the volatility.
2. Creation of the optimizer
- *N*, number of simulations in the Monte-Carlo algorithm.
- *steps* (optional), number of steps for the generation of the price path.
3.  Creation of an option
- *K*, the strike(s) of the option.
- T*, the maturity.

**Caution**: Two methods are available to calculate the price of an option: *priceAndPrint* and *priceAndPrintClassic*. 
The first one accepts all options, and generates a complete price trajectory at each iteration of the Monte-Carlo algorithm. This allows options to be evaluated according to the price trajectory. For options that do not depend on the price path, we can save time by computing only the price at maturity without generating the price path using the *priceAndPrintClassic* method. Therefore, we cannot use this method to estimate the price of an Asian option that depends on the price path nor for options created from the *Complex* class.

## Working hypothesis

An important issue in Monte Carlo simulations is the generation of random numbers. 
In particular, since we rely on the Black-Scholes model, we need to simulate a random variable that follows a normal distribution to calculate the payoffs and derive an estimate of the option price. The choice of our pseudo-random generator is therefore crucial. We have used the pseudo-random generator of the C++11 library which is more robust than the function *rand()*.

Thus, from this generator which simulates a random variable of uniform distribution on [-1,1], we use the method of inversion of the distribution function. The polar method (Box Müller) is implemented in the *gaussian_box_muller* method of the *BlackScholesModel* class.

# II - Results

The results concerning the prices of the different call options are logical: the options offering the most advantages or simply being the least risky cost more. Moreover, we obtain price values that are comparable to the results of scientific journal articles that deal with the application of the Monte-Carlo method in finance.

# III - Improvements

## Reduction of the variance
The Monte-Carlo method requires a large number of simulations to be relevant. Thus, to have estimates with an appropriate accuracy, we can increase the number of simulations, which is at the expense of an increase in computing time. We must therefore find a middle ground.

In some cases, our estimator gives very satisfactory results for execution times of the order of a second, especially for options independent of the path followed by the underlying (use the *priceAndPrintClasssic* method with N = 10 ^ 7). However, when dealing with path-dependent options, it is sometimes not possible to obtain a sufficiently narrow confidence interval in a reasonable time.

To improve the speed of convergence of our estimator we could have used another method: variance reduction. Indeed, reducing the variance of our estimator improves the speed of convergence. 
However, we have to be careful that the additional computations generated by this method do not increase the computation time too much. We thought of implementing the antithetical control method.

## Calculating Greeks

We have considered the calculation of Greeks. Unfortunately, we did not complete this part because this addition did not fit well with the structure of the program we had coded until then. Nevertheless, this feature would be desirable in a future program.

## Graphical interface 

We would have liked to code a graphical interface that would have made it easier for users to use our options pricer. Unfortunately, we ran out of time, and we realized that the library we were going to use has become a paid library.
