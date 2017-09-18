#include "../src/polynomial.h"

using namespace poly;

int main(int argc, char** argv)
{
    polynomial polyA = { 5, 2, 1, 3, 1 };
    polynomial polyB = { 1, 3, 6, 10 };

    std::cout << polyA << " / " << polyB << std::endl;

    quotient result = polyA / polyB;

    std::cout << "Result: " << result.first << std::endl;
    std::cout << "Remainder: " << result.second << std::endl;
}