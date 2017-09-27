//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/tangent.h"

poly::tangent::tangent(const poly::expression& argument)
        : trigonometric_function(argument, "tan", std::tan)
{

}

poly::expr_content* poly::tangent::clone() const
{
    return new poly::tangent(argument);
}

poly::expression poly::tangent::derivative(const poly::variable& var) const
{
    return argument.derivative(var) / (poly::cos(argument) ^ 2);
}
