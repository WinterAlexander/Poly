//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_EXPR_CONTENT_H
#define POLY_EXPR_CONTENT_H

namespace poly {
    class expr_content;

    class expression;
    class variable;
}

class poly::expr_content
{

public:
    virtual ~expr_content() = default;

    virtual double value() const = 0;
    virtual bool is_constant() const = 0;

    virtual poly::expression derivative(const variable &var) const = 0;

    virtual poly::expr_content* clone() const = 0;

    virtual std::string to_string() const = 0;
    virtual std::string to_mathjax() const = 0;
};

#endif //POLY_EXPR_CONTENT_H
