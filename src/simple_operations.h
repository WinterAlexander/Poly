//
// Created by Alexander Winter on 2017-09-23.
//

#ifndef POLY_SUM_H
#define POLY_SUM_H

#include <bits/unique_ptr.h>
#include "expression.h"

namespace poly {
    class addition;
    class subtraction;
    class multiplication;
    class division;
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

    inline expr_content* clone() const override {
        return new poly::addition(augend, addend);
    }

    std::string to_string() const override;
};


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

    inline expr_content* clone() const override {
        return new poly::subtraction(minuend, subtrahend);
    }

    std::string to_string() const override;
};


class poly::multiplication final : public poly::expr_content
{
    poly::expression multiplicand;
    poly::expression multiplier;

public:
    multiplication(const poly::expression& multiplicand, const poly::expression& multiplier);

    double value() const override;

    bool is_constant() const;

    inline expr_content* clone() const override {
        return new poly::multiplication(multiplicand, multiplier);
    }

    std::string to_string() const override;
};


class poly::division final : public poly::expr_content
{
    poly::expression dividend;
    poly::expression divisor;

public:
    division(const poly::expression& dividend, const poly::expression& divisor);

    double value() const override;

    bool is_constant() const override {
        return dividend.is_constant() && divisor.is_constant();
    }

    inline expr_content* clone() const override {
        return new poly::division(dividend, divisor);
    }

    std::string to_string() const override;

    inline const expression& get_dividend() const {
        return dividend;
    }

    inline const expression& get_divisor() const {
        return divisor;
    }
};


#endif //POLY_SUM_H
