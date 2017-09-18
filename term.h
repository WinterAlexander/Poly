//
// Created by Alexander Winter on 2017-09-17.
//

#ifndef POLY_TERM_H
#define POLY_TERM_H


#include <cstddef>
#include "polynomial.h"

namespace poly {
    class term;

    polynomial operator+(const term& first, const term& second);
    polynomial operator-(const term& first, const term& second);
    term operator*(const term& first, const term& second);
    term operator/(const term& first, const term& second);
}

class poly::term final
{
public:
    const float value;
    const std::size_t degree;

    term() = delete;
    term(const term& copy) = default;
    term(float value, std::size_t degree);

    term operator-() const;

    friend polynomial operator+(const term& first, const term& second);
    friend polynomial operator-(const term& first, const term& second);
    friend term operator*(const term& first, const term& second);
    friend term operator/(const term& first, const term& second);
};


#endif //POLY_TERM_H
