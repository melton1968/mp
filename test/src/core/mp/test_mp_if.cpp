// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/if.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, If)
{
    
    {
     	using R = mp::if_ct<0,mp_a,mp_b>;
     	StaticAssertTypeEq<R,mp_b>();
     }
    {
     	using R = mp::if_ct<1,mp_a,mp_b>;
     	StaticAssertTypeEq<R,mp_a>();
     }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
