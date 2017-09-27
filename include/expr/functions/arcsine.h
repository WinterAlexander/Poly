//
// Created by Alexander Winter on 2017-09-27.
//

#ifndef POLY_ARCSINE_H
#define POLY_ARCSINE_H

#include "expr/functions/trigonometric_function.h"

namespace poly {
    class arcsine;

    expression asin(const expression& argument);
}

class poly::arcsine final : public poly::trigonometric_function
{
public:
    arcsine(const expression& argument);

    expression derivative(const variable& var) const override;
    expr_content* clone() const override;
};


#endif //POLY_ARCSINE_H
