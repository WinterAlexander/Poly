//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_INTEGER_H
#define POLY_INTEGER_H

#include <cmath>
#include "constant.h"

namespace poly {
    class integer;
}

class poly::integer final : public poly::constant
{
    int value;
public:
    integer(int value);

    double resolve() const override;

    poly::expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;

    int get_value() const;
};


#endif //POLY_INTEGER_H
