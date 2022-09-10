// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/nth.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Nth)
{
    EXPECT_EQ(mp::nth<0>(0), 0);
    
    EXPECT_EQ(mp::nth<0>(0,1), 0);
    EXPECT_EQ(mp::nth<1>(0,1), 1);
    
    EXPECT_EQ(mp::nth<0>(0,1,2), 0);
    EXPECT_EQ(mp::nth<1>(0,1,2), 1);
    EXPECT_EQ(mp::nth<2>(0,1,2), 2);

    EXPECT_EQ(mp::nth<0>(0,1,2,3), 0);
    EXPECT_EQ(mp::nth<1>(0,1,2,3), 1);
    EXPECT_EQ(mp::nth<2>(0,1,2,3), 2);
    EXPECT_EQ(mp::nth<3>(0,1,2,3), 3);

    // EXPECT_EQ(mp::nth<0>(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,19,20), 0);
    // EXPECT_EQ(mp::nth<20>(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,19,20), 20);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
