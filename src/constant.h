//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_CONSTANT_H
#define POLY_CONSTANT_H

#include <cmath>
#include "expression.h"

namespace poly {
    class integer;
    class pi;
    class e;

    static const pi PI();
    static const e E();
}

class poly::integer final : public poly::expr_content
{
    int _value;
public:
    integer(int value);

    double value() const override {
        return _value;
    }

    bool is_constant() const override {
        return true;
    }

    inline poly::expr_content* clone() const override {
        return new poly::integer(_value);
    }

    std::string to_string() const override;

    std::string to_mathjax() const override;
};

class poly::pi final : public poly::expr_content
{
public:
    inline double value() const override {
        return M_PI;
    }

    inline bool is_constant() const override {
        return true;
    }

    inline expr_content* clone() const override {
        return new poly::pi();
    }

    inline std::string to_string() const override {
        return "PI";
    }

    inline std::string to_mathjax() const override {
        return "\\pi";
    }
};

class poly::e final : public poly::expr_content
{
public:
    inline double value() const override {
        return std::exp(1);
    }

    inline bool is_constant() const override {
        return true;
    }

    inline expr_content* clone() const override {
        return new poly::e();
    }

    inline std::string to_string() const override {
        return "e";
    }

    inline std::string to_mathjax() const override {
        return to_string();
    }
};


#endif //POLY_CONSTANT_H
