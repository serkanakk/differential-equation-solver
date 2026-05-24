#include "DifferentialSystem.h"

DifferentialSystem::DifferentialSystem(
    const std::string &e1,
    const std::string &e2,
    const std::string &e3)
{
    expr1_string = e1;
    expr2_string = e2;
    expr3_string = e3;

    symbol_table.add_variable("x", x);
    symbol_table.add_variable("y", y);
    symbol_table.add_variable("z", z);

    symbol_table.add_constants();

    expr1.register_symbol_table(symbol_table);
    expr2.register_symbol_table(symbol_table);
    expr3.register_symbol_table(symbol_table);

    parser.compile(expr1_string, expr1);
    parser.compile(expr2_string, expr2);
    parser.compile(expr3_string, expr3);
}

double DifferentialSystem::f1(double xv, double yv, double zv)
{
    x = xv;
    y = yv;
    z = zv;

    return expr1.value();
}

double DifferentialSystem::f2(double xv, double yv, double zv)
{
    x = xv;
    y = yv;
    z = zv;

    return expr2.value();
}

double DifferentialSystem::f3(double xv, double yv, double zv)
{
    x = xv;
    y = yv;
    z = zv;

    return expr3.value();
}