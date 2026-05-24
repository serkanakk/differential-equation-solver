#pragma once

#include <string>

#include "../external/exprtk.hpp"

class DifferentialSystem
{

private:
    std::string expr1_string;
    std::string expr2_string;
    std::string expr3_string;

    double x;
    double y;
    double z;

    exprtk::symbol_table<double> symbol_table;

    exprtk::expression<double> expr1;
    exprtk::expression<double> expr2;
    exprtk::expression<double> expr3;

    exprtk::parser<double> parser;

public:
    DifferentialSystem(
        const std::string &e1,
        const std::string &e2,
        const std::string &e3);

    double f1(double x, double y, double z);

    double f2(double x, double y, double z);

    double f3(double x, double y, double z);
};