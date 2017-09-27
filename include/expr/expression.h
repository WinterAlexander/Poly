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

    expression operator+(int augend, const expression& addend);
    expression operator-(int minuend, const expression& subtrahend);
    expression operator*(int multiplicand, const expression& multiplier);
    expression operator/(int dividend, const expression& divisor);
    expression operator^(int base, const expression& exponent);
}

class poly::expression final
{
    expr_content* content = nullptr;
    const std::type_info* expr_type;

    template<typename T>
    explicit expression(T* content)
            : content(dynamic_cast<expr_content*>(content)), expr_type(&typeid(T))
    {
        if(!this->content)
            throw std::invalid_argument("type is not an expression");
    }

public:
    expression(int value);
    expression(float value);
    expression(const expression& other);

    ~expression();

    double resolve() const;
    bool is_constant() const;

    expression derivative(const variable& var) const;
    expression simplified() const;

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

    const std::type_info& type() const {
        return *expr_type;
    }

    expression& operator=(const expression& other);
    expression& operator=(int value);
    expression& operator=(float value);

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

    friend expression sqrt(const expression& radicant);

    friend expression ln(const expression& exponent);
    friend expression log(const expression& base, const expression& exponent);

    friend expression get_e();
    friend expression get_pi();

    friend expression var(char name);
    friend expression var(const std::string& name);

    friend expression asin(const expression& argument);
    friend expression acos(const expression& argument);
    friend expression atan(const expression& argument);
};



#endif //POLY_NUMBER_H
