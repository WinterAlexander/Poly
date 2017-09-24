//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_COSINE_H
#define POLY_COSINE_H

#include "trigonometric_function.h"

namespace poly {
    class cosine;
}

class cosine final : poly::trigonometric_function
{
public:
    cosine(const poly::expression& argument);

    poly::expr_content* clone() const override;
};


#endif //POLY_COSINE_H
