//
// Created by Alexander Winter on 2017-09-18.
//

#include <gtest/gtest.h>
#include "polynomial.h"

TEST(term, test_add_same_degree)
{
    ASSERT_EQ(poly::term(17.6f, 4), (poly::term(15.6f, 4) + poly::term(2, 4)).highest());
    ASSERT_EQ(poly::term(10, 0), (poly::term(5, 0) + poly::term(5, 0)).highest());
    ASSERT_EQ(poly::term(11, 100), (poly::term(5.45, 100) + poly::term(5.55, 100)).highest());
}

TEST(term, test_multiply)
{
    ASSERT_EQ(poly::term(31.2f, 4), poly::term(15.6f, 4) * poly::term(2, 0));
    ASSERT_EQ(poly::term(10, 4), poly::term(5, 2) * poly::term(2, 2));
    ASSERT_EQ(poly::term(5, 4), poly::term(2.5, 1) * poly::term(2, 3));
    ASSERT_EQ(poly::term(49, 14), poly::term(7, 7) * poly::term(7, 7));
}

TEST(term, test_divide)
{
    ASSERT_EQ(poly::term(2, 0), poly::term(31.2f, 4) / poly::term(15.6f, 4));
    ASSERT_EQ(poly::term(2, 2), poly::term(10, 4) / poly::term(5, 2));
    ASSERT_EQ(poly::term(2, 3), poly::term(5, 4) / poly::term(2.5, 1));
    ASSERT_EQ(poly::term(7, 7), poly::term(49, 14) / poly::term(7, 7));
}