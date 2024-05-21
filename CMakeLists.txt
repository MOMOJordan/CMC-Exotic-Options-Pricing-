cmake_minimum_required(VERSION 3.26)
project(dailyC)

set(CMAKE_CXX_STANDARD 17)

add_executable(dailyC main.cpp
        matrix.cpp
        UpAndOutOption.h
        UpAndOutOption.cpp
        BlackScholesModel.cpp
        mathlib.h
        mathlib.cpp
        RealFunction.cpp
        ContinuousTimeOptionBase.cpp
        ContinuousTimeOption.cpp
        MonteCarloPricer.cpp
        KnockoutOption.cpp)
