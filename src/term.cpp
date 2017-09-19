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

bool poly::term::operator<(const poly::term& rhs) const
{
    if (_degree < rhs._degree)
        return true;
    if(_degree > rhs._degree)
        return false;
    return _value < rhs._value;
}

bool poly::term::operator>(const poly::term& rhs) const
{
    return rhs < *this;
}

bool poly::term::operator<=(const poly::term& rhs) const
{
    return !(rhs < *this);
}

bool poly::term::operator>=(const poly::term& rhs) const
{
    return !(*this < rhs);
}

bool poly::term::operator==(const poly::term& rhs) const
{
    return _value == rhs._value && _degree == rhs._degree;
}

bool poly::term::operator!=(const poly::term& rhs) const
{
    return !(rhs == *this);
}

poly::polynomial poly::term::operator+(const poly::term& second) const
{
    return poly::polynomial(*this) += poly::polynomial(second);
}

poly::polynomial poly::term::operator-(const poly::term& second) const
{
    return poly::polynomial(*this) -= poly::polynomial(second);
}

poly::term poly::term::operator*(const poly::term& second) const
{
    return poly::term(this->_value * second._value, this->_degree + second._degree);
}

poly::term poly::term::operator/(const poly::term& second) const
{
    return poly::term(this->_value / second._value, this->_degree - second._degree);
}

std::ostream& ::poly::operator<<(std::ostream& os, const poly::term& term)
{
    os << term.to_string();
    return os;
}
