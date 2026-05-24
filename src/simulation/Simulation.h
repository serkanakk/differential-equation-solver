#pragma once

#include <vector>

#include "../core/State.h"
#include "../core/RK4Solver.h"
#include "../core/DifferentialSystem.h"

class Simulation
{

private:
    std::vector<State> states;

    DifferentialSystem &system;

public:
    Simulation(DifferentialSystem &sys);

    void run();

    const std::vector<State> &getStates() const;
};