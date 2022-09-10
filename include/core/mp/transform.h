// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_TRANSFORM_H
#define CORE_MP_TRANSFORM_H

#include "core/mp/list.h"

namespace core::mp
{

// transform
//
template<template<typename...> typename F, typename L>
struct transform
{
    template<template<typename...> typename Fx, typename Lx>
    struct impl;

    template<template<typename...> typename Fx, template<typename...> typename Lx, typename... Tx>
    struct impl<Fx, Lx<Tx...>>
    { using type = Lx<Fx<Tx>...>; };

    using type = typename impl<F,L>::type;
};

template<template<typename...> typename F, typename L>
using transform_t = typename transform<F, L>::type;

}; // mp

#endif
