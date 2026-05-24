#include <fstream>
#include "Simulation.h"
#include "../core/ImpulseHandler.h"
#include <iostream>

void Simulation::run()
{
    ImpulseHandler impulseHandler;

    DifferentialSystem system;

    RK4Solver solver;

    State current;

    current.x = 1.0;
    current.y = 2.0;
    current.z = 1.0;

    double h = 0.01;

    int steps = 20;

    states.push_back(current);

    for (int i = 0; i < steps; i++)
    {

        State next = solver.step(current, h, system);
        if (impulseHandler.checkImpulse(next))
        {

            std::cout
                << "\n=== IMPULSE TRIGGERED ==="
                << std::endl;

            std::cout
                << "Before Impulse:"
                << std::endl;

            std::cout
                << "X: " << next.x
                << " Y: " << next.y
                << " Z: " << next.z
                << std::endl;

            next =
                impulseHandler.applyImpulse(next);

            std::cout
                << "After Impulse:"
                << std::endl;

            std::cout
                << "X: " << next.x
                << " Y: " << next.y
                << " Z: " << next.z
                << std::endl;

            std::cout
                << "=========================\n"
                << std::endl;
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

    file << "step,x,y,z\n";

    for (size_t i = 0; i < states.size(); i++)
    {

        file
            << i << ","
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