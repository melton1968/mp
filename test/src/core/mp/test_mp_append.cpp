// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/append.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Append)
{
    using L = mp::list<mp_a,mp_b,mp_c>;
    {
	using M = mp::list<mp_d,mp_e>;
	using A = mp::append_t<L,M>;
	using R = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using M = mp::list<>;
	using A = mp::append_t<L,M>;
	using R = mp::list<mp_a,mp_b,mp_c>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using M = mp::list<>;
	using A = mp::append_t<M,L>;
	using R = mp::list<mp_a,mp_b,mp_c>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
