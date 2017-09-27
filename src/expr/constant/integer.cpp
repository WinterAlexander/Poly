//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/constant/integer.h"

poly::integer::integer(int value)
        : value(value)
{

}

double poly::integer::resolve() const
{
    return value;
}

poly::expr_content* poly::integer::clone() const
{
    return new poly::integer(value);
}

std::string poly::integer::to_string() const
{
    return std::to_string(value);
}

std::string poly::integer::to_mathjax() const
{
    return to_string();
}

int poly::integer::get_value() const
{
    return value;
}
