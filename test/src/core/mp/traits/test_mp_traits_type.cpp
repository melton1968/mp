// Copyright (C) 2017, 2019, 2022, 2023 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/traits/type.h"

using namespace core;
using namespace std::string_literals;

TEST(MP, TraitsType)
{
    EXPECT_EQ(mp::type_traits<std::int8_t>::name, "signed char"s);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
