//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/constant/pi.h"

double value() const
{
    return M_PI;
}

bool is_constant() const
{
    return true;
}

poly::expr_content* clone() const
{
    return new poly::pi();
}

std::string to_string() const
{
    return "PI";
}

std::string to_mathjax() const
{
    return "\\pi ";
}

poly::expression poly::get_pi()
{
    return poly::expression(new poly::pi());
}
