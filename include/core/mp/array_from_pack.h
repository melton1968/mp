// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/array.h"

namespace core::mp {

template<class T, size_t N, std::array<T, N> M, T... Ts>
struct array_from_pack_impl;

template<class T, size_t N, std::array<T, N> M>
struct array_from_pack_impl<T, N, M> {
    static constexpr auto value = M;
};

template<class T, size_t N, std::array<T, N> M, T Elem, T... Ts>
struct array_from_pack_impl<T, N, M, Elem, Ts...> {
    static constexpr auto value = array_from_pack_impl<T, N+1, array_append(M, Elem), Ts...>::value;
};

template<class T, T... Ts>
consteval auto array_from_pack() {
    return array_from_pack_impl<T, 0, std::array<T, 0>{}, Ts...>::value;
}

}; // core::mp
