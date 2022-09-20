// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_MP_APPEND_H
#define CORE_MP_APPEND_H

#include "core/mp/list.h"

namespace core::mp
{

// append
//
template<typename... L>
struct append
{
    template<bool B,typename... Lx>
    struct impl;

    template<bool B>
    struct impl<B>
    { using type = mp::list<>; };

    template<bool B,template<typename...> typename Lx, typename... Tx>
    struct impl<B,Lx<Tx...>>
    { using type = Lx<Tx...>; };

    template<bool B,template<typename...> typename L1, typename... T1,
	     template<typename...> typename L2, typename... T2, typename... Lr>
    struct impl<B,L1<T1...>, L2<T2...>, Lr...>
    { using type = typename append<L1<T1..., T2...>, Lr...>::type; };

    using type = typename impl<true,L...>::type;
};

/// Concatenate the lists or list elements **L**.
///
/// \tparam L The lists or list elements.
template<class... L>
using append_t = typename append<L...>::type;

}; // mp

#endif
