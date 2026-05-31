#pragma once

#include "Solver.h"

class HeunSolver : public Solver
{
public:
    State step(
        const State &current,
        double h,
        DifferentialSystem &system) override;
};