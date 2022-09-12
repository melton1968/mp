// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/transform.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

template<typename T>
using add_pointer = T*;

template<typename T>
using add_one = std::integral_constant<char,T::value+1>;

TEST(MP, Transform)
{
    {
	using L = mp::list<>;
	using A = mp::list<>;
	using R = mp::transform_t<add_pointer, L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<int, void, float>;
	using A = mp::list<int*, void*, float*>;
	using R = mp::transform_t<add_pointer, L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<mp_a,mp_b,mp_c>;
	using A = mp::list<mp_b,mp_c,mp_d>;
	using R = mp::transform_t<add_one, L>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
