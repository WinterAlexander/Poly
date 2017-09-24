//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_TANGENT_H
#define POLY_TANGENT_H

#include "trigonometric_function.h"

namespace poly {
    class tangent;
}

class poly::tangent final : poly::trigonometric_function
{
public:
    tangent(const expression& argument);

private:
    expr_content* clone() const override;
};


#endif //POLY_TANGENT_H
