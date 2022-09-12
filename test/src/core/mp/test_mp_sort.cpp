// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/sort.h"
#include "core/mp/if.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Sort)
{
    {
	using L = mp::list<mp_b,mp_c,mp_e,mp_a,mp_d>;
	using A = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::sort_t<L,mp::integral_constant_less>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<mp_b,mp_c,mp_e,mp_a,mp_d>;
	using A = mp::list<mp_e,mp_d,mp_c,mp_b,mp_a>;
	using R = mp::sort_t<L,mp::integral_constant_more>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
