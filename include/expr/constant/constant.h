//
// Created by Alexander Winter on 2017-09-24.
//

#ifndef POLY_CONSTANT_H
#define POLY_CONSTANT_H

#include "expr/variable.h"
#include "expr/expr_content.h"
#include "expr/expression.h"


namespace poly {
    class constant;
}

class poly::constant : public expr_content
{
public:
    bool is_constant() const override;
    poly::expression derivative(const variable &var) const override;
};


#endif //POLY_CONSTANT_H
