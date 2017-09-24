//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/functions/trigonometric_function.h"

poly::trigonometric_function::trigonometric_function(const poly::expression& argument, const std::string& func_name, double(&function)(double))
        : argument(argument), func_name(func_name), function(function)
{

}

double poly::trigonometric_function::value() const
{
    return function(argument.value());
}

bool poly::trigonometric_function::is_constant() const
{
    return argument.is_constant();
}

std::string poly::trigonometric_function::to_string() const
{
    return func_name + "(" + argument.to_string() + ")";
}

std::string poly::trigonometric_function::to_mathjax() const
{
    return "\\" + func_name + " " + argument.to_mathjax() + " ";
}

const poly::expression& poly::trigonometric_function::get_argument() const
{
    return argument;
}
