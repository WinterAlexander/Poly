//
// Created by Alexander Winter on 2017-09-19.
//

#ifndef POLY_NUMBER_H
#define POLY_NUMBER_H

#include <string>
#include <typeinfo>
#include <stdexcept>

namespace poly {
    class expression;
    class expr_content;

    template<typename T>
    class invalid_expr_cast_except;

    class cannot_derivate_except;

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

    expression derivative() const;

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
};

class poly::expr_content
{

public:
    virtual ~expr_content() = default;

    virtual double value() const = 0;
    virtual bool is_constant() const = 0;

    virtual poly::expression derivative() const = 0;

    virtual poly::expr_content* clone() const = 0;

    virtual std::string to_string() const = 0;
    virtual std::string to_mathjax() const = 0;
};

template<typename T>
class poly::invalid_expr_cast_except final : public std::logic_error
{
public:
    invalid_expr_cast_except()
        : logic_error(std::string("Could not cast expression to type") + typeid(T).name())
    {

    }
};

class poly::cannot_derivate_except final : public std::logic_error
{
public:
    cannot_derivate_except(const std::string& message)
            : logic_error(message)
    {

    }
};


#endif //POLY_NUMBER_H
