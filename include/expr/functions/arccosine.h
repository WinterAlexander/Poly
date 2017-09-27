//
// Created by Alexander Winter on 2017-09-27.
//

#ifndef POLY_ARCCOSINE_H
#define POLY_ARCCOSINE_H

#include "trigonometric_function.h"

namespace poly {
    class arccosine;

    expression acos(const expression& argument);
}

class poly::arccosine final : public poly::trigonometric_function
{
public:
    arccosine(const expression& argument);

    expression derivative(const variable& var) const override;
    expr_content* clone() const override;
};


#endif //POLY_ARCCOSINE_H
