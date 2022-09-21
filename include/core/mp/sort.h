// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/list.h"
#include "core/mp/at.h"
#include "core/mp/swap.h"

namespace core::mp
{

template<typename L, template <typename, typename> typename C>
struct sort
{
    template <typename Lx, size_t Ix, size_t Jx, size_t Nx>
    struct impl
    {
        // Compare and conditionally swap
        using Px = std::conditional_t
	    <C<at_ct<Ix,Lx>, at_ct<Jx,Lx>>::value, Lx, swap_t<Ix, Jx, Lx>>;
	
	// Recurse until J == N
        using type = typename impl<Px, Ix, Jx + 1, Nx>::type;
    };

    // Increment I and set J = I + 1
    template <typename Lx, size_t Ix, size_t Nx>
    struct impl<Lx, Ix, Nx, Nx>
    { using type = typename impl<Lx, Ix + 1, Ix + 2, Nx>::type; };

    // End of loop
    template <typename Lx, size_t J, size_t N>
    struct impl<Lx, N, J, N>
    { using type = Lx; };

    using type = typename impl<L, 0, 1, size<L>::value>::type;
};

/// Sort the types in type list **L** according to the template
/// template comparator **C**.
///
/// The comparator should be a template template parameter taking two
/// types that evaluates to true if the first type compares less
/// than the second type; otherwise, false.
///
/// \tparam L The type list to sort.
/// \tparam C The template template comparator
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// sort_t<list<mp_c,mp_b,mp_a>,integral_constant_less> // list<mp_a,mp_b,mp_c>
/// ```
/// \endverbatim
template<typename L, template <typename, typename> typename C>
using sort_t = typename sort<L,C>::type;

}; // mp

