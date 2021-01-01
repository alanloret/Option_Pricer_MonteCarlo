cmake_minimum_required(VERSION 3.17)
project(Pricer_MonteCarlo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pricer_MonteCarlo Pricer/main.cpp Pricer/vanilla.h Pricer/digital.h
        Pricer/tools.h Pricer/asian.h Pricer/payoff.h)
