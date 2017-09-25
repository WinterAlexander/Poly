//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_ADDITION_H
#define POLY_ADDITION_H

#include "expr/expression.h"
#include "expr/variable.h"
#include "expr/expr_content.h"

namespace poly {
    class addition;
}

class poly::addition final : public poly::expr_content
{
    poly::expression augend;
    poly::expression addend;

public:
    addition(const poly::expression& augend, const poly::expression& addend);

    double value() const override;

    bool is_constant() const override {
        return augend.is_constant() && addend.is_constant();
    }

    poly::expression derivative(const variable &var) const override;

    expr_content* clone() const override {
        return new poly::addition(augend, addend);
    }

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_ADDITION_H
