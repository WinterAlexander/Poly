//
// Created by Alexander Winter on 2017-09-19.
//

#include "expression.h"
#include "addition.h"

poly::expression poly::expression::operator+(const poly::expression& addend) const
{
    return poly::addition(*this, addend);
}

poly::expression poly::expression::operator-(const poly::expression& addend) const
{
    return poly::expression();
}

poly::expression poly::expression::operator*(const poly::expression& addend) const
{
    return poly::expression();
}

poly::expression poly::expression::operator/(const poly::expression& addend) const
{
    return poly::expression();
}

std::ostream& poly::operator<<(std::ostream& os, const poly::expression& number)
{
    os << number.to_string();
    return os;
}