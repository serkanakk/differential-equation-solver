#pragma once

#include <vector>
#include <string>
#include "../core/State.h"
#include "../core/DifferentialSystem.h"
#include "../core/Solver.h"

class Simulation
{

private:
    std::vector<State> states;

    DifferentialSystem &system;

    Solver *solver;

    std::string methodName;

public:
    Simulation(
        DifferentialSystem &sys,
        Solver *selectedSolver,
        const std::string &method);

    void run();

    const std::vector<State> &getStates() const;
};