// BlackScholes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"

int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.05, 0.2); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1e6); // Optimizer

    EuropeanCall call = EuropeanCall(100.0, 1.0); // European Call option
    EuropeanPut put = EuropeanPut(100.0, 1.0); // European put
    optimizer.priceAndPrint(model, call);
    optimizer.priceAndPrint(model, put);

    DigitalCall digi_call = DigitalCall(100.0, 1.0);
    DigitalPut digi_put = DigitalPut(100.0, 1.0);
    optimizer.priceAndPrint(model, digi_call);
    optimizer.priceAndPrint(model, digi_put);

    AsianCall asian_call = AsianCall(100.0, 1.0);
    AsianPut asian_put = AsianPut(100.0, 1.0);
    optimizer.priceAndShowAsian(model, asian_call);
    optimizer.priceAndShowAsian(model, asian_put);



}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
