//
// Created by Alexander Winter on 2017-09-17.
//

#include "polynomial.h"

poly::polynomial::polynomial(poly::term singleTerm)
{
    terms.resize(singleTerm.degree + 1);
    terms[singleTerm.degree] = singleTerm;
}

poly::polynomial::polynomial(std::initializer_list<float> terms)
{
    for(float val : terms)
    {

    }
}

poly::polynomial::polynomial(const std::vector<poly::term>& terms)
    : terms(terms)
{
    remove_null_terms();
}

void poly::polynomial::remove_null_terms()
{
    while(terms.size() > 1 && terms.back().value == 0)
        terms.pop_back();
}

poly::polynomial poly::polynomial::operator-() const
{
    polynomial other(*this);

    for(poly::term& term : other.terms)
        term = -term;

    return other;
}

size_t poly::polynomial::degree() const
{
    return terms.size(); //assumes vector is cleaned up
}

poly::polynomial poly::operator+(const poly::polynomial& first, const poly::polynomial& second)
{
    polynomial result(first);

    size_t size = second.degree();

    if(size > result.degree())
        result.terms.resize(size);

    for(size_t i = 0; i < size; i++)
        result.terms[i] += second.terms[i];
    result.remove_null_terms();

    return result;
}

poly::polynomial poly::operator-(const poly::polynomial& first, const poly::polynomial& second)
{
    return first + -second;
}

poly::polynomial poly::operator*(const poly::polynomial& first, const poly::polynomial& second)
{
    return poly::polynomial();
}

poly::polynomial poly::operator/(const poly::polynomial& first, const poly::polynomial& second)
{
    return poly::polynomial();
}

poly::polynomial poly::operator%(const poly::polynomial& first, const poly::polynomial& second)
{
    return poly::polynomial();
}

std::string poly::polynomial::to_string() const
{
    std::stringstream ss;
    bool first = true;
    for(size_t i = terms.size(); i-- > 0;)
    {
        if(terms[i].value() == 0)
            continue;

        if(first)
        {
            first = false;
            if(terms[i].value() < 0)
                ss << "-";
        }
        else
            ss << (terms[i].value() < 0 ? " - " : " + ");

        float absVal = std::abs(terms[i].value());

        if(i == 0)
            ss << absVal;
        else if(i == 1)
        {
            if(absVal == 1)
                ss << "x";
            else
                ss << absVal << "x";
        }
        else
        {
            if(absVal == 1)
                ss << "x^" << i;
            else
                ss << absVal << "x^" << i;
        }

    }
    return ss.str();
}

std::ostream& poly::operator<<(std::ostream& os, const poly::polynomial& poly)
{
    os << poly.to_string();
    return os;
}
