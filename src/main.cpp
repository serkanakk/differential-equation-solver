#include "simulation/Simulation.h"

#include <iostream>

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

    Simulation simulation(system);

    simulation.run();

    return 0;
}