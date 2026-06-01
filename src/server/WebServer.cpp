#include "WebServer.h"
#include "../../external/httplib.h"
#include "../database/DatabaseManager.h"

#include "../core/DifferentialSystem.h"
#include "../core/EulerSolver.h"
#include "../core/HeunSolver.h"
#include "../core/RK4Solver.h"
#include "../simulation/Simulation.h"

#include <sstream>
#include <iostream>

void WebServer::start()
{
    httplib::Server server;
    DatabaseManager database;

    database.connect(
        "../../database/solver.db");

    server.Get(
        "/",
        [](const httplib::Request &req,
           httplib::Response &res)
        {
            res.set_content(
                "Differential Equation Solver API",
                "text/plain");
        });

    server.Get(
        "/test",
        [](const httplib::Request &req,
           httplib::Response &res)
        {
            res.set_content(
                "Test successful",
                "text/plain");
        });

    server.Options(
        "/login",
        [](const httplib::Request &req,
           httplib::Response &res)
        {
            res.set_header(
                "Access-Control-Allow-Origin",
                "*");

            res.set_header(
                "Access-Control-Allow-Methods",
                "POST, OPTIONS");

            res.set_header(
                "Access-Control-Allow-Headers",
                "Content-Type");

            res.status = 200;
        });

    server.Post(
        "/login",
        [&](const httplib::Request &req,
            httplib::Response &res)
        {
            res.set_header(
                "Access-Control-Allow-Origin",
                "*");

            std::string username =
                req.get_param_value(
                    "username");

            std::string password =
                req.get_param_value(
                    "password");

            bool success =
                database.loginUser(
                    username,
                    password);

            if (success)
            {
                res.set_content(
                    "Login successful",
                    "text/plain");
            }
            else
            {
                res.set_content(
                    "Login failed",
                    "text/plain");
            }
        });

    server.Options(
        "/register",
        [](const httplib::Request &req,
           httplib::Response &res)
        {
            res.set_header(
                "Access-Control-Allow-Origin",
                "*");

            res.set_header(
                "Access-Control-Allow-Methods",
                "POST, OPTIONS");

            res.set_header(
                "Access-Control-Allow-Headers",
                "Content-Type");

            res.status = 200;
        });

    server.Post(
        "/register",
        [&](const httplib::Request &req,
            httplib::Response &res)
        {
            res.set_header(
                "Access-Control-Allow-Origin",
                "*");

            std::string username =
                req.get_param_value(
                    "username");

            std::string email =
                req.get_param_value(
                    "email");

            std::string password =
                req.get_param_value(
                    "password");

            bool success =
                database.registerUser(
                    username,
                    email,
                    password);

            if (success)
            {
                res.set_content(
                    "Registration successful",
                    "text/plain");
            }
            else
            {
                res.set_content(
                    "Registration failed",
                    "text/plain");
            }
        });

    server.Options(
        "/solve",
        [](const httplib::Request &req,
           httplib::Response &res)
        {
            res.set_header(
                "Access-Control-Allow-Origin",
                "*");

            res.set_header(
                "Access-Control-Allow-Methods",
                "POST, OPTIONS");

            res.set_header(
                "Access-Control-Allow-Headers",
                "Content-Type");

            res.status = 200;
        });

    server.Post(
        "/solve",
        [&](const httplib::Request &req,
            httplib::Response &res)
        {
            res.set_header(
                "Access-Control-Allow-Origin",
                "*");

            std::string eq1 =
                req.get_param_value(
                    "equation1");

            std::string eq2 =
                req.get_param_value(
                    "equation2");

            std::string eq3 =
                req.get_param_value(
                    "equation3");

            std::string method =
                req.get_param_value(
                    "method");

            DifferentialSystem system(
                eq1,
                eq2,
                eq3);

            Solver *solver = nullptr;

            if (method == "Euler")
            {
                solver =
                    new EulerSolver();
            }
            else if (method == "Heun")
            {
                solver =
                    new HeunSolver();
            }
            else
            {
                solver =
                    new RK4Solver();
            }

            Simulation simulation(
                system,
                solver,
                method);

            simulation.run();

            const auto &states =
                simulation.getStates();

            std::stringstream result;

            for (size_t i = 0;
                 i < states.size();
                 i++)
            {
                result
                    << "Step "
                    << i
                    << " X:"
                    << states[i].x
                    << " Y:"
                    << states[i].y
                    << " Z:"
                    << states[i].z
                    << "\n";
            }

            delete solver;

            res.set_content(
                result.str(),
                "text/plain");
        });
    std::cout
        << "Server started on http://localhost:8080"
        << std::endl;

    server.listen(
        "0.0.0.0",
        8080);
}