//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/functions/absolute_value.h"
#include <cmath>

poly::absolute_value::absolute_value(const poly::expression& argument)
        : argument(argument)
{

}

double poly::absolute_value::value() const
{
    return std::abs(argument.value());
}

bool poly::absolute_value::is_constant() const
{
    return argument.is_constant();
}

poly::expr_content* poly::absolute_value::clone() const
{
    return new poly::absolute_value(argument);
}

std::string poly::absolute_value::to_string() const
{
    return "|" + argument.to_string() + "|";
}

std::string poly::absolute_value::to_mathjax() const
{
    return "\\lvert\\," + argument.to_string() + "\\,\\lvert ";
}

poly::expression poly::absolute_value::derivative(const variable &var) const
{
    return ((argument ^ 2) ^ (1 / 2)).derivative(var);
}

poly::expression abs(const poly::expression& value)
{
    return poly::expression(new poly::absolute_value(value));
}