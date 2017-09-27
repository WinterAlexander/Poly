//
// Created by Alexander Winter on 2017-09-27.
//

#include <cmath>
#include "expr/functions/arctangent.h"

poly::arctangent::arctangent(const poly::expression& argument)
        : trigonometric_function(argument, "arctan", std::atan)
{

}

poly::expression poly::arctangent::derivative(const poly::variable& var) const
{
    return argument.derivative(var) / ((argument ^ 2) + 1);
}

poly::expr_content* poly::arctangent::clone() const
{
    return new poly::arctangent(argument);
}

poly::expression poly::atan(const poly::expression& argument)
{
    return poly::expression(new poly::arctangent(argument));
}