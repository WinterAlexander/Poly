//
// Created by Alexander Winter on 2017-09-17.
//

#include "term.h"

poly::term::term(float value, std::size_t degree)
    : value(value), degree(degree)
{

}

poly::term poly::term::operator-() const
{
    return poly::term(-value, degree);
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
    return poly::term(first.value * second.value, first.degree + second.degree);
}

poly::term poly::operator/(const poly::term& first, const poly::term& second)
{
    return poly::term(first.value / second.value, first.degree - second.degree);
}
