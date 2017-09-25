//
// Created by Alexander Winter on 2017-09-18.
//

#ifndef POLY_POLY_TYPE_H
#define POLY_POLY_TYPE_H

#include <utility>
#include <stdexcept>

namespace poly {
    typedef float value_t;
    typedef int degree_t;
}

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

#endif //POLY_POLY_TYPE_H
