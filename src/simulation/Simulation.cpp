#include "Simulation.h"

#include "../core/ImpulseHandler.h"

#include <iostream>
#include <fstream>

Simulation::Simulation(
    DifferentialSystem &sys,
    Solver *selectedSolver)
    : system(sys),
      solver(selectedSolver)
{
}

void Simulation::run()
{

    ImpulseHandler impulseHandler;

    State current;

    current.x = 1.0;
    current.y = 2.0;
    current.z = 1.0;

    double h = 0.01;

    int steps = 20;

    states.push_back(current);

    for (int i = 0; i < steps; i++)
    {

        State next =
            solver->step(current, h, system);

        if (impulseHandler.checkImpulse(next))
        {

            std::cout
                << "\n=== IMPULSE TRIGGERED ==="
                << std::endl;

            next =
                impulseHandler.applyImpulse(next);
        }

        states.push_back(next);

        current = next;
    }

    for (size_t i = 0; i < states.size(); i++)
    {

        std::cout
            << "Step " << i
            << " X: " << states[i].x
            << " Y: " << states[i].y
            << " Z: " << states[i].z
            << std::endl;
    }

    std::ofstream file("results.csv");

    file << "step,time,x,y,z\n";

    for (size_t i = 0; i < states.size(); i++)
    {

        double time = i * h;

        file
            << i << ","
            << time << ","
            << states[i].x << ","
            << states[i].y << ","
            << states[i].z
            << "\n";
    }

    file.close();
}

const std::vector<State> &Simulation::getStates() const
{

    return states;
}