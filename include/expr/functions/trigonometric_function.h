//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_TRIGONOMETRIC_FUNCTION_H
#define POLY_TRIGONOMETRIC_FUNCTION_H

#include "../expression.h"

namespace poly {
    class trigonometric_function;

    expression sin(const expression& argument);
    expression cos(const expression& argument);
    expression tan(const expression& argument);
}

class poly::trigonometric_function : public expr_content
{
protected:
    expression argument;
    std::string func_name;
    double(&function)(double);

public:
    trigonometric_function(const expression& argument, const std::string& func_name, double(&function)(double));

    double value() const override;
    bool is_constant() const override;

    std::string to_string() const override;
    std::string to_mathjax() const override;

    const expression& get_argument() const;
};


#endif //POLY_TRIGONOMETRIC_FUNCTION_H
