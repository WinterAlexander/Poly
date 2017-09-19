//
// Created by Alexander Winter on 2017-09-19.
//

#ifndef POLY_NUMBER_H
#define POLY_NUMBER_H

namespace poly {
    class number;
}

class poly::number
{

public:
    number operator+(number addend);
    number operator-(number addend);
    number operator*(number addend);
    number operator/(number addend);
};


#endif //POLY_NUMBER_H
