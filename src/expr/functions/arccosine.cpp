//
// Created by Alexander Winter on 2017-09-27.
//

#include <cmath>
#include "expr/exponentiation.h"
#include "expr/functions/arccosine.h"

poly::arccosine::arccosine(const poly::expression& argument)
        : trigonometric_function(argument, "arccos", std::acos)
{}

poly::expression poly::arccosine::derivative(const poly::variable& var) const
{
    return -argument.derivative(var) / (poly::sqrt(1 - (argument ^ 2)));
}

poly::expr_content* poly::arccosine::clone() const
{
    return new poly::arccosine(argument);
}

poly::expression poly::acos(const poly::expression& argument)
{
    return poly::expression(new poly::arccosine(argument));
}
