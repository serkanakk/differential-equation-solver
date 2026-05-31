#include "simulation/Simulation.h"

#include <iostream>
#include "core/Solver.h"
#include "core/EulerSolver.h"
#include "core/HeunSolver.h"
#include "core/RK4Solver.h"

int main()
{

    std::string eq1;
    std::string eq2;
    std::string eq3;

    std::cout << "Enter f1(x,y,z): ";
    std::cin >> eq1;

    std::cout << "Enter f2(x,y,z): ";
    std::cin >> eq2;

    std::cout << "Enter f3(x,y,z): ";
    std::cin >> eq3;

    DifferentialSystem system(
        eq1,
        eq2,
        eq3);

    int choice;

    std::cout << "\nChoose Method:\n";
    std::cout << "1 - Euler\n";
    std::cout << "2 - Heun\n";
    std::cout << "3 - RK4\n";

    std::cin >> choice;

    Solver *solver = nullptr;

    if (choice == 1)
    {
        solver = new EulerSolver();
    }
    else if (choice == 2)
    {
        solver = new HeunSolver();
    }
    else
    {
        solver = new RK4Solver();
    }

    Simulation simulation(
        system,
        solver);

    simulation.run();
    delete solver;
    return 0;
}