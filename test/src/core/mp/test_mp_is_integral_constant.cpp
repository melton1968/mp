// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/list.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, IsIntegralConstant)
{
    {
	using L = mp_a;
	using A = mp_true;
	using R = mp::is_integral_constant_t<L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = int;
	using A = mp_false;
	using R = mp::is_integral_constant_t<L>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
