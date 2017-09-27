//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/variable.h"
#include "expr/expression.h"

poly::variable::variable(const std::string& name)
        : name(name)
{

}

poly::variable::variable(char name)
        : name(std::string(1, name))
{

}

double poly::variable::resolve() const
{
    throw poly::incalculable_expr_except(name);
}

bool poly::variable::is_constant() const
{
    return false;
}

poly::expression poly::variable::derivative(const variable &var) const
{
    if(var.name == this->name)
        return 1;
    throw poly::cannot_derivate_except("Trying to find the derivative of a variable with another");
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

poly::expression poly::var(char name)
{
    return poly::expression(new poly::variable(name));
}

poly::expression poly::var(const std::string& name)
{
    return poly::expression(new poly::variable(name));
}
