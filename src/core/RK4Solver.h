#pragma once

#include "Solver.h"

class RK4Solver : public Solver
{

public:
    State step(
        const State &current,
        double h,
        DifferentialSystem &system) override;
};