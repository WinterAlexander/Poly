//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/constant/e.h"

double poly::e::resolve() const
{
    return std::exp(1);
}

poly::expr_content* poly::e::clone() const
{
    return new poly::e();
}

std::string poly::e::to_string() const
{
    return "e";
}

std::string poly::e::to_mathjax() const
{
    return to_string();
}

poly::expression poly::get_e()
{
    return poly::expression(new poly::e());
}