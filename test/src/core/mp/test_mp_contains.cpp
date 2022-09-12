// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/contains.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Contains)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    {
	using R = mp::contains_t<mp_a,L>;
	StaticAssertTypeEq<R,mp_true>();
	ASSERT_EQ((mp::contains_v<mp_a,L>),true);
    }
    {
    	using R = mp::contains_t<mp_b,L>;
    	StaticAssertTypeEq<R,mp_true>();
    	ASSERT_EQ((mp::contains_v<mp_b,L>),true);
    }
    {
    	using R = mp::contains_t<mp_e,L>;
    	StaticAssertTypeEq<R,mp_true>();
    	ASSERT_EQ((mp::contains_v<mp_e,L>),true);
    }
    {
    	using R = mp::contains_t<mp_f,L>;
    	StaticAssertTypeEq<R,mp_false>();
    	ASSERT_EQ((mp::contains_v<mp_f,L>),false);
    }
}

TEST(MP, IsMember)
{
    {
	using R = mp::is_member_t<mp_a,mp_a,mp_b,mp_c,mp_d,mp_e>;
	StaticAssertTypeEq<R,mp_true>();
	ASSERT_EQ((mp::is_member_v<mp_a,mp_a,mp_b,mp_c,mp_d,mp_e>),true);
    }
    {
    	using R = mp::is_member_t<mp_b,mp_a,mp_b,mp_c,mp_d,mp_e>;
    	StaticAssertTypeEq<R,mp_true>();
    	ASSERT_EQ((mp::is_member_v<mp_b,mp_a,mp_b,mp_c,mp_d,mp_e>),true);
    }
    {
    	using R = mp::is_member_t<mp_e,mp_a,mp_b,mp_c,mp_d,mp_e>;
    	StaticAssertTypeEq<R,mp_true>();
    	ASSERT_EQ((mp::is_member_v<mp_e,mp_a,mp_b,mp_c,mp_d,mp_e>),true);
    }
    {
    	using R = mp::is_member_t<mp_f,mp_a,mp_b,mp_c,mp_d,mp_e>;
    	StaticAssertTypeEq<R,mp_false>();
    	ASSERT_EQ((mp::is_member_v<mp_f,mp_a,mp_b,mp_c,mp_d,mp_e>),false);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
