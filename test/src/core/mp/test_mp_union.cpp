// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/union.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Union)
{
    using L1 = mp::list<mp_a,mp_b,mp_c>;
    using L2 = mp::list<mp_d,mp_e,mp_c>;
    using L3 = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e,mp_g>;

    {
	using A = mp::list<>;
	using R = mp::union_t<>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
	using A = mp::list<>;
	using R = mp::union_t<mp::list<>, mp::list<>, mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
	using A = L1;
	using R = mp::union_t<mp::list<>, L1, mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
	using A = L2;
	using R = mp::union_t<L2, mp::list<>, mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    
    {
	using R = mp::union_t<L1,L2,L3>;
	StaticAssertTypeEq<mp::size<R>,mp_6s>();
	StaticAssertTypeEq<mp::contains_t<mp_a,R>,mp_true>();
	StaticAssertTypeEq<mp::contains_t<mp_b,R>,mp_true>();
	StaticAssertTypeEq<mp::contains_t<mp_c,R>,mp_true>();
	StaticAssertTypeEq<mp::contains_t<mp_d,R>,mp_true>();
	StaticAssertTypeEq<mp::contains_t<mp_e,R>,mp_true>();
	StaticAssertTypeEq<mp::contains_t<mp_g,R>,mp_true>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
