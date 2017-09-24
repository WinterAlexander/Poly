//
// Created by Alexander Winter on 2017-09-23.
//

#include "addition.h"

poly::addition::addition(const poly::expression& augend, const poly::expression& addend)
        : augend(augend.clone()), addend(addend.clone())
{

}

poly::addition::~addition()
{
    delete augend;
    delete addend;
}

std::string poly::addition::to_string() const
{
    return "(" + augend->to_string() + " + " + addend->to_string() + ")";
}
