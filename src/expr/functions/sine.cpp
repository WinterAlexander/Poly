//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/sine.h"

poly::sine::sine(const poly::expression& argument)
        : trigonometric_function(argument, "sin", std::sin)
{

}

poly::expr_content* poly::sine::clone() const
{
    return new poly::sine(argument);
}

poly::expression poly::sine::derivative(const poly::variable& var) const
{
    return poly::cos(argument) * argument.derivative(var);
}
