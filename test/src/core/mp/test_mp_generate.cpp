// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/generate.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(List, Generate)
{
    {
	using A = mp::list<>;
	using R = mp::generate_t<size_t,0>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<size_t>;
	using R = mp::generate_t<size_t,1>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<size_t,size_t>;
	using R = mp::generate_t<size_t,2>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<size_t,size_t,size_t,size_t,size_t,size_t,size_t,size_t>;
	using R = mp::generate_t<size_t,8>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
