// Copyright (C) 2017, 2018, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/permutation.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Permutation)
{
    {
	using L1 = mp::list<mp_a,mp_b,mp_c>;
	using L2 = mp::list<mp_c,mp_a,mp_b>;
	using A = mp::list<mp_2s,mp_0s,mp_1s>;
	using R = mp::permutation_t<L1,L2>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L1 = mp::list<mp_a,mp_b,mp_c>;
	using L2 = mp::list<>;
	using A = mp::list<>;
	using R = mp::permutation_t<L1,L2>;
	StaticAssertTypeEq<R,A>();
    }
    // {
    // 	using L1 = mp::list<mp_a,mp_b,mp_c>;
    // 	using L2 = mp::list<mp_d>;
    // 	using A = mp::list<>;
    // 	using R = mp::permutation_t<L1,L2>;
    // 	cout << type(R{}) << endl;
    // 	StaticAssertTypeEq<R,A>();
    // }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
