// Copyright (C) 2018, 2019 by Mark Melton
//

#ifndef CORE_MP_SUBSET_H
#define CORE_MP_SUBSET_H

#include "core/mp/contains.h"

namespace core::mp
{

// subset
//

// template<typename Subset, typename Set>
// struct is_subset_of : std::false_type
// { };

// template<typename... Ts, typename... Us>
// struct is_subset_of<mp::list<Ts...>, mp::list<Us...>>
//     : std::conjunction<mp::contains_t<Ts,mp::list<Us...>>...>
// { };

template<typename V, typename L>
struct is_subset_of
{
    template<typename Sx>
    struct impl;

    template<typename... Ts>
    struct impl<mp::list<Ts...>>
    { using type = typename std::conjunction<mp::contains_t<Ts,L>...>::type; };
    
    using type = typename impl<V>::type;
};

template<typename V, typename L>
using is_subset_of_t = typename is_subset_of<V,L>::type;

}; // mp

#endif
