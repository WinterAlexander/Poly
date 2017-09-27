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


poly::expression::expression(int value)
{
    *this = value;
}

poly::expression::expression(float value)
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
    expr_type = other.expr_type;
    return *this;
}

poly::expression& poly::expression::operator=(int value)
{
    delete content;
    content = new poly::integer(value);
    expr_type = &typeid(poly::integer);
    return *this;
}

poly::expression& poly::expression::operator=(float value)
{
    throw std::logic_error("Not implemented");
    /*
    float numerator = value;
    float denominator = 1;

    while(numerator != (int)numerator)
    {
        numerator *= 2;
        denominator *= 2;
    }

    return *this = ((poly::expression((int)numerator) / (int)denominator)).simplified();*/
}

double poly::expression::resolve() const
{
    return content->resolve();
}

bool poly::expression::is_constant() const
{
    return content->is_constant();
}

poly::expression poly::expression::derivative(const variable &var) const
{
    return content->derivative(var);
}

poly::expression poly::expression::simplified() const
{
    return content->simplified(*this);
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

poly::expression poly::operator+(int augend, const poly::expression& addend)
{
    return poly::expression(augend) + addend;
}

poly::expression poly::operator-(int minuend, const poly::expression& subtrahend)
{
    return poly::expression(minuend) - subtrahend;
}

poly::expression poly::operator*(int multiplicand, const poly::expression& multiplier)
{
    return poly::expression(multiplicand) * multiplier;
}

poly::expression poly::operator/(int dividend, const poly::expression& divisor)
{
    return poly::expression(dividend) / divisor;
}

poly::expression poly::operator^(int base, const poly::expression& exponent)
{
    return poly::expression(base) ^ exponent;
}
