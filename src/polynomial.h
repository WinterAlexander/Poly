//
// Created by Alexander Winter on 2017-09-17.
//

#ifndef POLYDIVIDER_POLYNOMIAL_H
#define POLYDIVIDER_POLYNOMIAL_H

#include <vector>
#include <type_traits>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "template_util.h"
#include "term.h"

namespace poly {
    class polynomial;

    std::ostream& operator<<(std::ostream& os, const polynomial& poly);
}

class poly::polynomial final
{
    std::vector<poly::term> terms;

public:
    polynomial();
    polynomial(poly::term term);
    polynomial(std::initializer_list<float> terms);
    polynomial(std::initializer_list<poly::term> terms);

    std::string to_string() const;

    degree_t degree() const;
    const poly::term& highest() const;
    bool is_single() const;

    poly::term operator[](degree_t index) const;

    polynomial& operator+=(const polynomial& addend) {
        return *this = *this + addend;
    }

    polynomial& operator-=(const polynomial& subtrahend) {
        return *this = *this - subtrahend;
    }

    polynomial& operator+=(const term& addend) {
        return *this += polynomial(addend);
    }

    polynomial& operator-=(const term& subtrahend) {
        return *this -= polynomial(subtrahend);
    }

    bool operator==(const polynomial& rhs) const;
    bool operator!=(const polynomial& rhs) const;

    polynomial operator-() const;

    polynomial operator+(const polynomial& addend) const;
    polynomial operator-(const polynomial& subtrahend) const;
    polynomial operator*(const polynomial& multiplier) const;

    typedef std::pair<polynomial, polynomial> quotient;
    quotient operator/(const polynomial& divisor) const;

private:
    void ensure_valid();
    void remove_null_terms();
};


#endif //POLYDIVIDER_POLYNOMIAL_H
