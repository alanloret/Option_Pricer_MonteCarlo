#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"

int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.15, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1e7); // Optimizer

    EuropeanCall eu_call = EuropeanCall(100.0, 1.0); // European Call
    EuropeanPut eu_put = EuropeanPut(100.0, 1.0); // European put
    optimizer.priceAndPrintClassic(model, eu_call);
    optimizer.priceAndPrintClassic(model, eu_put);

    DigitalCall digi_call = DigitalCall(100.0, 1.0); // Digital Call
    DigitalPut digi_put = DigitalPut(100.0, 1.0); // Digital put
    optimizer.priceAndPrintClassic(model, digi_call);
    optimizer.priceAndPrintClassic(model, digi_put);

    DoubleDigital double_digital = DoubleDigital(100.0, 120.0, 1.0); // Double Digital
    optimizer.priceAndPrintClassic(model, double_digital);

    BullSpread bull_spread = BullSpread(80.0, 120.0, 1); // BullSpread
    optimizer.priceAndPrintClassic(model, bull_spread);

    Strangle strangle = Strangle(80.0, 120.0, 1); // Strangle
    optimizer.priceAndPrintClassic(model, strangle);

    BearSpread bear_spread = BearSpread(80.0, 120.0, 1); // BearSpread
    optimizer.priceAndPrintClassic(model, bear_spread);

    Butterfly butterfly = Butterfly(80.0, 100.0, 1); // ButtterFly
    optimizer.priceAndPrintClassic(model, butterfly);


    /* For the Asian simulation we need to reduce the number of path because we need to compute an
     * arithmetic or a geometric mean which is n_steps times longer (here we take n_steps=252)*/

    BlackScholesModel model_asian = BlackScholesModel(100, 0.15, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer_asian = MonteCarloPricer(1e4, 252); // Optimizer

    AsianArithmeticCall asian_arithmetic_call = AsianArithmeticCall(100.0, 1.0); // Asian Arithmetic Call
    AsianArithmeticPut asian_arithmetic_put = AsianArithmeticPut(100.0, 1.0); // Asia Arithmetic Put
    optimizer_asian.priceAndPrintComplex(model_asian, asian_arithmetic_call);
    optimizer_asian.priceAndPrintComplex(model_asian, asian_arithmetic_put);

    AsianGeometricCall asian_geometric_call = AsianGeometricCall(100.0, 1.0); // Asian Geometric Call
    AsianGeometricPut asian_geometric_put = AsianGeometricPut(100.0, 1.0); // Asian Geometric Put
    optimizer_asian.priceAndPrintComplex(model_asian, asian_geometric_call);
    optimizer_asian.priceAndPrintComplex(model_asian, asian_geometric_put);

}
