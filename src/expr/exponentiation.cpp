//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/exponentiation.h"
#include "expr/arithmetic/division.h"
#include "expr/constant/integer.h"
#include "expr/functions/logarithm.h"

poly::exponentiation::exponentiation(const poly::expression& base, const poly::expression& exponent)
    : base(base), exponent(exponent)
{

}

double poly::exponentiation::resolve() const
{
    bool baseSet = false, expSet = false;
    double baseVal, expVal;
    if(exponent.is_constant())
    {
        expVal = exponent.resolve();
        expSet = true;
        if(expVal == 0)
            return 1;
    }

    if(base.is_constant())
    {
        baseVal = base.resolve();
        baseSet = true;
        if(baseVal == 1)
            return 1;
        else if(baseVal == 0)
            return 0;
    }

    if(!baseSet)
        baseVal = base.resolve();

    if(!expSet)
        expVal = exponent.resolve();

    return std::pow(baseVal, expVal);
}

bool poly::exponentiation::is_constant() const
{
    if(exponent.is_constant())
    {
        if(exponent.resolve() == 0)
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
    std::string baseStr;

    if(base.instance_of<poly::division>())
        baseStr = "(" + base.to_mathjax() + ")";
    else
        baseStr = base.to_mathjax();

    if(exponent.instance_of<poly::division>())
    {
        const poly::division& di = exponent.as<poly::division>();

        if(di.get_divisor().instance_of<poly::integer>())
            return "\\sqrt[" + di.get_divisor().to_mathjax() + "]{{" + baseStr + "}^{" + di.get_dividend().to_mathjax() + "}}";
    }

    return "{" + baseStr + "}^{" + exponent.to_mathjax() + "}";
}

poly::expression poly::exponentiation::derivative(const variable &var) const
{
    if(base.is_constant())
        return (base ^ exponent) * poly::ln(base) * exponent.derivative(var);

    if(exponent.is_constant())
    {
        if(exponent == 1)
            return base.derivative(var);
        else if(exponent == 0)
            return 0;

        return exponent * (base ^ (exponent - 1)) * base.derivative(var);
    }

    throw poly::cannot_derivate_except("Both base and exponent are variables");
}

poly::expression poly::sqrt(const poly::expression& radicant)
{
    return radicant ^ (1 / 2);
}