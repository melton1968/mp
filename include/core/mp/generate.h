// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_GENERATE_H
#define CORE_MP_GENERATE_H

#include "core/mp/list.h"

namespace core::mp
{

template<typename T, size_t N>
struct generate
{
    template<typename Tx, size_t Nx>
    struct impl_helper
    { using type = Tx; };
    
    template<typename Ix>
    struct impl;
    
    template<std::size_t... Is>
    struct impl<std::index_sequence<Is...>>
    { using type = mp::list<typename impl_helper<T,Is>::type...>; };
	
    using type = typename impl<std::make_index_sequence<N>>::type;
};

template<typename T, size_t N>
using generate_t = typename generate<T,N>::type;

}; // mp
    
#endif
