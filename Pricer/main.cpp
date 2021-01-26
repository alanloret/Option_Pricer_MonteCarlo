#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"
#include "Complex.h"

int main()
{
    double starting_price = 100.0;
    double risk_free_rate = 0.05;
    double volatility = 0.2;
    BlackScholesModel model(starting_price, risk_free_rate, volatility); // Model to simulate prices

    double T = 1.0; // Maturity
    int num_sims = 1e4;
    int n_steps = 250; // Number of steps in the path generation process
    MonteCarloPricer optimizer(num_sims, n_steps); // Optimizer

    EuropeanCall eu_call(100.0, T); // European Call
    optimizer.priceAndPrintClassic(model, eu_call);
    EuropeanPut eu_put(100.0, T); // European Put
    optimizer.priceAndPrintClassic(model, eu_put);

    BullSpread bull_spread(100.0, 120.0, T); // Bullspread
    optimizer.priceAndPrintClassic(model, bull_spread);

    BearSpread bear_spread(80.0, 100.0, T); // BearSpread
    optimizer.priceAndPrintClassic(model, bear_spread);

    Butterfly butterfly(100.0, 120.0, T); // Butterfly
    optimizer.priceAndPrintClassic(model, butterfly);

    Strangle strangle(100.0, 120.0, T); //Strangle
    optimizer.priceAndPrintClassic(model, strangle);

    DigitalCall digital_call(100.0, T); // Digital Call
    optimizer.priceAndPrintClassic(model, digital_call);
    DigitalPut digital_put(100.0, T); // Digital Put
    optimizer.priceAndPrintClassic(model, digital_put);

    DoubleDigital double_digital(100.0, 120.0, T); // Double Digital
    optimizer.priceAndPrintClassic(model, double_digital);

    AsianArithmeticCall asian_arithmetic_call(100.0, T); // Asian Arithmetic Call
    optimizer.priceAndPrint(model, asian_arithmetic_call);
    AsianArithmeticPut asian_arithmetic_put(100.0, T); // Asian Arithmetic Put
    optimizer.priceAndPrint(model, asian_arithmetic_put);

    AsianGeometricCall asian_geometric_call(100.0, T); // Asian Geometric Call
    optimizer.priceAndPrint(model, asian_geometric_call);
    AsianGeometricPut asian_geometric_put(100.0, T); // Asian Geometric Put
    optimizer.priceAndPrint(model, asian_geometric_put);

    Complex custom_option("Customized option");
    /* The repartition of this customized option :
     - 1 Long European Call
     - 1 Long Asian Arithmetic Put
     - 3 Short Digital Call
     Total number of Options purchased: 50 000 */

    DigitalCall triple_digital_call(120.0, T); // Create a triple digitalCall
    triple_digital_call.setMultiplier(3.0);
    
    custom_option += eu_call ; // Buy European Call
    custom_option += asian_arithmetic_put; // Buy Asian Arithmetic Put
    custom_option -= triple_digital_call; // Sell triple digital Call

    custom_option *= 50000.0; // Set the total number of options
    optimizer.priceAndPrint(model, custom_option);

    /* If you want to test if our class Complex option is correct, you can compare the value of the
     the direct computation of bullspread, bearspread, strangle and butterfly with the following command :

    // Bullspread = Buy Call K1 and Sell Call K2 (k1 < K2)
    BullSpreadComplex bull_spread_complex(100.0, 120.0, T);
    optimizer.priceAndPrint(model, bull_spread_complex);

    // Bearspread = Sell Call K1 and Buy Call K2 (k1 < K2)
    BearSpreadComplex bear_spread_complex(100.0, 120.0, T);
    optimizer.priceAndPrint(model, bear_spread_complex);

    // Strangle = Buy Put K1 and Buy Call K2 (K1 < K2)
    StrangleComplex strangle_complex(100.0, 120.0, T);
    optimizer.priceAndPrint(model, strangle_complex);

    // Butterfly = Buy Call K1, Buy Call K2 and Sell 2 Call (K1 + K2)/2 (K1 < K2)
    ButterflyComplex butterfly_complex(100.0, 120.0, T);
    optimizer.priceAndPrint(model, butterfly_complex);
     */

    return 0;
}