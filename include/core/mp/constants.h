// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <type_traits>
#include "core/pp/map.h"

namespace core::mp
{

// integral constants
//

/**
   @brief Type alias for creating integral constants of type `bool`
   @tparam B non-type parameter of type `bool`
   @returns The bool integral constant for the value of B
*/
template<bool B>
using _bool = std::integral_constant<bool,B>;

/**
   @brief The false integral constant.
*/
using _false = _bool<false>;

/**
   @brief The true integral constant.
*/
using _true = _bool<true>;

// size_t, natural, integer, char
//
/**
   @brief Type alias for creating integral constants of type `size_t`
   @tparam N non-type parameter of type `size_t`
   @returns The `size_t` integral constant for the given value of N
*/
template<size_t N>
using _size_t = std::integral_constant<std::size_t,N>;

/**
   @brief Type alias for creating integral constants of type `uint`
   @tparam N non-type parameter of type `uint`
   @returns The `uint` integral constant for the given value of N
*/
template<size_t N>
using _natural = std::integral_constant<uint,N>;

/**
   @brief Type alias for creating integral constants of type `int`
   @tparam N non-type parameter of type `int`
   @returns The `int` integral constant for the given value of N
*/
template<size_t N>
using _integer = std::integral_constant<int,N>;

/**
   @brief Type alias for creating integral constants of type `char`
   @tparam C non-type parameter of type `char`
   @returns The `char` integral constant for the given value of C
*/
template<char C>
using _char = std::integral_constant<char,C>;

// matching 
//
template<typename T>
struct is_integral_constant
{ using type = _false; };

template<typename T,T V>
struct is_integral_constant<std::integral_constant<T,V>>
{ using type = _true; };

template<typename T>
using is_integral_constant_t = typename is_integral_constant<T>::type;

template<typename T>
inline constexpr bool is_integral_constant_v = is_integral_constant_t<T>::value;

// comparision
//
template<class T, class U>
using integral_constant_less = std::conditional_t<(T::value < U::value),_true,_false>;

template<class T, class U>
using integral_constant_more = std::conditional_t<(T::value > U::value),_true,_false>;

// pre-named natural, integer, char constants
//

#define MP_INTEGRAL(N)		    \
    using _ ## N ##s = _size_t<N>;  \
    using _ ## N ##u = _natural<N>; \
    using _ ## N = _integer<N>;
CORE_PP_EVAL_MAP(MP_INTEGRAL, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);
#undef MP_INTEGRAL

#define Q(X) ((#X)[0])
#define MP_CHAR(C) using _ ## C = _char<Q(C)>;
CORE_PP_EVAL_MAP(MP_CHAR, a, b, c, d, e, f, g, h, i, j, k, l, m,
		 n, o, p, q, r, s, t, u, v, w, x, y, z, _);
#undef MP_CHAR
#undef Q

}; // namespace

using mp_false = core::mp::_false;
using mp_true = core::mp::_true;

#define MP_INTEGRAL(N)				\
    using mp_ ## N ##s = core::mp::_ ## N ##s;	\
    using mp_ ## N ##u = core::mp::_ ## N ##u;	\
    using mp_ ## N = core::mp::_ ## N;
CORE_PP_EVAL_MAP(MP_INTEGRAL, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);
#undef MP_INTEGRAL

#define Q(X) ((#X)[0])
#define MP_CHAR(C) using mp_ ## C = core::mp::_ ## C;
CORE_PP_EVAL_MAP(MP_CHAR, a, b, c, d, e, f, g, h, i, j, k, l, m,
		 n, o, p, q, r, s, t, u, v, w, x, y, z, _);
#undef MP_CHAR
#undef Q

