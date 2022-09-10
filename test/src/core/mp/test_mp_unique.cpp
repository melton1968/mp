// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/unique.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Unique)
{
    {
	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::unique_t<L>;
	StaticAssertTypeEq<R,L>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_a,mp_c,mp_e>;
	using R = mp::unique_t<L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<>;
	using R = mp::unique_t<L>;
	StaticAssertTypeEq<R,L>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
