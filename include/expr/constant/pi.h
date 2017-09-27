//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_PI_H
#define POLY_PI_H

#include "constant.h"

namespace poly {
    class pi;

    expression get_pi();
    static const expression PI = get_pi();
}

class poly::pi final : public poly::constant
{
    double resolve() const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_PI_H
