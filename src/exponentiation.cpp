//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "exponentiation.h"

poly::exponentiation::exponentiation(const poly::expression& base, const poly::expression& exponent)
    : base(base), exponent(exponent)
{

}

double poly::exponentiation::value() const
{
    bool baseSet = false, expSet = false;
    double baseVal, expVal;
    if(exponent.is_constant())
    {
        expVal = exponent.value();
        expSet = true;
        if(expVal == 0)
            return 1;
    }

    if(base.is_constant())
    {
        baseVal = base.value();
        baseSet = true;
        if(baseVal == 1)
            return 1;
        else if(baseVal == 0)
            return 0;
    }

    if(!baseSet)
        baseVal = base.value();

    if(!expSet)
        expVal = exponent.value();

    return std::pow(baseVal, expVal);
}

bool poly::exponentiation::is_constant() const
{
    if(exponent.is_constant())
    {
        if(exponent.value() == 0)
            return true;
        return base.is_constant();
    }

    return base.is_constant() && exponent.is_constant();
}

poly::expr_content* poly::exponentiation::clone() const
{
    return new poly::exponentiation(base, exponent);
}

std::string poly::exponentiation::to_string() const
{
    return "(" + base.to_string() + ")^(" + exponent.to_string() + ")";
}

std::string poly::exponentiation::to_mathjax() const
{
    if(exponent.instance_of<poly::division>())
    {

    }

    return "{" + base.to_string() + "}^{" + exponent.to_string() + "}";
}
