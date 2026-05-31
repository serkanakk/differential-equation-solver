#include "HeunSolver.h"

State HeunSolver::step(
    const State &current,
    double h,
    DifferentialSystem &system)
{
    State next;

    // Predictor (Euler)

    double k1x =
        system.f1(
            current.x,
            current.y,
            current.z);

    double k1y =
        system.f2(
            current.x,
            current.y,
            current.z);

    double k1z =
        system.f3(
            current.x,
            current.y,
            current.z);

    double px =
        current.x + h * k1x;

    double py =
        current.y + h * k1y;

    double pz =
        current.z + h * k1z;

    // Corrector

    double k2x =
        system.f1(
            px,
            py,
            pz);

    double k2y =
        system.f2(
            px,
            py,
            pz);

    double k2z =
        system.f3(
            px,
            py,
            pz);

    next.x =
        current.x +
        h * (k1x + k2x) / 2.0;

    next.y =
        current.y +
        h * (k1y + k2y) / 2.0;

    next.z =
        current.z +
        h * (k1z + k2z) / 2.0;

    return next;
}