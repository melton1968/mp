// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <functional>

namespace core::mp {

// invoke_with_pack
//
template<std::size_t... Is, typename F>
auto invoke_with_pack(std::index_sequence<Is...>, F&& function)
{ return function(std::integral_constant<std::size_t, Is>{}...); }

}; // meta

