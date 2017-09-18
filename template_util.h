//
// Created by Alexander Winter on 2017-09-17.
//

#ifndef POLYDIVIDER_TEMPLATE_UTIL_H
#define POLYDIVIDER_TEMPLATE_UTIL_H

namespace detail
{
    template<bool...> struct bool_pack;
    template<bool... bs>
    using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;
}

template <typename... Ts>
using all_true = detail::all_true<Ts::value...>;

template <typename T, typename... Ts>
using all_same = all_true<std::is_same<T,Ts>...>;

#endif //POLYDIVIDER_TEMPLATE_UTIL_H
