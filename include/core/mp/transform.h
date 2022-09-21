// Copyright (C) 2017, 2019, 2022 by Mark Melton
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

/// Apply the template template parameter **F** to each element of type
/// list **L**.
///
/// The template template parameter **F** should be a template with a
/// single type parameter that evaluates to the transformed type.
///
/// \tparam F Template template parameter that computes transformation.
/// \tparam L The type list to transform.
template<template<typename...> typename F, typename L>
using transform_t = typename transform<F, L>::type;

}; // mp

#endif
