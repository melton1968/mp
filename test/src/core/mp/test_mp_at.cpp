// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/at.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, At)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    {
	using R = mp::at_t<mp_0u,L>;
	StaticAssertTypeEq<R,mp_a>();
    }
    {
	using R = mp::at_t<mp_1u,L>;
	StaticAssertTypeEq<R,mp_b>();
    }
    {
	using R = mp::at_t<mp_4u,L>;
	StaticAssertTypeEq<R,mp_e>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
