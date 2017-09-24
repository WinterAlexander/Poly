//
// Created by Alexander Winter on 2017-09-24.
//


#include <gtest/gtest.h>
#include "expression.h"

TEST(expression, simple_operation_construction)
{
    poly::expression expr = 1;
    expr = expr + 4;

    std::cout << expr << std::endl;
    std::cout << expr.value() << std::endl;
}