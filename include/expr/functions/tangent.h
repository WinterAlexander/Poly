//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_TANGENT_H
#define POLY_TANGENT_H

#include "trigonometric_function.h"

namespace poly {
    class tangent;
}

class poly::tangent final : public poly::trigonometric_function
{
public:
    tangent(const expression& argument);

    expression derivative(poly::variable var) const override;

    expr_content* clone() const override;
};


#endif //POLY_TANGENT_H
