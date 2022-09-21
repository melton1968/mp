// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/if.h"
#include "core/mp/contains.h"
#include "core/mp/push_front.h"

namespace core::mp
{

// unique
//
template<class L>
struct unique
{
    template<class Lx>
    struct impl;
    
    template<template<class...> class Lx>
    struct impl<Lx<>>
    { using type = Lx<>; };
    
    template<template<class...> class Lx, class T1, class... Tx>
    struct impl<Lx<T1, Tx...>>
    {
	using _rest = typename unique<Lx<Tx...>>::type;
	using type = if_t<contains_t<T1,_rest>, _rest, push_front_t<T1, _rest>>;
    };

    using type = typename impl<L>::type;
};

/// Uniquify type list **L**, i.e. remove any duplicate types.
///
/// \tparam L The type list to uniquify.
template<class L>
using unique_t = typename unique<L>::type;

}; // core::mp

