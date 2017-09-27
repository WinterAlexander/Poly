//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/constant/pi.h"

double poly::pi::resolve() const
{
    return M_PI;
}

poly::expr_content* poly::pi::clone() const
{
    return new poly::pi();
}

std::string poly::pi::to_string() const
{
    return "PI";
}

std::string poly::pi::to_mathjax() const
{
    return "\\pi ";
}

poly::expression poly::get_pi()
{
    return poly::expression(new poly::pi());
}
