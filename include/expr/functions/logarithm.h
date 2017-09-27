//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_LOGARITHM_H
#define POLY_LOGARITHM_H

#include "expr/expression.h"
#include "expr/expr_content.h"

namespace poly {
    class logarithm;

    expression ln(const expression& exponent);
    expression log(const expression& base, const expression& exponent);
}

class poly::logarithm final : public poly::expr_content
{
    expression base;
    expression antilogarithm;

public:
    logarithm(const expression& base, const expression& antilogarithm);

    double value() const override;
    bool is_constant() const override;

    poly::expression derivative(const variable& var) const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;

    const expression& get_base() const;
    const expression& get_antilogarithm() const;
};


#endif //POLY_LOGARITHM_H
