cmake_minimum_required(VERSION 3.17)
project(BlackScholes)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlackScholes BlackScholes/main.cpp BlackScholes/BlackScholesModel.cpp BlackScholes/BlackScholesModel.h
        BlackScholes/European.cpp BlackScholes/European.h BlackScholes/MonteCarloPricer.cpp BlackScholes/MonteCarloPricer.h
        BlackScholes/PathIndependentOption.cpp BlackScholes/PathIndependentOption.h BlackScholes/Digital.cpp
        BlackScholes/Digital.h)
