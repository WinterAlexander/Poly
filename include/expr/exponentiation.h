//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_POWER_H
#define POLY_POWER_H

#include "expression.h"
#include "expr_content.h"
#include "variable.h"

namespace poly {
    class exponentiation;
}

class poly::exponentiation final : public poly::expr_content
{
    poly::expression base;
    poly::expression exponent;

public:
    exponentiation(const poly::expression& base, const poly::expression& exponent);

    double value() const override;
    bool is_constant() const override;

    poly::expression derivative(poly::variable var) const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_POWER_H
