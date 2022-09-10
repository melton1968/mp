// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/map_find.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, MapFind)
{
    using L = mp::list<mp::list<mp_a,mp_b>,mp::list<mp_c,mp_d>,mp::list<mp_e,mp_f>>;
    {
	using A = mp::map_find_t<mp_a,L>;
	using R = mp::list<mp_a,mp_b>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
