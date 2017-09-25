//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_CONSTANT_H
#define POLY_CONSTANT_H

#include <cmath>
#include "constant.h"

namespace poly {
    class integer;
}

class poly::integer final : public poly::constant
{
    int _value;
public:
    integer(int value);

    double value() const override {
        return _value;
    }

    poly::expr_content* clone() const override {
        return new poly::integer(_value);
    }

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_CONSTANT_H
