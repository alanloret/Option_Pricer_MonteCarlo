cmake_minimum_required(VERSION 3.17)
project(Option_Pricer_MonteCarlo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Option_Pricer_MonteCarlo
        Pricer/BlackScholesModel.cpp Pricer/BlackScholesModel.h Pricer/MonteCarloPricer.cpp Pricer/MonteCarloPricer.h
        Pricer/European.cpp Pricer/European.h Pricer/Digital.cpp Pricer/Digital.h Pricer/Asian.cpp Pricer/Asian.h
        Pricer/PathIndependentOption.cpp Pricer/PathIndependentOption.h  Pricer/PathDependentOption.cpp Pricer/PathDependentOption.h
        Pricer/Complex.cpp Pricer/Complex.h Pricer/main.cpp Pricer/PriceCI.cpp Pricer/PriceCI.h Pricer/Option.cpp
        Pricer/Option.h)
