// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/subset.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(List, Subset)
{
    using L = mp::list<mp_a,mp_b,mp_c>;
    {
	using R = mp::is_subset_of_t<mp::list<mp_a>,L>;
	StaticAssertTypeEq<R,mp_true>();
    }
    {
	using R = mp::is_subset_of_t<mp::list<mp_d>,L>;
	StaticAssertTypeEq<R,mp_false>();
    }
    {
	using R = mp::is_subset_of_t<mp::list<mp_a,mp_b,mp_c>,L>;
	StaticAssertTypeEq<R,mp_true>();
    }
    {
	using R = mp::is_subset_of_t<mp::list<mp_c,mp_a,mp_b>,L>;
	StaticAssertTypeEq<R,mp_true>();
    }
    {
	using R = mp::is_subset_of_t<mp::list<mp_c,mp_a,mp_d,mp_b>,L>;
	StaticAssertTypeEq<R,mp_false>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
