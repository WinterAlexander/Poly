//
// Created by Alexander Winter on 2017-09-19.
//

#ifndef POLY_NUMBER_H
#define POLY_NUMBER_H

#include <string>
#include <typeinfo>

namespace poly {
    class expression;
    class expr_content;

    template<typename T>
    class invalid_expr_cast_except;

    std::ostream& operator<<(std::ostream& os, const expression& expr);
}

class poly::expression final
{
    expr_content* content = nullptr;

    explicit expression(expr_content* content);

public:
    expression(int value);
    expression(const expression& other);

    ~expression();

    double value() const;
    bool is_constant() const;

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

    expression operator+(const expression& addend) const;
    expression operator-(const expression& subtrahend) const;
    expression operator*(const expression& multiplier) const;
    expression operator/(const expression& divisor) const;

    expression operator^(const expression& exponent) const;

    std::string to_string() const;
    std::string to_mathjax() const;
};

class poly::expr_content
{

public:
    virtual ~expr_content() = default;

    virtual double value() const = 0;
    virtual bool is_constant() const = 0;

    virtual poly::expr_content* clone() const = 0;

    virtual std::string to_string() const = 0;
    virtual std::string to_mathjax() const = 0;
};

template<typename T>
class poly::invalid_expr_cast_except final //: public std::logic_error
{/*
public:
    invalid_expr_cast_except()
        : logic_error(std::string("Could not cast expression to type") + typeid(T).name())
    {

    }*/
};

#endif //POLY_NUMBER_H
