//
// Created by Alexander Winter on 2017-09-23.
//

#include "expr/arithmetic/subtraction.h"



poly::subtraction::subtraction(const poly::expression& minuend, const poly::expression& subtrahend)
        : minuend(minuend), subtrahend(subtrahend)
{

}

double poly::subtraction::resolve() const
{
    return minuend.resolve() - subtrahend.resolve();
}

std::string poly::subtraction::to_string() const
{
    return "(" + minuend.to_string() + " - " + subtrahend.to_string() + ")";
}

std::string poly::subtraction::to_mathjax() const
{
    return "(" + minuend.to_mathjax() + "-" + subtrahend.to_mathjax() + ")";
}

poly::expression poly::subtraction::derivative(const variable &var) const
{
    return minuend.derivative(var) - subtrahend.derivative(var);
}
