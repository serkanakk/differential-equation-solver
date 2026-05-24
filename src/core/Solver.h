#pragma once

#include "State.h"
#include "DifferentialSystem.h"

class Solver
{
public:
    virtual State step(
        const State &current,
        double h,
        DifferentialSystem &system) = 0;
};