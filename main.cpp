//#include "gtest/googletest/include/gtest/gtest.h"

#include "polynomial.h"

using namespace poly;

int main(int argc, char** argv)
{
    polynomial polyA = {5, 2, 1, 3, 1};
    polynomial polyB = {1, 3, 6, 10};

    std::cout << polyA << " / " << polyB << std::endl;

    quotient result = polyA / polyB;

    std::cout << "Result: " << result.first << std::endl;
    std::cout << "Remainder: " << result.second << std::endl;

    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}

/*
TEST(polynomial, test_add)
{
    ASSERT_EQ(1, 1);
}
 */