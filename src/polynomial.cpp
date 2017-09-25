//
// Created by Alexander Winter on 2017-09-17.
//

#include "polynomial.h"
#include "poly_except.h"
#include <cmath>

poly::polynomial::polynomial()
{
    terms.emplace_back(poly::term());
}

poly::polynomial::polynomial(poly::term term)
{
    if(term.value() == 0)
    {
        terms.emplace_back(poly::term());
        return;
    }

    terms.resize(static_cast<size_t>(term.degree() + 1));
    terms[term.degree()] = term;
}

poly::polynomial::polynomial(std::initializer_list<float> terms)
{
    this->terms.resize(terms.size());

    for(degree_t i = 0; i < static_cast<degree_t>(terms.size()); i++)
        this->terms[i] = poly::term(*(terms.end() - i - 1), i);

    remove_null_terms();
}

poly::polynomial::polynomial(std::initializer_list<poly::term> terms)
    : terms(terms)
{
    std::reverse(this->terms.begin(), this->terms.end());
    remove_null_terms();
    ensure_valid();
}

void poly::polynomial::ensure_valid()
{
    for(degree_t i = 0; i < static_cast<degree_t>(terms.size()); i++)
        if(i != terms[i].degree())
            throw poly::invalid_term_order_except();
}

void poly::polynomial::remove_null_terms()
{
    while(terms.size() > 1 && terms.back().value() == 0)
        terms.pop_back();
}


int poly::polynomial::degree() const
{
    return static_cast<degree_t>(terms.size()) - 1; //assumes vector is cleaned up
}

const poly::term& poly::polynomial::highest() const
{
    return terms[degree()];
}

bool poly::polynomial::is_single() const
{
    int count = 0;

    for(term term : terms)
        if(term.value() != 0)
            if(++count > 1)
                return false;

    return true;
}

poly::term poly::polynomial::operator[](poly::degree_t index) const
{
    if(index < 0 || index > degree())
        return poly::term(0, index);

    return terms[index];
}

poly::polynomial poly::polynomial::operator-() const
{
    polynomial other(*this);

    for(poly::term& term : other.terms)
        term = -term;

    return other;
}

poly::polynomial poly::polynomial::operator+(const poly::polynomial& second) const
{
    polynomial result;

    degree_t size = std::max(this->degree(), second.degree());
    result.terms.resize(static_cast<std::size_t>(size) + 1);

    for(degree_t i = 0; i <= size; i++)
        result.terms[i] = poly::term((*this)[i].value() + second[i].value(), i);

    result.remove_null_terms();

    return result;
}

poly::polynomial poly::polynomial::operator-(const poly::polynomial& second) const
{
    return *this + -second;
}

poly::polynomial poly::polynomial::operator*(const poly::polynomial& second) const
{
    poly::polynomial result;

    for(poly::term a : this->terms)
        for(poly::term b : second.terms)
            result += a * b;

    return result;
}

poly::polynomial::quotient poly::polynomial::operator/(const polynomial& divisor) const
{
    polynomial remainder = *this;
    polynomial result;

    const term divisorTerm = divisor.highest();

    while(remainder.degree() >= divisorTerm.degree())
    {
        term newterm = remainder.highest() / divisorTerm;
        result += newterm;

        for(term term : divisor.terms)
            remainder -= term * newterm;
    }

    return { result, remainder };
}

bool poly::polynomial::operator==(const poly::polynomial& rhs) const
{
    return terms == rhs.terms;
}

bool poly::polynomial::operator!=(const poly::polynomial& rhs) const
{
    return !(rhs == *this);
}

std::string poly::polynomial::to_string() const
{
    std::stringstream ss;
    bool first = true;
    for(degree_t i = static_cast<degree_t>(terms.size()); i-- > 0;)
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

        value_t absVal = std::abs(terms[i].value());

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
