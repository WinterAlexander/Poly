//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/constant/integer.h"

poly::integer::integer(int value)
        : _value(value)
{

}

std::string poly::integer::to_string() const
{
    return std::to_string(_value);
}

std::string poly::integer::to_mathjax() const
{
    return to_string();
}
