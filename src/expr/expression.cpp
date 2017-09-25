//
// Created by Alexander Winter on 2017-09-19.
//

#include "expr/expression.h"
#include "expr/arithmetic/subtraction.h"
#include "expr/constant/integer.h"
#include "expr/exponentiation.h"
#include "expr/arithmetic/addition.h"
#include "expr/arithmetic/multiplication.h"
#include "expr/arithmetic/division.h"

poly::expression::expression(poly::expr_content* content)
    : content(content)
{

}

poly::expression::expression(int value)
{
    *this = value;
}

poly::expression::expression(double value)
{
    *this = value;
}

poly::expression::expression(const expression& other)
{
    *this = other;
}

poly::expression::~expression()
{
    delete content;
}

poly::expression& poly::expression::operator=(const poly::expression& other)
{
    delete content;
    content = other.content->clone();
    return *this;
}

poly::expression& poly::expression::operator=(int value)
{
    delete content;
    content = new poly::integer(value);
    return *this;
}

poly::expression& poly::expression::operator=(double value)
{
    delete content;
    content = new poly::integer((int)value); //TODO detect fraction
    return *this;
}

double poly::expression::value() const
{
    return content->value();
}

bool poly::expression::is_constant() const
{
    return content->is_constant();
}

poly::expression poly::expression::derivative(const variable &var) const
{
    return content->derivative(var);
}

poly::expression poly::expression::operator+(const poly::expression& addend) const
{
    return poly::expression(new poly::addition(*this, addend));
}

poly::expression poly::expression::operator-(const poly::expression& subtrahend) const
{
    return poly::expression(new poly::subtraction(*this, subtrahend));
}

poly::expression poly::expression::operator*(const poly::expression& multiplier) const
{
    return poly::expression(new poly::multiplication(*this, multiplier));
}

poly::expression poly::expression::operator/(const poly::expression& divisor) const
{
    return poly::expression(new poly::division(*this, divisor));
}

poly::expression poly::expression::operator^(const poly::expression& exponent) const
{
    return poly::expression(new poly::exponentiation(*this, exponent));
}

poly::expression poly::expression::operator-()
{
    return poly::expression(new poly::multiplication(*this, -1));
}

poly::expression& poly::expression::operator+=(const poly::expression& addend)
{
    return *this = *this + addend;
}

poly::expression& poly::expression::operator-=(const poly::expression& subtrahend)
{
    return *this = *this - subtrahend;
}

poly::expression& poly::expression::operator*=(const poly::expression& multiplier)
{
    return *this = *this * multiplier;
}

poly::expression& poly::expression::operator/=(const poly::expression& divisor)
{
    return *this = *this / divisor;
}

poly::expression& poly::expression::operator^=(const poly::expression& exponent)
{
    return *this = *this ^ exponent;
}

bool poly::expression::operator==(const poly::expression& other) const
{
    return false;//*content == *other.content;
}

bool poly::expression::operator!=(const poly::expression& other) const
{
    return !(other == *this);
}


std::string poly::expression::to_string() const
{
    return content->to_string();
}

std::string poly::expression::to_mathjax() const
{
    return content->to_mathjax();
}

std::ostream& poly::operator<<(std::ostream& os, const poly::expression& expr)
{
    os << expr.to_string();
    return os;
}
