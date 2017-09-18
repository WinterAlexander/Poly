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

    polynomial operator+(const polynomial& augend, const polynomial& addend);
    polynomial operator-(const polynomial& minuend, const polynomial& subtrahend);
    polynomial operator*(const polynomial& multiplicand, const polynomial& multiplier);

    typedef std::pair<polynomial, polynomial> quotient;
    quotient operator/(const polynomial& dividend, const polynomial& divisor);
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

    poly::term operator[](degree_t index) const;

    const poly::term& highest() const;

    polynomial operator-() const;

    inline polynomial& operator+=(const polynomial& addend) {
        return *this = *this + addend;
    }

    inline polynomial& operator-=(const polynomial& subtrahend) {
        return *this = *this - subtrahend;
    }

    inline polynomial& operator+=(const term& addend) {
        return *this += polynomial(addend);
    }

    inline polynomial& operator-=(const term& subtrahend) {
        return *this -= polynomial(subtrahend);
    }

    bool operator==(const polynomial& rhs) const;
    bool operator!=(const polynomial& rhs) const;
    
    friend polynomial operator+(const polynomial& augend, const polynomial& addend);
    friend polynomial operator-(const polynomial& minuend, const polynomial& subtrahend);
    friend polynomial operator*(const polynomial& multiplicand, const polynomial& multiplier);
    friend quotient operator/(const polynomial& dividend, const polynomial& divisor);

private:
    void ensure_valid();
    void remove_null_terms();
};


#endif //POLYDIVIDER_POLYNOMIAL_H
