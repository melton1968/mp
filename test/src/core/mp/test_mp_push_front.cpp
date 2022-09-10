// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/push_front.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, PushFront)
{
    using L = mp::list<mp_a,mp_b,mp_c>;
    {
	using R = mp::list<mp_d,mp_a,mp_b,mp_c>;
	using A = mp::push_front_t<mp_d,L>;
	StaticAssertTypeEq<A,R>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
