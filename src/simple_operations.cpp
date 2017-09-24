//
// Created by Alexander Winter on 2017-09-23.
//

#include "simple_operations.h"

poly::addition::addition(const poly::expression& augend, const poly::expression& addend)
        : augend(augend), addend(addend)
{

}

std::string poly::addition::to_string() const
{
    return "(" + augend.to_string() + " + " + addend.to_string() + ")";
}

double poly::addition::value() const
{
    return augend.value() + addend.value();
}


poly::subtraction::subtraction(const poly::expression& minuend, const poly::expression& subtrahend)
        : minuend(minuend), subtrahend(subtrahend)
{

}

std::string poly::subtraction::to_string() const
{
    return "(" + minuend.to_string() + " - " + subtrahend.to_string() + ")";
}

double poly::subtraction::value() const
{
    return minuend.value() - subtrahend.value();
}

poly::multiplication::multiplication(const poly::expression& multiplicand, const poly::expression& multiplier)
        : multiplicand(multiplicand), multiplier(multiplier)
{

}

std::string poly::multiplication::to_string() const
{
    return "(" + multiplicand.to_string() + " * " + multiplier.to_string() + ")";
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

poly::division::division(const poly::expression& dividend, const poly::expression& divisor)
    : dividend(dividend), divisor(divisor)
{

}

std::string poly::division::to_string() const
{
    return "(" + dividend.to_string() + " / " + divisor.to_string() + ")";
}

double poly::division::value() const
{
    return dividend.value() / divisor.value();
}
