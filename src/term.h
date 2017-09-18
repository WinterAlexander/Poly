//
// Created by Alexander Winter on 2017-09-17.
//

#ifndef POLY_TERM_H
#define POLY_TERM_H


#include <cstddef>
#include "poly_type.h"
#include <string>

namespace poly {
    class term;
    class polynomial;
    std::ostream& operator<<(std::ostream& os, const term& term);

    polynomial operator+(const term& first, const term& second);
    polynomial operator-(const term& first, const term& second);
    term operator*(const term& first, const term& second);
    term operator/(const term& first, const term& second);
}

class poly::term final
{
    value_t _value = 0;
    degree_t _degree = 0;

public:
    term() = default;
    term(value_t value, degree_t degree);

    std::string to_string() const;

    inline value_t value() const {
        return _value;
    }

    inline degree_t degree() const {
        return _degree;
    }

    term operator-() const;

    bool operator==(const term& rhs) const;

    bool operator!=(const term& rhs) const;

    bool operator<(const term& rhs) const;
    bool operator>(const term& rhs) const;
    bool operator<=(const term& rhs) const;
    bool operator>=(const term& rhs) const;

    friend polynomial operator+(const term& first, const term& second);
    friend polynomial operator-(const term& first, const term& second);
    friend term operator*(const term& first, const term& second);
    friend term operator/(const term& first, const term& second);
};


#endif //POLY_TERM_H
