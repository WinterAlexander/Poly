//
// Created by Alexander Winter on 2017-09-19.
//

#ifndef POLY_NUMBER_H
#define POLY_NUMBER_H

#include <string>

namespace poly {
    class expression;

    std::ostream& operator<<(std::ostream& os, const expression& number);
}

class poly::expression
{
public:
    virtual poly::expression* clone() const = 0;
    virtual std::string to_string() const = 0;

    expression operator+(const expression& addend) const;
    expression operator-(const expression& subtrahend) const;
    expression operator*(const expression& multiplier) const;
    expression operator/(const expression& divisor) const;
};


#endif //POLY_NUMBER_H
