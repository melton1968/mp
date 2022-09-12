// Copyright (C) 2017, 2019, 2020, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/enable_if.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, EnableIfAll)
{
    EXPECT_TRUE((mp::enable_if_all_v<int>));
    EXPECT_TRUE((mp::enable_if_all_v<int,int>));
    EXPECT_TRUE((mp::enable_if_all_v<int,int,int>));

    StaticAssertTypeEq<void, mp::enable_if_all_t<int>>();
    StaticAssertTypeEq<void, mp::enable_if_all_t<int,int>>();
    StaticAssertTypeEq<void, mp::enable_if_all_t<int,int,int>>();
    
    EXPECT_FALSE((mp::enable_if_all_v<int,float>));
    EXPECT_FALSE((mp::enable_if_all_v<int,int,float>));
    EXPECT_FALSE((mp::enable_if_all_v<int,float,int>));
}

TEST(MP, EnableIfAny)
{
    EXPECT_TRUE((mp::enable_if_any_v<int,int>));
    EXPECT_TRUE((mp::enable_if_any_v<int,int,int>));
    EXPECT_TRUE((mp::enable_if_any_v<int,int,float>));
    EXPECT_TRUE((mp::enable_if_any_v<int,float,int>));

    StaticAssertTypeEq<void, mp::enable_if_any_t<int,int>>();
    StaticAssertTypeEq<void, mp::enable_if_any_t<int,int,int>>();
    StaticAssertTypeEq<void, mp::enable_if_any_t<int,float,int>>();
    StaticAssertTypeEq<void, mp::enable_if_any_t<int,int,float>>();
    
    EXPECT_FALSE((mp::enable_if_any_v<int>));
    EXPECT_FALSE((mp::enable_if_any_v<int,float>));
    EXPECT_FALSE((mp::enable_if_any_v<int,float,char>));
    EXPECT_FALSE((mp::enable_if_any_v<int,float,char,double>));
}

TEST(MP, EnableIfNone)
{
    EXPECT_TRUE((mp::enable_if_none_v<int>));
    EXPECT_TRUE((mp::enable_if_none_v<int,float>));
    EXPECT_TRUE((mp::enable_if_none_v<int,float,char>));
    EXPECT_TRUE((mp::enable_if_none_v<int,float,char,double>));

    StaticAssertTypeEq<void, mp::enable_if_none_t<int>>();
    StaticAssertTypeEq<void, mp::enable_if_none_t<int,float>>();
    StaticAssertTypeEq<void, mp::enable_if_none_t<int,float,char>>();
    
    EXPECT_FALSE((mp::enable_if_none_v<int,int>));
    EXPECT_FALSE((mp::enable_if_none_v<int,int,int>));
    EXPECT_FALSE((mp::enable_if_none_v<int,int,float>));
    EXPECT_FALSE((mp::enable_if_none_v<int,float,int>));
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
