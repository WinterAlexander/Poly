//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_COSINE_H
#define POLY_COSINE_H

#include "trigonometric_function.h"
#include "expr/variable.h"

namespace poly {
    class cosine;
}

class poly::cosine final : public poly::trigonometric_function
{
public:
    cosine(const poly::expression& argument);

    expression derivative(const poly::variable& var) const override;

    poly::expr_content* clone() const override;
};


#endif //POLY_COSINE_H
