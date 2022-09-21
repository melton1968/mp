// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/cat.h"
#include "core/mp/unique.h"

namespace core::mp
{

/**
   @brief Union of the given lists
   @tparam Ls... The lists to combine
   @returns The union of the given lists
*/
/// Compute the union of the given type lists **Ls**.
///
/// This is a proper mathematical set union in that there are no duplicate
/// members in the resulting type list.
///
/// \tparam Ls The type lists to union.
template<class... Ls>
using union_t = unique_t<cat_t<Ls...>>;

}; // core::mp
