//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/arithmetic/addition.h"

poly::addition::addition(const poly::expression& augend, const poly::expression& addend)
        : augend(augend), addend(addend)
{

}

std::string poly::addition::to_string() const
{
    return "(" + augend.to_string() + " + " + addend.to_string() + ")";
}

double poly::addition::resolve() const
{
    return augend.resolve() + addend.resolve();
}

std::string poly::addition::to_mathjax() const
{
    return "(" + augend.to_mathjax() + "+" + addend.to_mathjax() + ")";
}

poly::expression poly::addition::derivative(const variable &var) const
{
    return augend.derivative(var) + addend.derivative(var);
}
