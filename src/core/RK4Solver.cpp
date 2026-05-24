#include "RK4Solver.h"

State RK4Solver::step(
    const State &current,
    double h,
    DifferentialSystem &system)
{

    State next;

    double k1x = h * system.f1(current.x, current.y, current.z);
    double k1y = h * system.f2(current.x, current.y, current.z);
    double k1z = h * system.f3(current.x, current.y, current.z);

    double k2x = h * system.f1(
                         current.x + k1x / 2.0,
                         current.y + k1y / 2.0,
                         current.z + k1z / 2.0);

    double k2y = h * system.f2(
                         current.x + k1x / 2.0,
                         current.y + k1y / 2.0,
                         current.z + k1z / 2.0);

    double k2z = h * system.f3(
                         current.x + k1x / 2.0,
                         current.y + k1y / 2.0,
                         current.z + k1z / 2.0);

    double k3x = h * system.f1(
                         current.x + k2x / 2.0,
                         current.y + k2y / 2.0,
                         current.z + k2z / 2.0);

    double k3y = h * system.f2(
                         current.x + k2x / 2.0,
                         current.y + k2y / 2.0,
                         current.z + k2z / 2.0);

    double k3z = h * system.f3(
                         current.x + k2x / 2.0,
                         current.y + k2y / 2.0,
                         current.z + k2z / 2.0);

    double k4x = h * system.f1(
                         current.x + k3x,
                         current.y + k3y,
                         current.z + k3z);

    double k4y = h * system.f2(
                         current.x + k3x,
                         current.y + k3y,
                         current.z + k3z);

    double k4z = h * system.f3(
                         current.x + k3x,
                         current.y + k3y,
                         current.z + k3z);

    next.x = current.x + (k1x + 2 * k2x + 2 * k3x + k4x) / 6.0;

    next.y = current.y + (k1y + 2 * k2y + 2 * k3y + k4y) / 6.0;

    next.z = current.z + (k1z + 2 * k2z + 2 * k3z + k4z) / 6.0;

    return next;
}