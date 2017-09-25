//
// Created by Alexander Winter on 2017-09-18.
//

#ifndef POLY_POLY_EXCEPT_H
#define POLY_POLY_EXCEPT_H

#include <stdexcept>
#include <typeinfo>

namespace poly {
    class invalid_term_order_except;
    class division_by_higher_degree_except;

    template<typename T>
    class invalid_expr_cast_except;

    class cannot_derivate_except;
    class incalculable_expr_except;
}

class poly::invalid_term_order_except : public std::logic_error
{
public:
    invalid_term_order_except()
            : std::logic_error("Terms aren't properly ordered")
    {

    }
};

class poly::division_by_higher_degree_except : public std::logic_error
{
public:
    division_by_higher_degree_except(const std::string& __arg)
            : std::logic_error(__arg)
    {

    }
};

template<typename T>
class poly::invalid_expr_cast_except final : public std::logic_error
{
public:
    invalid_expr_cast_except()
            : logic_error(std::string("Could not cast expression to type") + typeid(T).name())
    {

    }
};

class poly::cannot_derivate_except final : public std::logic_error
{
public:
    cannot_derivate_except(const std::string& message)
            : logic_error(message)
    {

    }
};

class poly::incalculable_expr_except final : public std::logic_error
{
public:
    incalculable_expr_except(const std::string& var_name)
            : logic_error("Could not calculate expression with variable: " + var_name)
    {

    }
};

#endif //POLY_POLY_EXCEPT_H
