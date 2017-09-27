//
// Created by Alexander Winter on 2017-09-27.
//

#include <cmath>
#include "expr/exponentiation.h"
#include "expr/functions/arcsine.h"

poly::arcsine::arcsine(const poly::expression& argument)
        : trigonometric_function(argument, "arcsin", std::asin)
{}

poly::expression poly::arcsine::derivative(const poly::variable& var) const
{
    return argument.derivative(var) / (poly::sqrt(1 - (argument ^ 2)));
}

poly::expr_content* poly::arcsine::clone() const
{
    return new poly::arcsine(argument);
}

poly::expression poly::asin(const poly::expression& argument)
{
    return poly::expression(new poly::arcsine(argument));
}