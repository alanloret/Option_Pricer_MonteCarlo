
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"

int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.05, 0.1); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1e7); // Optimizer

    EuropeanCall call = EuropeanCall(110.0, 1.0);
    EuropeanPut put = EuropeanPut(110.0, 1.0);
    optimizer.priceAndPrint(model, call);
    optimizer.priceAndPrint(model, put);

    DigitalCall digi_call = DigitalCall(110.0, 1.0);
    DigitalPut digi_put = DigitalPut(110.0, 1.0);
    optimizer.priceAndPrint(model, digi_call);
    optimizer.priceAndPrint(model, digi_put);

}
