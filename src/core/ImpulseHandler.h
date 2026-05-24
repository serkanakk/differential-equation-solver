#pragma once

#include "State.h"

class ImpulseHandler
{

private:
    double K = 5.0;

public:
    bool checkImpulse(const State &s);

    State applyImpulse(const State &s);
};