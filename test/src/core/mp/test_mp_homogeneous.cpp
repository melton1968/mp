// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/homogeneous.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, HomogenousTrue)
{
    {
	using L = mp::list<mp_a,mp_a,mp_a>;
	EXPECT_EQ(mp::homogeneous_v<L>, true);
    }
}

TEST(MP, HomogenousFalse)
{
    {
	using L = mp::list<mp_a,mp_b,mp_a>;
	EXPECT_EQ(mp::homogeneous_v<L>, false);
    }
}

TEST(MP, HomogenousEmpty)
{
    {
	using L = mp::list<>;
	EXPECT_EQ(mp::homogeneous_v<L>, true);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
