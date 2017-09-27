//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/logarithm.h"
#include "expr/constant/integer.h"
#include "expr/constant/e.h"


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

poly::expression poly::logarithm::derivative(const variable& var) const
{
    if(base.is_constant())
        return antilogarithm.derivative(var) / (antilogarithm * poly::ln(base));
    throw poly::cannot_derivate_except("base is not constant");
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

poly::expression poly::ln(const poly::expression& exponent)
{
    return poly::expression(new poly::logarithm(poly::E, exponent));
}

poly::expression poly::log(const poly::expression& base, const poly::expression& exponent)
{
    return poly::expression(new poly::logarithm(base, exponent));
}
