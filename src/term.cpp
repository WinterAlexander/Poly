//
// Created by Alexander Winter on 2017-09-17.
//

#include "term.h"
#include "polynomial.h"

poly::term::term(value_t value, degree_t degree)
    : _value(value), _degree(degree)
{

}

std::string poly::term::to_string() const
{
    std::stringstream ss;

    if(_degree == 0)
        ss << _value;
    else if(_degree == 1)
    {
        if(_value == 1)
            ss << "x";
        else if(_value == -1)
            ss << "-x";
        else
            ss << _value << "x";
    }
    else
    {
        if(_value == 1)
            ss << "x^" << _degree;
        else if(_value == -1)
            ss << "-x^" << _degree;
        else
            ss << _value << "x^" << _degree;
    }

    return ss.str();
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
    return poly::polynomial(first) -= poly::polynomial(second);
}

poly::term poly::operator*(const poly::term& first, const poly::term& second)
{
    return poly::term(first._value * second._value, first._degree + second._degree);
}

poly::term poly::operator/(const poly::term& first, const poly::term& second)
{
    return poly::term(first._value / second._value, first._degree - second._degree);
}
