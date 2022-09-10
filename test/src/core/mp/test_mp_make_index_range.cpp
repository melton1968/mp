// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/make_index_range.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, MakeIndexRange)
{
    {
	using A = std::integer_sequence<std::size_t>;
	using R = mp::make_index_range_t<mp_7u,mp_7u>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = std::integer_sequence<std::size_t,1>;
	using R = mp::make_index_range_t<mp_1u,mp_2u>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = std::integer_sequence<std::size_t,4,5,6,7>;
	using R = mp::make_index_range_t<mp_4u,mp_8u>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
