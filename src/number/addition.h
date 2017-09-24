//
// Created by Alexander Winter on 2017-09-23.
//

#ifndef POLY_SUM_H
#define POLY_SUM_H

#include <bits/unique_ptr.h>
#include "expression.h"

namespace poly {
    class addition;
}

class poly::addition : public poly::expression
{
    poly::expression* augend;
    poly::expression* addend;

public:
    addition(const poly::expression& augend, const poly::expression& addend);

    virtual ~addition();

    std::string to_string() const override;
};


#endif //POLY_SUM_H
