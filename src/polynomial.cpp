//
// Created by Alexander Winter on 2017-09-17.
//

#include "polynomial.h"
#include "poly_except.h"

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
            throw poly::invalid_term_order();
}

void poly::polynomial::remove_null_terms()
{
    while(terms.size() > 1 && terms.back().value() == 0)
        terms.pop_back();
}

poly::polynomial poly::polynomial::operator-() const
{
    polynomial other(*this);

    for(poly::term& term : other.terms)
        term = -term;

    return other;
}

int poly::polynomial::degree() const
{
    return static_cast<degree_t>(terms.size()) - 1; //assumes vector is cleaned up
}

poly::term poly::polynomial::operator[](poly::degree_t index) const
{
    if(index < 0 || index > degree())
        return poly::term(0, index);

    return terms[index];
}

const poly::term& poly::polynomial::highest() const
{
    return terms[degree()];
}

poly::polynomial poly::operator+(const poly::polynomial& first, const poly::polynomial& second)
{
    polynomial result;

    degree_t size = std::max(first.degree(), second.degree());
    result.terms.resize(static_cast<std::size_t>(size) + 1);

    for(degree_t i = 0; i <= size; i++)
        result.terms[i] = poly::term(first[i].value() + second[i].value(), i);

    result.remove_null_terms();

    return result;
}

poly::polynomial poly::operator-(const poly::polynomial& first, const poly::polynomial& second)
{
    return first + -second;
}

poly::polynomial poly::operator*(const poly::polynomial& first, const poly::polynomial& second)
{
    poly::polynomial result;

    for(poly::term a : first.terms)
        for(poly::term b : second.terms)
            result += a * b;

    return result;
}

poly::quotient poly::operator/(const polynomial& dividend, const polynomial& divisor)
{
    polynomial remainder = dividend;
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
