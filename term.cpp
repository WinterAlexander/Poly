//
// Created by Alexander Winter on 2017-09-17.
//

#include "term.h"
#include "polynomial.h"

poly::term::term(float value, std::size_t degree)
    : _value(value), _degree(degree)
{

}

poly::term poly::term::operator-() const
{
    return poly::term(-_value, _degree);
}

poly::polynomial poly::operator+(const poly::term& first, const poly::term& second)
{
    return poly::polynomial(first) += poly::polynomial(second);
}

poly::polynomial poly::operator-(const poly::term& first, const poly::term& second)
{
    return poly::polynomial();
}

poly::term poly::operator*(const poly::term& first, const poly::term& second)
{
    return poly::term(first._value * second._value, first._degree + second._degree);
}

poly::term poly::operator/(const poly::term& first, const poly::term& second)
{
    if(first._degree < second._degree)
        throw std::arith

    return poly::term(first._value / second._value, first._degree - second._degree);
}
