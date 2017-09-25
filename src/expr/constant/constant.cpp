//
// Created by Alexander Winter on 2017-09-24.
//

#include "expr/constant/constant.h"

bool poly::constant::is_constant() const
{
    return true;
}

poly::expression poly::constant::derivative(const variable &var) const
{
    return 0;
}
