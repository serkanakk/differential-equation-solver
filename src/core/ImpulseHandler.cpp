#include "ImpulseHandler.h"

bool ImpulseHandler::checkImpulse(const State &s)
{

    double value =
        s.x * s.x +
        s.y * s.y;

    return value >= K;
}

State ImpulseHandler::applyImpulse(const State &s)
{

    State updated;

    double a = 0.5;
    double b = 0.8;
    double c = 0.2;
    double d = 0.7;
    double e = 0.1;

    updated.x = a * s.x;

    updated.y =
        b * s.y - c * s.z;

    updated.z =
        d * s.z + e * s.x * s.x;

    return updated;
}