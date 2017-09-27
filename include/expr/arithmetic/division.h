//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_DIVISION_H
#define POLY_DIVISION_H

#include "expr/expression.h"
#include "expr/variable.h"
#include "expr/expr_content.h"

namespace poly {
    class division;

    expression gcd(const expression& arg1, const expression& arg2);
}

class poly::division final : public poly::expr_content
{
    poly::expression dividend;
    poly::expression divisor;

public:
    division(const poly::expression& dividend, const poly::expression& divisor);

    double resolve() const override;

    bool is_constant() const override {
        return dividend.is_constant() && divisor.is_constant();
    }

    poly::expression derivative(const variable &var) const override;

    expression simplified(const poly::expression& parent) const override;

    expr_content* clone() const override {
        return new poly::division(dividend, divisor);
    }

    std::string to_string() const override;
    std::string to_mathjax() const override;

    const expression& get_dividend() const {
        return dividend;
    }

    const expression& get_divisor() const {
        return divisor;
    }
};

#endif //POLY_DIVISION_H
