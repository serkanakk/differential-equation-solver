include_directories(
    src
    external
)

cmake_minimum_required(VERSION 3.10)

project(DifferentialEquationSolver)

set(CMAKE_CXX_STANDARD 17)
add_executable(
    solver

    src/main.cpp

    src/core/DifferentialSystem.cpp
    src/core/RK4Solver.cpp
    src/core/EulerSolver.cpp
    src/core/HeunSolver.cpp
    src/core/ImpulseHandler.cpp

    src/simulation/Simulation.cpp

    src/database/DatabaseManager.cpp

    src/server/WebServer.cpp

    external/sqlite3.c
)
target_compile_options(solver PRIVATE /bigobj)