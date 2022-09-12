// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/subtract.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Subtract)
{
    using L1 = mp::list<mp_a,mp_b,mp_c>;
    using L2 = mp::list<mp_d,mp_e,mp_c>;
    
    {
	using A = mp::list<>;
	using R = mp::subtract_t<mp::list<>,mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = L1;
     	using R = mp::subtract_t<L1,mp::list<>>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using A = mp::list<>;
	using R = mp::subtract_t<mp::list<>,L2>;
	StaticAssertTypeEq<R,A>();
    }
    {
    	using R = mp::subtract_t<L1,L2>;
    	StaticAssertTypeEq<mp::size<R>,mp_2s>();
    	StaticAssertTypeEq<mp::contains_t<mp_a,R>,mp_true>();
    	StaticAssertTypeEq<mp::contains_t<mp_b,R>,mp_true>();
    }
    {
    	using R = mp::subtract_t<L2,L1>;
    	StaticAssertTypeEq<mp::size<R>,mp_2s>();
    	StaticAssertTypeEq<mp::contains_t<mp_d,R>,mp_true>();
    	StaticAssertTypeEq<mp::contains_t<mp_e,R>,mp_true>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
