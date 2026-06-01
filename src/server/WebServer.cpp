#include "WebServer.h"
#include "../../external/httplib.h"
#include "../database/DatabaseManager.h"
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

    std::cout
        << "Server started on http://localhost:8080"
        << std::endl;

    server.listen(
        "0.0.0.0",
        8080);
}