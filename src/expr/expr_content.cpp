//
// Created by Alexander Winter on 2017-09-27.
//

#include "expr/expr_content.h"
#include "expr/expression.h"

poly::expression poly::expr_content::simplified(const poly::expression& parent) const
{
    return parent;
}
