cmake_minimum_required(VERSION 3.17)
project(Pricer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Option_Pricer_MonteCarlo Pricer/main.cpp Pricer/BlackScholesModel.cpp Pricer/BlackScholesModel.h
        Pricer/European.cpp Pricer/European.h Pricer/MonteCarloPricer.cpp Pricer/MonteCarloPricer.h
        Pricer/Digital.cpp Pricer/Digital.h Pricer/Asian.cpp Pricer/Asian.h Pricer/PathIndependentOption.cpp
        Pricer/PathIndependentOption.h  Pricer/PathDependentOption.cpp Pricer/PathDependentOption.h)
