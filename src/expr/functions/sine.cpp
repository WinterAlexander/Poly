//
// Created by Alexander Winter on 2017-09-24.
//

#include <cmath>
#include "expr/functions/sine.h"

poly::sine::sine(const poly::expression& argument)
        : trigonometric_function(argument, "sin", std::sin)
{

}

poly::expr_content* poly::sine::clone() const
{
    return new poly::sine(argument);
}
