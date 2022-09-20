// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_MP_REMOVE_H
#define CORE_MP_REMOVE_H

#include "core/mp/if.h"
#include "core/mp/contains.h"
#include "core/mp/push_front.h"

namespace core::mp
{

// remove
//
template<typename V, typename L>
struct remove
{
    template<typename Vx, typename Lx>
    struct impl;

    template<typename Vx, template<typename...> typename Lx>
    struct impl<Vx,Lx<>>
    { using type = Lx<>; };

    template<typename Vx, template<typename...> typename Lx, typename T1, typename... Tx>
    struct impl<Vx,Lx<T1, Tx...>>
    {
	using _rest = typename remove<Vx,Lx<Tx...>>::type;
	using type = if_t<std::is_same<T1,Vx>, _rest, push_front_t<T1, _rest>>;
    };

    using type = typename impl<V,L>::type;
};

/// Remove all occurrences of type **V** from the type list **L**
///
/// \tparam V The type to remove.
/// \tparam L The type list.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// remove_t<int,list<int,char,int>> // list<char>
/// ```
/// \endverbatim
template<typename V, typename L>
using remove_t = typename remove<V,L>::type;

// remove_list
//
template<typename S, typename L>
struct remove_list
{
    template<typename Sx, typename Lx>
    struct impl;

    template<typename Sx, template<typename...> typename Lx>
    struct impl<Sx,Lx<>>
    { using type = Lx<>; };

    template<typename Sx, template<typename...> typename Lx, typename T1, typename... Tx>
    struct impl<Sx,Lx<T1, Tx...>>
    {
	using _rest = typename remove_list<Sx,Lx<Tx...>>::type;
	using type = if_t<contains_t<T1,Sx>, _rest, push_front_t<T1, _rest>>;
    };

    using type = typename impl<S,L>::type;
};

/// Remove all occurrences of the types in type list **S** from the
/// type list **L**
///
/// \tparam S The list of types to remove.
/// \tparam L The type list.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// remove_list_t<list<int,char>,list<int,char,int>> // list<>
/// ```
/// \endverbatim
template<typename S, typename L>
using remove_list_t = typename remove_list<S,L>::type;

}; // mp

#endif
