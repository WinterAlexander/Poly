//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_MULTIPLICATION_H
#define POLY_MULTIPLICATION_H

#include "../expression.h"

namespace poly {
    class multiplication;
}

class poly::multiplication final : public poly::expr_content
{
    poly::expression multiplicand;
    poly::expression multiplier;

public:
    multiplication(const poly::expression& multiplicand, const poly::expression& multiplier);

    double value() const override;

    bool is_constant() const;

    expression derivative() const override;

    expr_content* clone() const override {
        return new poly::multiplication(multiplicand, multiplier);
    }

    std::string to_string() const override;
    std::string to_mathjax() const override;
};



#endif //POLY_MULTIPLICATION_H
