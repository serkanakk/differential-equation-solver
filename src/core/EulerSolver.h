#pragma once

#include "Solver.h"

class EulerSolver : public Solver
{
public:
    State step(
        const State &current,
        double h,
        DifferentialSystem &system) override;
};