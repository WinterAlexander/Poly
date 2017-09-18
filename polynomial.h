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
    std::vector<float> terms;

public:
    template<class... U> //not bound to float so auto cast can occur
    polynomial(U... terms)
            : terms { terms... }
    {
        std::reverse(this->terms.begin(), this->terms.end());
        remove_null_terms();
    }

    std::string to_string() const;

    size_t degree() const;

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
