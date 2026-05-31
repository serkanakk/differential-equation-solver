#pragma once

#include <vector>

#include "../core/State.h"
// #include "../core/RK4Solver.h"
#include "../core/DifferentialSystem.h"
#include "../core/Solver.h"

class Simulation
{

private:
    std::vector<State> states;

    DifferentialSystem &system;

    Solver *solver;

public:
    Simulation(
        DifferentialSystem &sys,
        Solver *selectedSolver);

    void run();

    const std::vector<State> &getStates() const;
};