//
// Created by Alexander Winter on 2017-09-27.
//

#ifndef POLY_ARCTANGENT_H
#define POLY_ARCTANGENT_H

#include "trigonometric_function.h"

namespace poly {
    class arctangent;

    expression atan(const expression& argument);
}

class poly::arctangent final : public poly::trigonometric_function
{
public:
    arctangent(const expression& argument);

    expression derivative(const variable& var) const override;
    expr_content* clone() const override;
};


#endif //POLY_ARCTANGENT_H
