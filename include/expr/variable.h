//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_VARIABLE_H
#define POLY_VARIABLE_H

#include <stdexcept>
#include "expr_content.h"

namespace poly {
    class variable;
    class expression;

    expression var(char name);
    expression var(const std::string& name);
}

class poly::variable final : public poly::expr_content
{
    std::string name;

public:
    variable(char name);
    variable(const std::string& name);

    double value() const override;
    bool is_constant() const override;

    poly::expression derivative(poly::variable var) const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_VARIABLE_H
