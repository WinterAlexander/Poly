//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/cosine.h"

cosine::cosine(const poly::expression& argument)
        : trigonometric_function(argument, "cos", std::cos)
{

}


poly::expr_content* cosine::clone() const
{
    return new poly::cosine(argument);
}