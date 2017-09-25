//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_VARIABLE_H
#define POLY_VARIABLE_H

#include <stdexcept>
#include "expression.h"

namespace poly {
    class variable;
    class incalculable_expr_except;
}

class poly::variable final : public poly::expr_content
{
    std::string name;

public:
    variable(char name);
    variable(const std::string& name);

    double value() const override;
    bool is_constant() const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;
};

class poly::incalculable_expr_except final : public std::logic_error
{
public:
    incalculable_expr_except(const std::string& var_name)
            : logic_error("Could not calculate expression with variable: " + var_name)
    {

    }
};


#endif //POLY_VARIABLE_H
