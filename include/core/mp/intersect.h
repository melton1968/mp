// Copyright (C) 2017, 2018, 2019, 2020, 2022 by Mark Melton
//

#pragma once
#include "core/mp/append.h"
#include "core/mp/contains.h"
#include "core/mp/if.h"

namespace core::mp
{

// intersect
//
template<class... Ls>
struct intersect
{ using type = mp::list<>; };

template<class L>
struct intersect<mp::list<>, L>
{ using type = mp::list<>; };

template<class L1, class L2>
requires (mp::size_v<L1> > 0)
struct intersect<L1,L2>
{
    using pred = mp::contains_t<mp::head_t<L1>, L2>;
    using rtail = typename intersect<mp::tail_t<L1>,L2>::type;
    using concat = mp::append_t<mp::list<mp::head_t<L1>>, rtail>;
    using type = mp::if_t<pred,concat,rtail>;
};

template<class L1, class L2, class L3, class... Ls>
struct intersect<L1, L2, L3, Ls...>
{
    using partial = typename intersect<L1,L2>::type;
    using type = typename intersect<partial,L3,Ls...>::type;
};

/// Intersect the given type lists **Ls**.
///
/// \tparam Ls The type lists to intersect.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// intersect_t<list<int,char>,list<int>> // list<int>
/// ```
/// \endverbatim
template<class... Ls>
using intersect_t = typename intersect<Ls...>::type;

}; // mp
