#include "EulerSolver.h"

State EulerSolver::step(
    const State &current,
    double h,
    DifferentialSystem &system)
{
    State next;

    next.x =
        current.x +
        h * system.f1(
                current.x,
                current.y,
                current.z);

    next.y =
        current.y +
        h * system.f2(
                current.x,
                current.y,
                current.z);

    next.z =
        current.z +
        h * system.f3(
                current.x,
                current.y,
                current.z);

    return next;
}