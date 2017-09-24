//
// Created by Alexander Winter on 2017-09-24.
//

#include "multiplication.h"


poly::multiplication::multiplication(const poly::expression& multiplicand, const poly::expression& multiplier)
        : multiplicand(multiplicand), multiplier(multiplier)
{

}

double poly::multiplication::value() const
{
    if(multiplicand.is_constant())
    {
        double val1 = multiplicand.value();

        if(val1 == 0)
            return 0;

        return val1 * multiplier.value();
    }

    if(multiplier.is_constant())
    {
        double val2 = multiplier.value();

        if(val2 == 0)
            return 0;

        return multiplicand.value() * val2;
    }

    return multiplicand.value() * multiplier.value();
}

bool poly::multiplication::is_constant() const {
    if(multiplicand.is_constant())
    {
        if(multiplicand.value() == 0)
            return true;
        return multiplier.is_constant();
    }

    return multiplier.is_constant() && multiplier.value() == 0;
}

std::string poly::multiplication::to_string() const
{
    return "(" + multiplicand.to_string() + " * " + multiplier.to_string() + ")";
}

std::string poly::multiplication::to_mathjax() const
{
    return "(" + multiplicand.to_mathjax() + "\\cdot " + multiplier.to_mathjax() + ")";
}
