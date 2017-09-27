//
// Created by Alexander Winter on 2017-09-24.
//

#include <numeric>
#include "expr/arithmetic/division.h"
#include "expr/constant/integer.h"

poly::division::division(const poly::expression& dividend, const poly::expression& divisor)
        : dividend(dividend), divisor(divisor)
{

}

double poly::division::resolve() const
{
    return dividend.resolve() / divisor.resolve();
}

std::string poly::division::to_string() const
{
    return "(" + dividend.to_string() + " / " + divisor.to_string() + ")";
}

std::string poly::division::to_mathjax() const
{
    return "\\frac{" + dividend.to_mathjax() + "}{" + divisor.to_mathjax() + "}";
}

poly::expression poly::division::derivative(const variable &var) const
{
    return (dividend.derivative(var) * divisor - dividend * divisor.derivative(var)) / (divisor ^ 2);
}

poly::expression poly::division::simplified(const poly::expression& parent) const
{
    if(dividend.instance_of<poly::integer>() && divisor.instance_of<poly::integer>())
    {
        int dividendVal = dividend.as<poly::integer>().get_value();
        int divisorVal = divisor.as<poly::integer>().get_value();
        int gcd = std::gcd(dividendVal, divisorVal);

        if(divisorVal == gcd)
            return poly::expression(dividendVal / gcd);
        return poly::expression(dividendVal / gcd) / poly::expression(divisorVal / gcd);
    }

    return expr_content::simplified(parent);
}

poly::expression poly::gcd(const poly::expression& arg1, const poly::expression& arg2)
{
    return poly::expression(0);
}
