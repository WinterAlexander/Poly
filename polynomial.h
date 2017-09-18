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

    polynomial operator+(const polynomial& first, const polynomial& second);
    polynomial operator-(const polynomial& first, const polynomial& second);
    polynomial operator*(const polynomial& first, const polynomial& second);
    polynomial operator/(const polynomial& first, const polynomial& second);
    polynomial operator%(const polynomial& first, const polynomial& second);
}

class poly::polynomial final
{
    std::vector<poly::term> terms;

public:
    polynomial(poly::term singleTerm);
    polynomial(std::initializer_list<float> terms);
    polynomial(std::initializer_list<poly::term> terms);

    polynomial(const std::vector<term>& terms);

    std::string to_string() const;

    std::size_t degree() const;

    polynomial operator-() const;

    inline polynomial& operator+=(const polynomial& other) {
        *this = *this + other;
        return *this;
    }

    friend polynomial operator+(const polynomial& first, const polynomial& second);
    friend polynomial operator-(const polynomial& first, const polynomial& second);
    friend polynomial operator*(const polynomial& first, const polynomial& second);
    friend polynomial operator/(const polynomial& first, const polynomial& second);
    friend polynomial operator%(const polynomial& first, const polynomial& second);

private:
    void remove_null_terms();
};


#endif //POLYDIVIDER_POLYNOMIAL_H
