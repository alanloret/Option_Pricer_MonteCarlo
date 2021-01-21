
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"

int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.05, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1e7); // Optimizer

    EuropeanCall call = EuropeanCall(100.0, 1.0);
    EuropeanPut put = EuropeanPut(100.0, 1.0);
    optimizer.priceAndPrint(model, call);
    optimizer.priceAndPrint(model, put);

    DigitalCall digi_call = DigitalCall(100.0, 1.0);
    DigitalPut digi_put = DigitalPut(100.0, 1.0);
    optimizer.priceAndPrint(model, digi_call);
    optimizer.priceAndPrint(model, digi_put);

    /*
    AsianCall call = AsianCall(100.0, 1.0);
    AsianPut put = AsianPut(100.0, 1.0);
    optimizer.priceAndPrint(model, call);
    optimizer.priceAndPrint(model, put);
     */

}
