
#include "gtest/gtest.h"
#include "polynomial.h"

TEST(polynomial, test_add)
{
    poly::term termA(1, 1);
}

TEST(polynomial, test_divide)
{
    poly::polynomial polyA = { 5, 2, 1, 3, 1 };
    poly::polynomial polyB = { 1, 3, 6, 10 };

    poly::polynomial::quotient result = polyA / polyB;

    ASSERT_EQ(poly::polynomial({5, -13}), result.first);
    ASSERT_EQ(poly::polynomial({10, 31, 131}), result.second);
}