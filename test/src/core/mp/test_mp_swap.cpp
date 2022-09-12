// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/swap.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Swap)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    {
	using A = mp::list<mp_b,mp_a,mp_c,mp_d,mp_e>;
	using R = mp::swap_t<0,1,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<mp_e,mp_b,mp_c,mp_d,mp_a>;
	using R = mp::swap_t<0,4,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<mp_a,mp_b,mp_c,mp_e,mp_d>;
	using R = mp::swap_t<3,4,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<mp_a,mp_d,mp_c,mp_b,mp_e>;
	using R = mp::swap_t<1,3,L>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
