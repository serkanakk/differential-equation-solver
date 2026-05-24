#include "DifferentialSystem.h"

double DifferentialSystem::f1(double x, double y, double z)
{
    return x + y;
}

double DifferentialSystem::f2(double x, double y, double z)
{
    return y - z;
}

double DifferentialSystem::f3(double x, double y, double z)
{
    return x * z;
}