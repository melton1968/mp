// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/intersect.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Intersect)
{
    using L1 = mp::list<mp_a,mp_b,mp_c>;
    using L2 = mp::list<mp_d,mp_e,mp_c>;

    {
	using A = mp::list<>;
	using R0 = mp::intersect_t<>;
	using R1 = mp::intersect_t<mp::list<>>;
	using R2 = mp::intersect_t<mp::list<>, L1>;
	using R3 = mp::intersect_t<mp::list<>, L1, L2>;
	StaticAssertTypeEq<R0,A>();
	StaticAssertTypeEq<R1,A>();
	StaticAssertTypeEq<R2,A>();
	StaticAssertTypeEq<R3,A>();
    }
    
    {
	using A = mp::list<>;
	using R = mp::intersect_t<mp::list<>, mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
	using A = mp::list<>;
     	using R = mp::intersect_t<L1, mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
	using A = mp::list<>;
	using R = mp::intersect_t<mp::list<>, L2>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
    	using R = mp::intersect_t<L1, L2>;
    	StaticAssertTypeEq<mp::size<R>,mp_1s>();
    	StaticAssertTypeEq<mp::contains_t<mp_c,R>,mp_true>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
