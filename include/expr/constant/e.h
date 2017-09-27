//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_E_H
#define POLY_E_H

#include <cmath>
#include "constant.h"

namespace poly {
    class e;

    expression get_e();
    static const expression E = get_e();
}

class poly::e final : public poly::constant
{
public:
    double resolve() const override;

    expr_content* clone() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;
};


#endif //POLY_E_H
