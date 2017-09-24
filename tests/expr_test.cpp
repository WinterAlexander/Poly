//
// Created by Alexander Winter on 2017-09-24.
//


#include <gtest/gtest.h>
#include "expr/expression.h"

TEST(expression, simple_operation_construction)
{
    poly::expression expr = 1;
    expr = expr + 4;

    expr = (expr ^ 2) + 5;

    expr = expr / 4;

    expr = expr^(poly::expression(1) / 2);

    std::cout << std::endl;
    std::cout << expr << std::endl;
    std::cout << expr.to_mathjax() << std::endl;
    std::cout << expr.value() << std::endl;
}