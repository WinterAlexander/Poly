//
// Created by Alexander Winter on 2017-09-23.
//

#ifndef POLY_SUM_H
#define POLY_SUM_H

#include <bits/unique_ptr.h>
#include "../expression.h"

namespace poly {
    class subtraction;
}

class poly::subtraction final : public poly::expr_content
{
    poly::expression minuend;
    poly::expression subtrahend;

public:
    subtraction(const poly::expression& minuend, const poly::expression& subtrahend);

    double value() const override;

    bool is_constant() const override {
        return minuend.is_constant() && subtrahend.is_constant();
    }

    expr_content* clone() const override {
        return new poly::subtraction(minuend, subtrahend);
    }

    std::string to_string() const override;
    std::string to_mathjax() const override;
};





#endif //POLY_SUM_H
