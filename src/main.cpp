#include "simulation/Simulation.h"

#include <iostream>
#include "core/Solver.h"
#include "core/EulerSolver.h"
#include "core/HeunSolver.h"
#include "core/RK4Solver.h"
#include "database/DatabaseManager.h"

int main()
{
    DatabaseManager database;

    database.connect("../../database/solver.db");

    int choice;

    std::cout << "\n===== DIFFERENTIAL SOLVER =====\n";
    std::cout << "1 - Register\n";
    std::cout << "2 - Login\n";
    std::cout << "3 - Exit\n";

    std::cin >> choice;

    if (choice == 3)
    {
        return 0;
    }

    if (choice == 1)
    {
        std::string username;
        std::string email;
        std::string password;

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Email: ";
        std::cin >> email;

        std::cout << "Password: ";
        std::cin >> password;

        database.registerUser(
            username,
            email,
            password);

        return 0;
    }

    if (choice == 2)
    {
        std::string username;
        std::string password;

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        bool loginSuccess =
            database.loginUser(
                username,
                password);

        if (!loginSuccess)
        {
            std::cout
                << "Login failed!"
                << std::endl;

            return 0;
        }

        std::cout
            << "Login successful!"
            << std::endl;
    }

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

    int methodChoice;

    std::cout << "\nChoose Method:\n";
    std::cout << "1 - Euler\n";
    std::cout << "2 - Heun\n";
    std::cout << "3 - RK4\n";

    std::cin >> methodChoice;

    Solver *solver = nullptr;
    std::string methodName;

    if (methodChoice == 1)
    {
        solver = new EulerSolver();
        methodName = "Euler";
    }
    else if (methodChoice == 2)
    {
        solver = new HeunSolver();
        methodName = "Heun";
    }
    else
    {
        solver = new RK4Solver();
        methodName = "RK4";
    }

    Simulation simulation(
        system,
        solver,
        methodName);

    simulation.run();

    delete solver;

    return 0;
}