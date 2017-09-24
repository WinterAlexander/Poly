//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/logarithm.h"
#include "expr/constant.h"


poly::logarithm::logarithm(const poly::expression& base, const poly::expression& antilogarithm)
        : base(base), antilogarithm(antilogarithm)
{}

double poly::logarithm::value() const
{
    return std::log10(antilogarithm.value()) / std::log10(base.value());
}

bool poly::logarithm::is_constant() const
{
    return base.is_constant() && antilogarithm.is_constant();
}

poly::expr_content* poly::logarithm::clone() const
{
    return new poly::logarithm(base, antilogarithm);
}

std::string poly::logarithm::to_string() const
{
    if(base.instance_of<poly::e>())
    {
        return "ln(" + antilogarithm.to_string() + ")";
    }

    return "log_" + base.to_string() + "(" + antilogarithm.to_string() + ")";
}

std::string poly::logarithm::to_mathjax() const
{
    if(base.instance_of<poly::e>())
    {
        return "\\ln " + antilogarithm.to_mathjax() + " ";
    }

    return "\\log_{" + base.to_mathjax() + "} " + antilogarithm.to_mathjax() + " ";
}

const poly::expression& poly::logarithm::get_base() const
{
    return base;
}

const poly::expression& poly::logarithm::get_antilogarithm() const
{
    return antilogarithm;
}
