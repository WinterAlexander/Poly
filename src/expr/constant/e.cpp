//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/constant/e.h"

double value() const
{
    return std::exp(1);
}

poly::expr_content* clone() const
{
    return new poly::e();
}

std::string to_string() const
{
    return "e";
}

std::string to_mathjax() const
{
    return to_string();
}

poly::expression poly::get_e()
{
    return poly::expression(new poly::e());
}
