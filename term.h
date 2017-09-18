//
// Created by Alexander Winter on 2017-09-17.
//

#ifndef POLY_TERM_H
#define POLY_TERM_H


#include <cstddef>

namespace poly {
    class term;
    class polynomial;

    polynomial operator+(const term& first, const term& second);
    polynomial operator-(const term& first, const term& second);
    term operator*(const term& first, const term& second);
    term operator/(const term& first, const term& second);
}

class poly::term final
{
    float _value = 0;
    std::size_t _degree = 0;

public:
    term(float value, std::size_t degree);

    inline float value() const {
        return _value;
    }

    inline std::size_t degree() const {
        return _degree;
    }

    term operator-() const;

    friend polynomial operator+(const term& first, const term& second);
    friend polynomial operator-(const term& first, const term& second);
    friend term operator*(const term& first, const term& second);
    friend term operator/(const term& first, const term& second);
};


#endif //POLY_TERM_H
