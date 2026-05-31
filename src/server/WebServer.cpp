#include "WebServer.h"
#include "../../external/httplib.h"

#include <iostream>

void WebServer::start()
{
    httplib::Server server;

    server.Get(
        "/",
        [](const httplib::Request &req,
           httplib::Response &res)
        {
            res.set_content(
                "Differential Equation Solver API",
                "text/plain");
        });

    std::cout
        << "Server started on http://localhost:8080"
        << std::endl;

    server.listen(
        "0.0.0.0",
        8080);
}