#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"

int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.15, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1e7); // Optimizer

    EuropeanCall eu_call = EuropeanCall(100.0, 1.0); // European Call option
    EuropeanPut eu_put = EuropeanPut(100.0, 1.0); // European put
    optimizer.priceAndPrint(model, eu_call);
    optimizer.priceAndPrint(model, eu_put);

    DigitalCall digi_call = DigitalCall(100.0, 1.0); // Digital Call
    DigitalPut digi_put = DigitalPut(100.0, 1.0); // Digital put
    optimizer.priceAndPrint(model, digi_call);
    optimizer.priceAndPrint(model, digi_put);

    /* For the ASian simulation we need to reduce the number of path because we need to compute an
     * arithmetic or a geometric mean which is n_steps times longer (here we take n_steps=252)*/

    BlackScholesModel model_asian = BlackScholesModel(100, 0.15, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer_asian = MonteCarloPricer(1e5, 252); // Optimizer

    AsianCall asian_arithm_call = AsianCall(100.0, 1.0,"Arithmetic"); // Asian Arithmetic Call
    AsianPut asian_arithm_put = AsianPut(100.0, 1.0, "Arithmetic"); // Asia Arithmetic Put
    optimizer_asian.priceAndShowAsian(model_asian, asian_arithm_call);
    optimizer_asian.priceAndShowAsian(model_asian, asian_arithm_put);

    AsianCall asian_geo_call = AsianCall(100.0, 1.0, "Geometric"); // Asian Geometric Call
    AsianPut asian_geo_put = AsianPut(100.0, 1.0, "Geometric"); // Asian Geometric Put
    optimizer_asian.priceAndShowAsian(model_asian, asian_geo_call);
    optimizer_asian.priceAndShowAsian(model_asian, asian_geo_put);

}
