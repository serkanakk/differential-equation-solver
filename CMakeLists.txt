cmake_minimum_required(VERSION 3.10)

project(DifferentialEquationSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    solver

    src/main.cpp
    src/core/DifferentialSystem.cpp
    src/core/RK4Solver.cpp
    src/simulation/Simulation.cpp
    src/core/ImpulseHandler.cpp
)