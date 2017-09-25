//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/arithmetic/division.h"

poly::division::division(const poly::expression& dividend, const poly::expression& divisor)
        : dividend(dividend), divisor(divisor)
{

}

double poly::division::value() const
{
    return dividend.value() / divisor.value();
}

std::string poly::division::to_string() const
{
    return "(" + dividend.to_string() + " / " + divisor.to_string() + ")";
}

std::string poly::division::to_mathjax() const
{
    return "\\frac{" + dividend.to_mathjax() + "}{" + divisor.to_mathjax() + "}";
}

poly::expression poly::division::derivative() const
{
    return (dividend.derivative() * divisor - dividend * divisor.derivative()) / (divisor ^ 2);
}
