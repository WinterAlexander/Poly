//
// Created by Alexander Winter on 2017-09-24.
//

#include "variable.h"

poly::variable::variable(std::string name)
    : name(name)
{

}

double poly::variable::value() const
{
    throw poly::incalculable_expr_except(name);
}

bool poly::variable::is_constant() const
{
    return false;
}

poly::expr_content* poly::variable::clone() const
{
    return new poly::variable(name);
}

std::string poly::variable::to_string() const
{
    return name;
}

std::string poly::variable::to_mathjax() const
{
    return to_string();
}
