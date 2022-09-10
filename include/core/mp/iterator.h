// Copyright (C) 2021 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

namespace core::mp
{

template<class T, class U = void>
struct is_iterator : std::false_type
{ static constexpr bool value = false; };

template<class T>
struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::difference_type,
				  typename std::iterator_traits<T>::pointer,
				  typename std::iterator_traits<T>::reference,
				  typename std::iterator_traits<T>::value_type,
				  typename std::iterator_traits<T>::iterator_category>>
    : std::true_type { };

// Returns true iff `T` satisfies the type requirements of an iterator.
template<class T>
constexpr bool is_iterator_v = is_iterator<T>::value;

}; // mp
