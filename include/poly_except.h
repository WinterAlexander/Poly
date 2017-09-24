//
// Created by Alexander Winter on 2017-09-18.
//

#ifndef POLY_POLY_EXCEPT_H
#define POLY_POLY_EXCEPT_H

#include <stdexcept>

namespace poly {
    class invalid_term_order;
    class division_by_higher_degree;
}

class poly::invalid_term_order : public std::logic_error
{
public:
    invalid_term_order()
            : std::logic_error("Terms aren't properly ordered")
    {

    }
};

class poly::division_by_higher_degree : public std::logic_error
{
public:
    division_by_higher_degree(const std::string& __arg)
            : std::logic_error(__arg)
    {

    }
};

#endif //POLY_POLY_EXCEPT_H
