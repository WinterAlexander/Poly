//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/arithmetic/multiplication.h"


poly::multiplication::multiplication(const poly::expression& multiplicand, const poly::expression& multiplier)
        : multiplicand(multiplicand), multiplier(multiplier)
{

}

double poly::multiplication::resolve() const
{
    if(multiplicand.is_constant())
    {
        double val1 = multiplicand.resolve();

        if(val1 == 0)
            return 0;

        return val1 * multiplier.resolve();
    }

    if(multiplier.is_constant())
    {
        double val2 = multiplier.resolve();

        if(val2 == 0)
            return 0;

        return multiplicand.resolve() * val2;
    }

    return multiplicand.resolve() * multiplier.resolve();
}

bool poly::multiplication::is_constant() const {
    if(multiplicand.is_constant())
    {
        if(multiplicand.resolve() == 0)
            return true;
        return multiplier.is_constant();
    }

    return multiplier.is_constant() && multiplier.resolve() == 0;
}

std::string poly::multiplication::to_string() const
{
    return "(" + multiplicand.to_string() + " * " + multiplier.to_string() + ")";
}

std::string poly::multiplication::to_mathjax() const
{
    return "(" + multiplicand.to_mathjax() + "\\cdot " + multiplier.to_mathjax() + ")";
}

poly::expression poly::multiplication::derivative(const variable &var) const
{
    return multiplicand.derivative(var) * multiplier + multiplicand * multiplier.derivative(var);
}
