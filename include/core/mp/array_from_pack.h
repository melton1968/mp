// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <array>

namespace core::mp {

template<class T, T... Ts>
consteval auto array_from_pack() {
    return std::array<T, sizeof...(Ts)>{Ts...};
}

}; // core::mp
