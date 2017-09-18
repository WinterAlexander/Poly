#include <iostream>

#include "polynomial.h"

int main()
{
    poly::polynomial poly0(5.0);
    poly::polynomial poly1(1, 3.6f);

    std::cout << (poly0 + poly1) << " Degree: " << poly0.degree() << std::endl;
    return 0;
}