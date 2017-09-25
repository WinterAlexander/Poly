//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/cosine.h"

poly::cosine::cosine(const poly::expression& argument)
        : trigonometric_function(argument, "cos", std::cos)
{

}

poly::expr_content* poly::cosine::clone() const
{
    return new poly::cosine(argument);
}

poly::expression poly::cosine::derivative(poly::variable var) const
{
    return -poly::sin(argument) * argument.derivative(var);
}
