#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"
#include "Complex.h"


int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.05, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1e5); // Optimizer

    EuropeanCall eu_call = EuropeanCall(100.0, 1.0); // European Call
    optimizer.priceAndPrintClassic(model, eu_call);
    EuropeanPut eu_put = EuropeanPut(100.0, 1.0); // European Put
    optimizer.priceAndPrintClassic(model, eu_put);

    DigitalCall digital_call = DigitalCall(100.0, 1.0); // Digital Call
    optimizer.priceAndPrintClassic(model, digital_call);
    DigitalPut digital_put = DigitalPut(100.0, 1.0); // Digital Put
    optimizer.priceAndPrintClassic(model, digital_put);

    AsianArithmeticCall asian_arithmetic_call = AsianArithmeticCall(100.0, 1.0); // Asian Arithmetic Call
    optimizer.priceAndPrintComplex(model, asian_arithmetic_call);
    AsianArithmeticPut asian_arithmetic_put = AsianArithmeticPut(100.0, 1.0); // Asian Arithmetic Put
    optimizer.priceAndPrintComplex(model, asian_arithmetic_put);

    AsianGeometricCall asian_geometric_call = AsianGeometricCall(100.0, 1.0); // Asian Geometric Call
    optimizer.priceAndPrintComplex(model, asian_geometric_call);
    AsianGeometricPut asian_geometric_put = AsianGeometricPut(100.0, 1.0); // Asian Geometric Put
    optimizer.priceAndPrintComplex(model, asian_geometric_put);

    DoubleDigital double_digital = DoubleDigital(80.0, 120.0, 1.0); // Double Digital
    optimizer.priceAndPrintClassic(model, double_digital);

    BullSpread bull_spread = BullSpread(80.0, 120.0, 1.0); // Bullspread
    optimizer.priceAndPrintClassic(model, bull_spread);

    BearSpread bear_spread = BearSpread(80.0, 120.0, 1.0); // BearSpread
    optimizer.priceAndPrintClassic(model, bear_spread);

    Butterfly butterfly = Butterfly(80.0, 120.0, 1.0); //Butterfly
    optimizer.priceAndPrintClassic(model, butterfly);


    Complex custom_option = Complex("Customized option");
    /* The repartition of this customized option :
     - 25% Long European Call
     - 25% Long Asian Arithmetic Put
     - 50% Short Double Digital

     Total number of Options purchased: 200 000 */

    custom_option.buyOption(eu_call, 0.25);  // Buy European Call
    custom_option.buyOption(asian_arithmetic_put, 0.25); // Buy 3 Asian Arithmetic Put
    custom_option.buyOption(digital_put, -0.5); // Sell Double digital Option

    custom_option.setMultiplier(200000.0); // Set the total number of options
    optimizer.priceAndPrint(model, custom_option);

    return 0;

}
