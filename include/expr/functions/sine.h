//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_SINE_H
#define POLY_SINE_H

#include "trigonometric_function.h"

namespace poly {
    class sine;
    expression sin(const expression& argument);
}

class poly::sine final : public poly::trigonometric_function
{
public:
    sine(const expression& argument);

    expression derivative(const poly::variable& var) const override;

    expr_content* clone() const override;
};


#endif //POLY_SINE_H
