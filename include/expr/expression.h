//
// Created by Alexander Winter on 2017-09-19.
//

#ifndef POLY_NUMBER_H
#define POLY_NUMBER_H

#include <string>
#include <typeinfo>
#include <stdexcept>
#include "poly_except.h"

namespace poly {
    class expression;

    class variable;
    class expr_content;

    std::ostream& operator<<(std::ostream& os, const expression& expr);
}

class poly::expression final
{
    expr_content* content = nullptr;

    explicit expression(expr_content* content);

public:
    expression(int value);
    expression(double value);
    expression(const expression& other);

    ~expression();

    double value() const;
    bool is_constant() const;

    expression derivative(poly::variable var) const;

    template<typename T>
    bool instance_of() const {
        return dynamic_cast<T*>(content) != nullptr;
    }

    template<typename T>
    const T& as() const {
        T* ptr = dynamic_cast<T*>(content);

        if(!ptr)
            throw poly::invalid_expr_cast_except<T>();
        return *(ptr);
    }

    expression& operator=(const expression& other);
    expression& operator=(int value);
    expression& operator=(double value);

    expression operator+(const expression& addend) const;
    expression operator-(const expression& subtrahend) const;
    expression operator*(const expression& multiplier) const;
    expression operator/(const expression& divisor) const;

    expression operator^(const expression& exponent) const;

    expression operator-();

    expression& operator+=(const expression& addend);
    expression& operator-=(const expression& subtrahend);
    expression& operator*=(const expression& multiplier);
    expression& operator/=(const expression& divisor);

    expression& operator^=(const expression& exponent);

    bool operator==(const expression& other) const;
    bool operator!=(const expression& other) const;

    std::string to_string() const;
    std::string to_mathjax() const;

    friend expression sin(const expression& argument);
    friend expression cos(const expression& argument);
    friend expression tan(const expression& argument);

    friend expression abs(const expression& value);

    friend expression ln(const expression& exponent);
    friend expression log(const expression& base, const expression& exponent);

    friend expression get_e();
    friend expression get_pi();

    friend expression var(char name);
    friend expression var(const std::string& name);
};



#endif //POLY_NUMBER_H
