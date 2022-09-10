// Copyright (C) 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/same.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

template<class T>
struct NeedsParameter
{};

TEST(MP, At)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    {
	// using R = mp::is_same_template_t<L,mp::list>;
	// StaticAssertTypeEq<R, std::true_type>();
	
	static constexpr auto value = mp::is_same_template_v<L,mp::list>;
	EXPECT_EQ(value, true);
    }
    {
	// using R = mp::is_same_template_t<L,std::tuple>;
	// StaticAssertTypeEq<R,std::false_type>();
	
	static constexpr auto value = mp::is_same_template_v<L,std::tuple>;
	EXPECT_EQ(value, false);
    }
    {
	// using R = mp::is_same_template_t<mp::list<>,NeedsParameter>;
	// StaticAssertTypeEq<R,std::false_type>();
	
	static constexpr auto value = mp::is_same_template_v<mp::list<>,NeedsParameter>;
	EXPECT_EQ(value, false);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
